#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include <ctype.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>

sem_t chopstick[100];

int n;

void *thread_func(int no) {

	int i, iterations = 5;

	for(i = 0; i < iterations; i ++) {

		sem_wait(&chopstick[no]);
		sem_wait(&chopstick[(no+1)%n]);

		printf("Philosopher %d -> Begin eating\n",no);
		sleep(1);
		printf("Philosopher %d -> Finish eating\n",no );

		sem_post(&chopstick[no]);
		sem_post(&chopstick[(no+1)%n]);
	}

	pthread_exit(NULL);
}

int main() {
	int i, res;

	pthread_t a_thread[100];
	printf("Enter the number of philosophers:\n");
	scanf("%d",&n);

	for(int i = 0; i < n; i ++) {

		res = sem_init(&chopstick[i], 0, 0);

		if(res == -1) {
			perror("Semaphore initalization failed");
			exit(1);
		}
	}

	for(int i = 0; i < n; i ++) {
		res = pthread_Create(&a_thread[i], NULL, thread_func, (int*));

		if(res != 0) {
			perror("Semaphore creation failed");
			exit(1);
		}

		sem_post(&chopstick[i]);
	}

	for(int i = 0; i < n; i ++) {
		res = pthread_join(a_thread[i], NULL);
		if(res != 0) {
			perror("Semaphore join failed");
			exit(1);
		}
	}

	printf("Thread join successful\n");
	for(int i = 0; i < n; i ++) {
		res = sem_destroy(&chopstick[i]);

		if(res == -1) {
			perror("Semaphore destruction failed");
			exit(1);
		}
	}

	return 0;
}
