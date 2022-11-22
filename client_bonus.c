/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:10:37 by akouame           #+#    #+#             */
/*   Updated: 2022/05/20 19:11:36 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	ft_check(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("Message recived ^_^\n", 1);
}

void	ft_sent(int pid, char *msg)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= ft_strlen(msg))
	{
		j = 0;
		while (j < 8)
		{
			if (((msg[i] << j) & 128) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || argv[2] == NULL || ft_atoi(argv[1]) <= 0)
		return (0);
	signal(SIGUSR1, ft_check);
	ft_sent(ft_atoi(argv[1]), argv[2]);
	return (0);
}
