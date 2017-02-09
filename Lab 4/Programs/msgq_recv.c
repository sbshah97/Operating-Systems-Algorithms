#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE     128

void die(char *s) {
  perror(s);
  exit(1);
}

struct msgbuf {
    long mtype;
    char mtext[MAXSIZE];
};

main() {

    int msqid;
    int msgflg = IPC_CREAT | 0666;
    
    key_t key;
    
    struct msgbuf sbuf;
    size_t buflen;
    
    key = 1234;

    if(msqid = msgget(key, 0666) < 0) {
        die("msgget");
    }

    if(msgrcv(msqid, &sbuf, MAXSIZE, 1, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }

    printf("%s\n",sbuf.mtext);
    exit(0);
}

