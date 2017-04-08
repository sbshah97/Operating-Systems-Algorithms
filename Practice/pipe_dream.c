#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int pfds[2];

	pipe(pfds);

	if(!fork()) {
		close(1);
		dup(pfds[1]);
		close(pfds[0]);
		execlp("ls", "ls", NULL);
	}
	else {
		close(0);
		dup(pfds[0]);
		close(pfds[1]);
		execlp("wc", "wc", "-l", NULL);
	}

	return 0;
}