/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:53:26 by procha-r          #+#    #+#             */
/*   Updated: 2025/03/22 21:01:53 by pedroribeir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	reset_state(t_state *state)
{
	state->bit_count = 0;
	state->current_char = 0;
}

static void	print_received_char(int current)
{
	char	c;

	c = (char)current;
	if (c == '\0')
		write(1, "\n", 1);
	else
		write(1, &c, 1);
}

static int	handle_complete_char(t_state *state)
{
	print_received_char(state->current_char);
	if ((char)state->current_char == '\0')
	{
		reset_state(state);
		return (1);
	}
	state->bit_count = 0;
	state->current_char = 0;
	return (0);
}

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static t_state	state = {0, 0, 0};
	int				is_null;

	(void)context;
	if (state.client_pid == 0)
		state.client_pid = info->si_pid;
	if (info->si_pid != state.client_pid)
		return ;
	if (sig == SIGUSR1)
		state.current_char <<= 1;
	else if (sig == SIGUSR2)
		state.current_char = (state.current_char << 1) | 1;
	state.bit_count++;
	if (state.bit_count == 8)
	{
		is_null = handle_complete_char(&state);
		usleep(100);
		if (kill(state.client_pid, SIGUSR1) == -1)
			ft_printf("ACK FAIL: couldn't send to PID %d\n", state.client_pid);
		if (is_null)
			state.client_pid = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
