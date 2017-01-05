//Include header files
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//Main function
int main() {
	pid_t pid;
	//Fork a child process
	pid = fork();

	//Error has occurred
	if(pid < 0) {
		fprintf(stderr, "Fork failed");
		exit(-1);
	}
	//Child process has been created
	else if(pid == 0) {
		execlp("/bin/ls","ls",NULL);
	}
	//Parent process
	//Parent will wait for child to complete
	else {
		wait(NULL);
		printf("\nChild complete\n");
		exit(0);
	}

	return 0;
}