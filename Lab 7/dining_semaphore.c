# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

# include <ctype.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <sys/sem.h>

sem_t chopstick[100];

int n;

void *thread_func(int no)

{

int i,iteration=5;

for(i=0;i<iteration;++i)

{

sem_wait(&chopstick[no]);

sem_wait(&chopstick[(no+1)%n]);

printf("\nPhilosopher %d –> Begin eating",no);

sleep(1);

printf("\nPhilosopher %d –> Finish eating\n",no);

sem_post(&chopstick[no]);

sem_post(&chopstick[(no+1)%n]);

}

pthread_exit(NULL);

}

int main()

{

int i,res;

pthread_t a_thread[100];

printf("\nEnter the number of philosopher :");

scanf("%d",&n);

for(i=0;i<n;++i)

{

res=sem_init(&chopstick[i],0,0);

if(res==-1)

{

perror("semaphore initialization failed");

exit(1);

}

}

for(i=0;i<n;++i)

{

res=pthread_create(&a_thread[i],NULL,thread_func,(int*) i);

if(res!=0)

{

perror("semaphore creation failed");

exit(1);

}

sem_post(&chopstick[i]);

}

for(i=0;i<n;++i)

{

res=pthread_join(a_thread[i],NULL);

if(res!=0)

{

perror("semaphore join failed");

exit(1);

}

}

printf("\n \n thread join succesfull\n");

for(i=0;i<n;++i)

{

res=sem_destroy(&chopstick[i]);

if(res==-1)

{

perror("semaphore destruction failed");

exit(1);

}

}

exit(0);

}