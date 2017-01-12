#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int arr[] = {1,4,8,7,5,3,6,9,5,2};
int b[100];

void swap(int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

void quickSort(int l, int r) {
  if (l < r) {
    int v = arr[r];
    int i = l - 1, j = r;

    for (;;) {
      while (arr[++i] < v);
      while (arr[--j] > v);
      if (i >= j) break;
      swap(i, j);
    }

    swap(i, r);
    quickSort(l, i - 1);
    quickSort(i + 1, r);
  }
}

void merging(int low, int mid, int high) {
   //Declare variables
   int l1, l2, i;

   //Put the element of the two smaller elements in the new array
   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(arr[l1] <= arr[l2])
         b[i] = arr[l1++];
      else
         b[i] = arr[l2++];
   }

   //Finish off in case some of the elements are not put
   while(l1 <= mid)
      b[i++] = arr[l1++];

   //Finish off in case some of the elements are not put
   while(l2 <= high)
      b[i++] = arr[l2++];

   //Copy the elements of first array into the second array
   for(i = low; i <= high; i++)
      arr[i] = b[i];
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


	pid_t pid = fork();

	if(pid == 0) {
		printf("Entering Child process now ...\n");
		sleep(20);
		
      quickSort(0, 9);

      printf("Entering Child Quick Sort\n");
      for(int i = 0; i < 10; i ++)
         printf("%d ", arr[i]);
      printf("\n");

		printf("Exiting Child process now ...\n");
		exit(0);
	} 

	else if (pid > 0) {
		printf("Entering Parent process now ...\n");
		mergeSort(0, 9);

      printf("Entering Parent Merge Sort\n");
		for(int i = 0; i < 10; i++)
      	printf("%d ", arr[i]);
      printf("\n");

      wait(NULL);

		printf("Exiting Parent process now ...\n");
		
	}

	return 0;
}