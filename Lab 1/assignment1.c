#include <stdio.h>

#include <sys/types.h>

int main() {

	pid_t pid = fork();

	if(pid == 0) {
		printf("Child process created\n");
		int n;
		n = 10;
		int fibo[n];

		fibo[0] = 0;
		fibo[1] = 1;

		for(int i = 2; i <= n; i ++)
			fibo[i] = fibo[i-1] + fibo[i-2];

		printf("The %dth fibonacci number is %d\n",n, fibo[10]);
	}
	else 
		printf("Parent process created\n");

	return 0;
}
