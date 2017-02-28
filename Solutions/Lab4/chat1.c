//sending message
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>
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
	int msqid;
	struct msgbuf rcvbuffer;
	int msgflg=IPC_CREAT|0666;
	key_t key;
	struct msgbuf sbuf;
	size_t buflen;
	key=1234;
	int i;
	printf("HI");
	
	
	if((msqid=msgget(key,msgflg))<0)
	{
		die("msgget");
	}
	sbuf.mtype=1;
	for(i=0;i<5;i++)
	{
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
	if((msqid=msgget(key,0666))<0)
	{
		die("msgget()");
	}
	if(msgrcv(msqid,&rcvbuffer,MAXSIZE,1,0)<0)
	{
		die("msgrcv");
	}
	else
	{
	printf("%s\n",rcvbuffer.mtext);
	}
	}
	exit(0);
}
