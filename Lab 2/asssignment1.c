#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
	int pid,pfd[2],n,a,b,c;

	if(pipe(pfd)==-1) {
		printf("Error in pipe connection\n");
		exit(1);
	}
	pid=fork();

	if(pid>0) {
		printf("Parent Process\n");
		printf("Fibonacci Series\n");
		printf("Enter the limit for the series:\n");
		scanf("%d",&n);
		close(pfd[0]);
		write(pfd[1],&n,sizeof(n));
		close(pfd[1]);
		exit(0);
	}
	else {
		close(pfd[1]);
		read(pfd[0],&n,sizeof(n));
		printf("Child Process\n");
		a=0;
		b=1;
		close(pfd[0]);
		printf("Fibonacci Series is:\n");
		printf("%d\n%d\n",a,b);
		while(n>2) {
			c=a+b;
			printf("%d\n",c);
			a=b;
			b=c;
			n--;
		}
	}
}