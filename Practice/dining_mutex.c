#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#define philosopher 5

pthread_mutex_t chopstick[philosopher];

void *thread_func(int n) {

	for(int i = 0; i < philosopher; i ++) {
		sleep(1);

		pthread_mutex_lock(&chopstick[n]);
		pthread_mutex_lock(&chopstick[(n+1)%philosopher]);

		printf("Begin Eating: %d\n",n);
		sleep(1);
		printf("Finish Eating: %d\n",n);

		pthread_mutex_unlock(&chopstick[n]);
		pthread_mutex_unlock(&chopstick[(n+1)%philosopher]);

	}

	pthread_exit(NULL);
}

int main() {

	pthread_t a_thread[philosopher];

	void *thread_func(int n);

	for(int i = 0; i < philosopher; i ++) {
		int res = pthread_mutex_init(&chopstick[i], NULL);

		if(res == -1) {
			perror("Mutex initialization failed");
			exit(1);
		}
	}

	for(int i = 0; i < philosopher; i ++) {
		int res = pthread_create(&philosopher[i], NULL, thread_func, );
	}
}