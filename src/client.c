/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:35:01 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/16 16:24:04 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	int		len;
	int		i;
	int		two_power;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	i = 0;
	while (i < len)
	{
		two_power = 1;
		while (two_power <= 128)
		{
			if (argv[2][i] & two_power)
				kill (pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			two_power *= 2;
			usleep(100);
		}
		i++;
	}	
}
