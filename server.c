/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:53:26 by procha-r          #+#    #+#             */
/*   Updated: 2025/02/27 12:00:58 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	reset_state(t_state *state)
{
	state->bit_count = 0;
	state->current_char = 0;
	state->client_pid = 0;
}

static void	print_char(int current)
{
	char	c;

	c = (char)current;
	if (c == '\0')
		write(1, "\n", 1);
	else
		write(1, &c, 1);
}

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static t_state	state = {0, 0, 0};

	(void)context;
	if (state.client_pid == 0)
		state.client_pid = info->si_pid;
	if (sig == SIGUSR1)
		state.current_char = (state.current_char << 1);
	else if (sig == SIGUSR2)
		state.current_char = (state.current_char << 1) | 1;
	state.bit_count++;
	if (state.bit_count == 8)
	{
		if ((char)state.current_char == '\0')
		{
			print_char(state.current_char);
			kill(state.client_pid, SIGUSR1);
			reset_state(&state);
			return ;
		}
		print_char(state.current_char);
		state.bit_count = 0;
		state.current_char = 0;
	}
	usleep(50);
	kill(state.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
