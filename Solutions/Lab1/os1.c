#include<stdio.h>
#include<sys/types.h>
int main()
{

pid_t pid=fork();
if(pid==0)
{
printf("Child Process created\n");
printf("Creating fibonacci series\nEnter n ");
int n;
scanf("%d",&n);
if(n==1)
printf("1\n");
else if(n==2)
printf("1\t1\n");
else
{
printf("1\t1\t");
int f1=1,f2=1;
int i,f3;
for(i=3;i<=n;i++)
{
f3=f1+f2;
printf("%d\t",f3);
f1=f2;
f2=f3;
}
printf("\n");
}
}
else{
wait();
printf("Parent process created\n");}
return 0;
}
