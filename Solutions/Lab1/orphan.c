#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{

pid_t pid=fork();
if(pid==0)
{
printf("Child process sleeping\n");
sleep(15);
printf("Child process terminating\n");
}
else{
printf("Parent process exiting\n");
exit(0);

}
return 0;
}
