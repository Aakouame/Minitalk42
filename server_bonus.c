/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:11:45 by akouame           #+#    #+#             */
/*   Updated: 2022/05/20 19:13:15 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	ft_handl(int sig, siginfo_t *info, void *none)
{
	static unsigned char	c;
	static int				i;
	static pid_t			c_pid;
	char					z;

	(void)none;
	z = 0b00000000;
	if (!c_pid || c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
		c = 0b00000000;
		i = 0;
	}
	if (sig == SIGUSR1)
		c = c | (z & 128 >> i++);
	else if (sig == SIGUSR2)
		c = c | (z | 128 >> i++);
	if (i == 8)
	{
		if (!c)
			kill(c_pid, SIGUSR1);
		write (1, &c, 1);
		i = 0;
		c = 0b00000000;
	}
}

int	main(void)
{
	struct sigaction	ko;
	pid_t				pid;

	pid = getpid();
	if (pid < 0)
		return (0);
	ko.sa_flags = SA_SIGINFO;
	ko.sa_sigaction = &ft_handl;
	ft_putstr_fd("Votre pid est : ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &ko, NULL);
	sigaction(SIGUSR2, &ko, NULL);
	while (1)
		pause();
	return (0);
}
