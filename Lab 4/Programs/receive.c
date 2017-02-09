#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE  128
void die(char *s)
{
  perror(s);
  exit(1);
}

typedef struct msgbuf
{
    long    mtype;
    char    mtext[MAXSIZE];
} ;
main()
{
    int msqid,i;
    key_t key;
    struct msgbuf rcvbuffer,sbuf;
   key = 1234;
size_t buflen;
 sbuf.mtype = 1;

for(i=0;i<5;i++)
{
   if ((msqid = msgget(key, 0666)) < 0)
      die("msgget()");
     //Receive an answer of message type 1.
    if (msgrcv(msqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
      die("msgrcv");
    printf("%s\n", rcvbuffer.mtext);



 printf("Enter a message to add to message queue : ");
    scanf("%[^\n]",sbuf.mtext);
    getchar();
    buflen = strlen(sbuf.mtext) + 1 ;
    if (msgsnd(msqid, &sbuf, buflen, IPC_NOWAIT) < 0)
    {
        printf ("%d, %d, %s, %d\n", msqid, sbuf.mtype, sbuf.mtext, buflen);
        die("msgsnd");
    }
    else
        printf("Message Sent\n");


}
    exit(0);
}
