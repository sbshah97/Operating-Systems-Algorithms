#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{

int shmid;

int *shm;

key_t key=8765; //= IPC_PRIVATE;

int flag; //= SHM_R | SHM_W;

/*if (argc >= 2) {

key = atoi(argv[1]);

}*/

shmid = shmget(key, 1000, IPC_CREAT | 0666);

printf("shared memory for key %d: %d\n", key, shmid);

if (shmid < 0) {
printf("\nError in getting shared memory");
//perror("shmget");

printf("\nTry to create this segment\n");

shmid = shmget(key, 1000, IPC_CREAT | 0666);

if (shmid < 0) {
printf("Error again\n");
//perror("shmget | IPC_CREAT");
exit(1);
}

}

shm = (int *)shmat(shmid, NULL, /*flag*/0);

if ((int)shm ==-1) {

//perror("shmat");
printf("Error in attaching\n");
exit(1);

}

sprintf(shm, "hello world\n");

printf("shared memory content: %s\n", shm);

sleep(10);

return 0;

} /* main */
