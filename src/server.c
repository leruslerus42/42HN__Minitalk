/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:35:09 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/16 16:25:05 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	decode(int s)
{
	static int	c = 0;
	static int	count = 1;

	if (s == SIGUSR2)
		c += count;
	count *= 2;
	if (count > 128)
	{
		count = 1;
		write(1, &c, 1);
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %i\n", pid);
	while (TRUE)
	{
		signal(SIGUSR2, decode);
		signal(SIGUSR1, decode);
		pause();
	}
	return (0);
}
