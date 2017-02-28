#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
int n,a,b,c,pid;
int fibo[100];
int pfd[2];
if(pipe(pfd)==-1)
{
	printf("Error\n");
	exit(0);
}
pid=fork();
if(pid>0) //parent
{
printf("\nParent Process");\
printf("\nFibonacci Series");
printf("\nEnter the limit for the series:");
scanf("%d",&n);
close(pfd[0]);
write(pfd[1],&n,sizeof(n));
close(pfd[1]);
exit(0);
}
else //child
{
close(pfd[1]);
read(pfd[0],&n,sizeof(n));
printf("\nChild Process");
a=0;
b=1;
close(pfd[0]);
printf("\nFibonacci Series is:");
printf("\n%d\n%d",a,b);
while(n>2)
{
c=a+b;
printf("\n%d",c);
a=b;
b=c;
n--;
}
}
printf("\n");
return 0;
}//main
