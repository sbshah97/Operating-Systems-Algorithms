#include <stdio.h>
#include <sys/stypes.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

#define M_SIZE 100

typedef struct {
	ulong msg_to;
	ulong msg_from;
	char msg_content[M_SIZE];
} MESSAGE;

int main() {
	key_t key;
	int mq_handle;
	int ret;
	int mypid = getpid();
	MESSAGE msg, ret_msg;

	//Create key
	key = ftok(".", 1234);
	printf("Key generated = %08X\n",key );

	//Create Message queue
	mq_handle = msgget(key, IPC_CREAT | 0777);
	if(mq_handle <= -1) {
		printf("Error creating message queue\n");
		perror("MQ Sample");
		return 1;
	}
	printf("Message Queue created\n");

	msg.msg_to = mypid;
	msg.msg_from = mypid;

	memset(msg.msg_content, 0x0, M_SIZE);
	strcpy(msg.msg_content, "Testing the Message Queue");

	ret = msgsnd(mq_handle, &msg, sizeof(msg), 0);
	if(ret == -1) {
		perror("MQ sample msgsend");
		exit(1);
	}
	printf("Message sent\n");

	ret = msgrcv(mq_handle, &ret_msg, sizeof(ret_msg), mypid, 0);
	if(ret == -1) {
		perror("MQ Sample msgrcv");
		exit(1);
	}
	printf("Message received: %s\n",ret_msg.msg_content );

	msgctl(mq_handle, IPC_RMID, (struct msqid_ds *) 0);
	printf("Message Queue deleted\n");
	
	return 0;
}