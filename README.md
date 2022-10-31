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
<img width="1174" alt="Screenshot 2022-10-31 at 04 57 00" src="https://user-images.githubusercontent.com/85942176/198928004-04299712-c2fc-4dfe-9100-3cdada68f094.png">
