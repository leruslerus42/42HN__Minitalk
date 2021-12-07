/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:35:01 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/07 03:03:46 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
/*void client (int pid, char *s)
{
	//send s to server
	
}

int main(int argc, char **argv)
{
	int pid;
	char *s;

	printf("Process ID: %i\n", pid);
	s = ft_atoi(argv[1]);
}*/
/*
int main(int argc, char **argv)
{
	//pid_t pid = getpid;
	printf("?");
	pid_t pid;
	pid = ft_atoi(argv[1]);

	FILE *fp = fopen("foo", "w");
	setbuf(fp, NULL);

	kill(pid,SIGUSR2);
	

	char c;
	while (scanf("%c", &c) == 1)
	{
		if (c == '\n')
			continue;
		fprintf(fp, "%c", c);
		kill(pid, SIGUSR1);
	}

	unlink("foo");
	kill(pid, SIGTERM);
	
	return (0);
}*/

/*
The idea is to first calculate the length of the string as n and then run a loop n times. 
In each iteration store ASCII value of character in variable val and then convert it 
into binary number and store result in array finally print the array in reverse order.
*/



/*int	encoder(int pid, int c)
{
//	int num;
//	int len;
	int i;
//	char	**array;
	
	i = 1;
	//array = malloc (len + 1);
	//if (!array)
	//	return (0);
	
	
	
	while (i <= 128)
	{*/
		/*if (c % 2 == 0)
			kill(pid, SIGUSR2);
			//printf("0");
		else
			kill(pid, SIGUSR1);//send 1
			//printf("1");
		c = c / 2;
		//after store in array 
		i *= 2;//bitshifting same as *2*/
	/*	if (c & i)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);//send 0
		i *= 2;
		
		usleep(100);
	}
	//send array in rev order to server

	return (0);
}*/

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
		//encoder(pid, argv[2][i]);
		while (two_power <= 128)
		{
			if (argv[2][i] & two_power)
				kill (pi, SIGUSR2);
			else
				kill (pi, SIGUSR1);
			two_power *= 2;
			usleep(100);
		}
		i++;
	}	
}
