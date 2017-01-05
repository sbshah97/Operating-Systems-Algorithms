#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {

	pid_t pid = fork();

	if(pid == 0) {
		printf("Entering Child process now ...\n");
		
		printf("Exiting Child process now ...\n");
		exit(0);
	} 

	else if (pid > 0) {
		printf("Entering Parent process now ...\n");
		sleep(5);
		printf("Exiting Parent process now ...\n");
		
	}

	return 0;
}