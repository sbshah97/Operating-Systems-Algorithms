#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(){
	int shmid;
	int *shmp;
	int MIN;
	int temp;
	int flag =SHM_R | SHM_W;
	
	int pid=fork();
	if(pid==0){
		int i;
		printf("Child Process\n");
		printf("Trying to get shared memory ID: %d\n",3456);
		if((shmid=shmget(3456,1024,flag))<0)
			perror("Error in shmget\n");
		shmp = (int *)shmat(shmid, 0,0);
		int num;
		printf("Enter the number of terms\n->" );
		scanf("%d",&num);
		if(num<shmp[0]||num>shmp[1]){
			printf("Enter again !\n");
			scanf("%d",&num);
		}
		shmp[0]=num;
		shmp[1]=0;
		shmp[2]=1;
		for(i=3;i<num;i++){
			shmp[i]=shmp[i-1]+shmp[i-2];
		}			
		printf("----------------------------------------------\n");
				
	}
	else{
		if((shmid=shmget(3456,1024,flag))<0){
			perror("Error in shmget\n");
			printf("Trying to create this segment\n");
			if((shmid=shmget(3456,1024,flag|IPC_CREAT))<0)
				perror("Error in creating shmget\n");
		}
		printf("Parent\n");
		
		shmp = (int *)shmat(shmid, 0, 0);
		shmp[0]=4;     //min
		shmp[1]=20;    //max
		wait();
		for(int i=1;i<shmp[0];i++)
			printf("%d ",shmp[i]);
		shmdt(shmp);
		shmctl(3456,IPC_RMID,NULL);
		printf("\n");
	}
}