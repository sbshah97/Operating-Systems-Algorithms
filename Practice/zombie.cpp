#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	pid_t child_pid;

	//Create a child
	child_pid = fork();

	//Parent process
	if(child_pid > 0) {
		sleep(60);
	}
	//Child Process
	else {
		exit(0);
	}

	return 0;
}