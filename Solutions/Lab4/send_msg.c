//IPC_msgq_send.c

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 128


struct msgbuf

{

long mtype;

char mtext[MAXSIZE];

};

main()

{
imt msgflg=IPC_CREAT | 0666;
key_t key=1234;
int msqid=msgget(1234,IPC_CREAT);
printf("Enter message to be sent: ");
struct msgbuf sbuf;
scanf("%[^\n]",sbuf.mtext);
getchar();

size_t buflen;

if(msqid<0) 
{
printf("1");
printf("Failed\n");
exit(1);
}
//Message Type

sbuf.mtype = 1;

buflen=strlen(sbuf.mtext)+1;

if (msgsnd(msqid, &sbuf,buflen , IPC_NOWAIT) < 0)
{
printf("%d %ld %s %d",msqid,sbuf.mtype,sbuf.mtext,buflen);
printf("2");
printf ("Failed");
exit(1);
}

else
{
printf("Message Sent");

exit(1);

}
}
