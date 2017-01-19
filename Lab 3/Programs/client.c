#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#include <fentl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	char fname[50], buffer[1025];
	int req, res, n;

	req = open("req.fifo", O_WRONLY);
	res = open("res.fifo", O_RDONLY);

	if(req < 0 || res < 0) {
		printf("Please start the server");
		exit(-1);
	}

	printf("Enter the filename to request\n");
	scanf("%s",fname);

	write(req, fname,sizeof(fname));

	printf("Recieved response\n");

	while((n = read(res, buffer, sizeof(buffer))) > 0) {
		write(1, buffer, n);
	}

	close(req);
	close(res);

	return 0;
}