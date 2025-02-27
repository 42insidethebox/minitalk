/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: procha-r <procha-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:59:37 by procha-r          #+#    #+#             */
/*   Updated: 2025/02/25 23:30:30 by procha-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

/*
** handle_ack: Sets the acknowledgment flag upon receiving SIGUSR1.
*/
void	handle_ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

/*
** send_bit: Sends a bit to the server and waits for acknowledgment.
*/
void	send_bit(pid_t server_pid, int bit)
{
	g_ack_received = 0;
	if (bit == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	while (!g_ack_received)
		usleep(50);
}

/*
** send_message: Translates a string into bits and sends them.
** Sends 8 bits per character, then sends a null terminator (8 zero bits).
*/
void	send_message(pid_t server_pid, const char *message)
{
	int		i;
	char	c;

	while (*message)
	{
		c = *message;
		i = 7;
		while (i >= 0)
		{
			send_bit(server_pid, (c >> i) & 1);
			i--;
		}
		message++;
	}
	i = 7;
	while (i >= 0)
	{
		send_bit(server_pid, 0);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	const char			*message;
	struct sigaction	sa;

	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = (pid_t)atoi(argv[1]);
	message = argv[2];
	sa.sa_handler = handle_ack;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	send_message(server_pid, message);
	return (0);
}
