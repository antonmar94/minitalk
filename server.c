/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:33:27 by antonmar          #+#    #+#             */
/*   Updated: 2021/11/12 16:48:26 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

void	MySigusHandler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;

	(void)context;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		i = 0;
	}
	else
		c <<= 1;
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.__sigaction_u.__sa_sigaction = &MySigusHandler;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
	{
		usleep(1);
	}
	exit (0);
}
