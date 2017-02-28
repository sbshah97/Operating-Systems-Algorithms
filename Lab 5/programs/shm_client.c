#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char **argv) {
	int shmid;
	char *shm;
	key_t key;

	if(argc < 2) {
		fprintf(stderr, "Usage:%s key\n",argv[0]);
		exit(2);
	}
	key = atoi(argv[1]);

	printf("Trying shared memory:%d\n",key);
	shmid = shmget(key, 1000, SHM_R | SHM_W);
	if(shmid < 0) {
		perror("shmget");
		shmid= key;
	}
	else 
		printf("Shared memory: %d\n",shmid);

	shm = (char *)shmat(shmid, /*addr*/0, /*flag*/0);
	if(shm == (char *)-1) {
		perror("shmat");
		exit(1);
	}
	printf("Shared Memory: %p\n",shm);

	if(shm != 0){
		printf("Shared memory content:%s\n",shm);
	}

	sleep(500);
	return 0;
}