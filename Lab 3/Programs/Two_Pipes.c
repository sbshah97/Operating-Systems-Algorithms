#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {

	int pipe1fd[2],pipe2fd[2],n,file;
	char buffer[1024],fname[50];
	
	if(pipe(pipe1fd)==-1 || pipe(pipe2fd)==-1 ) {
		printf("\nError in pipe connection\n");
		exit(1);
	}
	
	if(!fork()) {
		close(pipe1fd[1]);
		printf("Enter filename to request:\n");
		scanf("%s", fname);
		write(pipe2fd[1], fname, sizeof(fname));
		printf("Received response\n");
		while((n = read(pipe1fd[0], buffer, sizeof(buffer)))>0) {
			write(1, buffer, n);
		}
		close(pipe2fd[0]);
	}
	
	else {
		close(pipe1fd[0]);
		printf("Waiting for request...\n");
		read(pipe2fd[0], fname, sizeof(fname));
		printf("Received request for %s\n", fname);
		file = open(fname,O_RDONLY);
		if (file < 0)
			write(pipe1fd[1], "File not found\n", 15);
		else {
			while((n = read(file, buffer, sizeof(buffer))) > 0) 
				write(pipe1fd[1], buffer, n);
		}
		close(pipe2fd[1]);
		exit(0);
	}

}