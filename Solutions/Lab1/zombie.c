#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{

pid_t pid=fork();
if(pid==0)
{
printf("Child Process created\n");
printf("Exiting\n");
exit(0);
}
else{
sleep(15);
printf("Parent process\n");

}
return 0;
}
