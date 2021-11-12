/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:33:34 by antonmar          #+#    #+#             */
/*   Updated: 2021/11/12 17:36:58 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	ft_handler(int sig)
{
	usleep(100);
	if (sig == SIGUSR1)
		ft_putchar_fd('|', 1);
}

void	signal_sender(int pid, char *text, struct sigaction action)
{
	int	i;

	while (*text)
	{
		i = 8;
		while (--i >= 0)
		{
			usleep(100);
			if (*text >> i & 1)
			{
				kill(pid, SIGUSR1);
				sigaction(SIGUSR1, &action, 0);
			}
			else
			{
				kill(pid, SIGUSR2);
				sigaction(SIGUSR1, &action, 0);
			}
			usleep(100);
		}
		text++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;
	char				*text;
	struct sigaction	action;

	i = 0;
	action.__sigaction_u.__sa_handler = &ft_handler;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		printf("Error");
		exit (-1);
	}
	text = argv[2];
	signal_sender(pid, text, action);
	exit (0);
}
