#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
int pfds[2];
pipe(pfds);
if (!fork())//parent process
{
close(1);//close standard output
dup(pfds[1]);//duplicate write file descriptor
close(pfds[0]);//close the read end of file
execlp("who", "who", NULL);
}

else//child process
{
close(0);//close standard input
dup(pfds[0]);
close(pfds[1]);
execlp("wc", "wc","-l", NULL);
}
}

