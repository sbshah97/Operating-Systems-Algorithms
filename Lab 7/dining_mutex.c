# include<stdio.h>
# include<pthread.h>
# include<stdlib.h>
# include<unistd.h>

# include<ctype.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<semaphore.h>

# define philosopher 5

pthread_mutex_t chopstick[philosopher];

void *thread_func(int n)

	{

	int i,iteration=5;

	for(i=0;i<iteration;++i)

	{

	sleep(1);

	pthread_mutex_lock(&chopstick[n]);

	pthread_mutex_lock(&chopstick[(n+1)%philosopher]);

	printf("\nBegin eating :%d",n);

	sleep(1);

	printf("\nFinish eating:%d",n);

	pthread_mutex_unlock(&chopstick[n]);

	pthread_mutex_unlock(&chopstick[(n+1)%philosopher]);

	}

	pthread_exit(NULL);

}

int main()

	{

	int i,res;

	pthread_t a_thread[philosopher];

	void *thread_func(int n);

	for(i=0;i<philosopher;++i)

	{

	res=pthread_mutex_init(&chopstick[i],NULL);

	if(res==-1)

	{

	perror("mutex initialization failed");

	exit(1);

	}

	}

	for(i=0;i<philosopher;++i)

	{

	res=pthread_create(&a_thread[i],NULL,thread_func,(int)i);

	if(res!=0)

	{

	perror("mutex creation failed");

	exit(1);

	}

	}

	for(i=0;i<philosopher;++i)

	{

	res=pthread_join(a_thread[i],NULL);

	if(res!=0)

	{

	perror("mutex join failed");

	exit(1);

	}

	}

	printf("thread join successful\n");

	for(i=0;i<philosopher;++i)

	{

	res=pthread_mutex_destroy(&chopstick[i]);

	if(res==-1)

	{

	perror("mutex destruction failed");

	exit(1);

	}

	}

	exit(0);

	return 0;
}

