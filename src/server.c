/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrajaobe <rrajaobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:35:09 by rrajaobe          #+#    #+#             */
/*   Updated: 2021/12/07 02:18:17 by rrajaobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
/*
int main(void)
{
	int pid;
	char *s;

	pid = getpid();
	printf("%i", pid);
	client(pid, s);
	return(0);
}*/


void decode(int s)
{
	static int	c = 0;
	static int count = 1;

	
	if (s == SIGUSR2)
	{
		c += count;
		//18 volte... quindi sigusr1=32-18=14
	}
	count *= 2;
	//hier 32 volte
	//printf("c: %i, count: %i\n", c, count);
	//write(1, &c, 1);
	//printf("%c", c);
	if (count > 128)
	{
		count = 1;
		write(1, &c, 1);
		c = 0;
	}
}


// VEDI: https://stackoverflow.com/questions/6168636/how-to-trigger-sigusr1-and-sigusr2
// non tanto rilevante pero ok : https://stackoverflow.com/questions/29084318/playing-around-with-signals
int main()
{
	int pid;
	
	pid = getpid();
	ft_printf("PID: %i\n", pid);
	while(2 == 2)
	{
		signal(SIGUSR2, decode);
		signal(SIGUSR1, decode);

		
		//by hh string, loop executed 17 volte (not 16)
		pause();
	}
	
	return (0);
}

/*
CLIENT SEND A SIGNAL AS BINAR TO SERVER ENCODED IT AND PRINT IT.
HOW WORK A SIGNAL?
*/
















/*
You must create a communication program in the form of a client and server.
• The server must be launched first, and after being launched it must display its PID.

• The client will take as parameters: The server PID + The string that should be sent.

• The client must communicate the string passed as a parameter to the server. 
Once the string has been received, the server must display it.

• Communication between your programs should ONLY be done using UNIX signals.

• Your server should be able to receive strings from several clients in a row, without needing to be restarted.
• You can only use the two signals SIGUSR1 and SIGUSR2.

*/
/*
◦
write
◦
ft_printf and any equivalent YOU coded
◦
signal
◦
sigemptyset - create empty sigset
◦
sigaddset - add a signal to the set
◦
sigaction
◦
kill
◦
getpid
◦
malloc
◦
free
◦
pause
◦
sleep
◦
usleep
◦
exit
*/