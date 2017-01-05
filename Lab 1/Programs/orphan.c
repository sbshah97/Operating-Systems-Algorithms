#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int arr[10];

void merging(int low, int mid, int high) {
   //Declare variables
   int l1, l2, i;

   //Put the element of the two smaller elements in the new array
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(ar[l1] <= ar[l2])
         b[i] = ar[l1++];
      else
         b[i] = ar[l2++];
   }

   //Finish off in case some of the elements are not put
   while(l1 <= mid)
      b[i++] = ar[l1++];

   //Finish off in case some of the elements are not put
   while(l2 <= high)
      b[i++] = ar[l2++];

   //Copy the elements of first array into the second array
   for(i = low; i <= high; i++)
      ar[i] = b[i];
}

void mergeSort(int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high) / 2;
      mergeSort(low, mid);
      mergeSort(mid+1, high);
      merging(low, mid, high);
   }
   
   else 
      return;
   
}


int main() {

	arr[10] = {1,4,8,7,5,3,6,9,5,2}

	pid_t pid = fork();

	if(pid == 0) {
		printf("Entering Child process now ...\n");
		sleep(10);
		

		printf("Exiting Child process now ...\n");
		exit(0);
	} 

	else if (pid > 0) {
		printf("Entering Parent process now ...\n");
		mergeSort(0, n-1);

		for(i = 0; i < n; i++)
      		printf("%d ", arr[i]);

		printf("Exiting Parent process now ...\n");
		
	}

	return 0;
}