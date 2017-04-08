
#include<stdio.h>

int mutex=1,full=0,empty=3,x=0;

main() {

	int n;

	void producer();

	void consumer();

	int wait(int);

	int signal(int);

	printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");

	while(1) {

		printf("\nENTER YOUR CHOICE\n");

		scanf("%d",&n);

		switch(n) {

			case 1:

			if((mutex==1)&&(empty!=0))

				producer();

			else

				printf("BUFFER IS FULL");

			break;

			case 2:

			if((mutex==1)&&(full!=0))

				consumer();

			else

				printf("BUFFER IS EMPTY");

			break;

			case 3:

			exit(0);

			break;

		}

	}

}

int wait(int s) {

	return(--s);

}

int signal(int s) {

	return(++s);

}

void producer() {

	mutex=wait(mutex);

	full=signal(full);

	empty=wait(empty);

	x++;

	printf("\nproducer produces the item%d",x);

	mutex=signal(mutex);

}

void consumer() {
	
	mutex=wait(mutex);

	full=wait(full);

	empty=signal(empty);

	printf("\n consumer consumes item%d",x);

	x--;

	mutex=signal(mutex);

}