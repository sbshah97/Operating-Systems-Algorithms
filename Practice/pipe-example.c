#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main() {
	int pfds[2];
	char buf[30];

	pipe(pfds);

	if(!fork()) {
		printf("Child reading to pipe\n");
		read(pfds[0], buf, 6);
		printf("%s\n",buf );
		printf("Child finished reading\n");
	}
	else {
		printf("Parent writing from pipe\n");
		write(pfds[1], "Hello", 6);
		printf("Parent finished writing\n");
	}
}