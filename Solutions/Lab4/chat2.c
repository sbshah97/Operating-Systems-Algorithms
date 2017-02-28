//receive
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 128
void die(char *s)
{
	perror(s);
	exit(1);
}
struct msgbuf
{
	long mtype;
	char mtext[MAXSIZE];
};
void main()
{
struct msgbuf sbuf;
	size_t buflen;
	int msqid;
	key_t key;
	struct msgbuf rcvbuffer;
	key=1234;
	while(1)
	
	{
	if((msqid=msgget(key,0666))<0)
	{
		die("msgget()");
	}
	sbuf.mtype=1;
	
	if(msgrcv(msqid,&rcvbuffer,MAXSIZE,1,0)<0)
	{
		die("msgrcv");
	}
	printf("%s\n",rcvbuffer.mtext);
	//send
	printf("Enter a message to add to the message queue:\n");
	scanf("%[^\n]",sbuf.mtext);
	getchar();
	buflen=strlen(sbuf.mtext)+1;
	if(msgsnd(msqid,&sbuf,buflen,IPC_NOWAIT)<0)
	{
		printf("%d ,%d ,%s ,%d\n",msqid,sbuf.mtype,sbuf.mtext,buflen);
		die("msgsnd");
	}
	else
	{
		printf("message sent\n");
	}
	}
	exit(0);
}
