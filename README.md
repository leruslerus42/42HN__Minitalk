# Minitalk

## GENERAL
Minitalk is a program that allows a remote server and a client to communicate between themselves. 
The programm is so structured that the client should be able to send a string to the server using only UNIX signals.

## LAUNCH
In order to run Minitalk, you can:
- Use the instruction make to create our objectcode from the sourcecode.
- Launch the executable ./server to launch it and so that you get the PID (Process Identification Number)from the server.
- Launch the executable ./client giving as first parameter the PID of the Server and as second parameter the string you would like to send to the server.
- The string tipped on the client will be automatically printed on the server :-)


## NORMINETTE

As all other C projects at the 42 school, the code has to written in accordance with the norm:
- only 25 lines per function
- only 5 functions per file

## RESULT 

<img width="846" alt="Screenshot 2022-11-01 at 07 12 31" src="https://user-images.githubusercontent.com/85942176/199170406-7b00bd04-de11-4ef0-9be8-80f601d8bd72.png">
