#include<stdio.h> /* For printf, scanf, etc...*/
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h> /* For getpid() function */
#include<string.h> /* For strcpy() function */
#define M_SIZE 80 /* Size of the Message */

typedef struct
{
	long msg_to;
	long msg_from;
	char msg_content[M_SIZE];
} MESSAGE;

int main()
{
	key_t key;
	int mq_handle;
	struct msqid_ds *info;
	int ret;
	int mypid=getpid(); /* To uniquely identify ourselves */
	MESSAGE msg,ret_msg; /* msg - messge to send. ret_msg - to retrieve message

	/* Create Key */
	key=ftok(".",2234);
	printf("Key generated = %08X\n",key);

	/* Create message queue */
	mq_handle=msgget(key,IPC_CREAT|0666); /* Create it if it doesn&#39;t exist */
	if(mq_handle<=-1)
	{
		printf("Error creating message queue\n");
		perror("MQ Sample"); /* print the error */
		return(1);
	}
	printf("Message Queue created\n");

	/* Obtain information */
	ret=msgctl(mq_handle,IPC_STAT,info);
	if(ret==-1)
	{
		printf("Failed to obtain message queue information\n");
		perror("MQ Sample");
		exit(1);
	}
	printf("MQ Information:\n");
	printf("Owner UID: %d\n",info->msg_perm.uid);
	printf("Owner GID: %d\n",info->msg_perm.gid);
	printf("# of bytes on queue: %d\n",info->msg_cbytes);
	printf("# of messages on queue: %d\n",info->msg_qnum);
	printf("# of bytes on queue: %d\n",info->msg_qbytes);

	/* Send a message */
	msg.msg_to=mypid; /* send it to ourselves - look at the msgrcv call below*/
	msg.msg_from=mypid;

	memset(msg.msg_content,0x0,M_SIZE); /* clear the msg buffer */
	strcpy(msg.msg_content,"Testing the MQ");
	ret=msgsnd(mq_handle,&msg,sizeof(msg),0);
	if(ret==-1)
	{
		perror("MQ Sample msgsend");
		exit(1);
	}
	printf("Message sent\n");

	/* Retrieve a message */
	ret=msgrcv(mq_handle,&ret_msg,sizeof(ret_msg),mypid,0);
	if(ret==-1)
	{
		perror("MQ Sample msgrcv");
		exit(1);
	}
	printf("Message received: %s\n",ret_msg.msg_content);

	/* Delete message queue */
	msgctl(mq_handle,IPC_RMID,(struct msqid_ds *)0);
	printf("Message Queue deleted\n");

	exit(1);

}
