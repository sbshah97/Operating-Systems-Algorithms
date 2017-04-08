#include <bits/stdc++.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
int main() {
	int pid = fork();

	//Parent process
	if(pid > 0) {
		printf("In Parent Process\n");
	}

	Child Process
	else if(pid == 0) {
		sleep(10);
		printf("In Child process\n");
	}
	return 0;	
}