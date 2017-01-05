#include <stdio.h>

#include <sys/types.h>

int main() {

	pid_t pid = fork();

	if(pid == 0) {
		printf("Entering Child process now ...\n");
	
		int n;
		scanf("%d",&n);
		int fib[n];
		fib[0] = 0;
		fib[1] = 1;

		for(int i = 2; i < n; i ++) {
			fib[i] = fib[i-1] + fib[i-2];
		}

		for(int i = 0; i < n; i ++) {
			printf("%d ",fib[i]);
		}
		printf("\n");

		printf("Exiting Child process now ...\n");
	}

	else if(pid > 0) {
		printf("Entering Parent process now ...\n");
		sleep(10);
		printf("Exiting Parent process now ...\n");
	}


}
