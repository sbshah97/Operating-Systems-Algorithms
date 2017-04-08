#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
	int n;
	// scanf("%d",&n);
	while((n = read(0, &n, sizeof(n))) != 0){
		write(1, &n, sizeof(n));
		printf("End program\n");
	}
	return 0;
}