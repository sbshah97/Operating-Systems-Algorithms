#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int a[], int low, int high)
{
    int j;
    int pivot = a[high];
    int i = (low - 1);

    for (j = low; j <= high- 1; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void Merge(int *a,int *L,int leftCount,int *R,int rightCount) {

	int i,j,k;

	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	while(i < leftCount) a[k++] = L[i++];
	while(j < rightCount) a[k++] = R[j++];
}


void MergeSort(int *a,int n) {
	int mid,i, *L, *R;
	if(n < 2) return;
	mid = n/2;


	L = (int*)malloc(mid*sizeof(int));
	R = (int*)malloc((n- mid)*sizeof(int));

	for(i = 0;i<mid;i++) L[i] = a[i];
	for(i = mid;i<n;i++) R[i-mid] = a[i];

	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(a,L,mid,R,n-mid);
        free(L);
        free(R);
}

int main()
{
int i,a[10],size;

printf("Enter size:");
scanf("%d",&size);

printf("Enter elements:\n");

for(i=0;i<size;i++)
	scanf("%d",&a[i]);

pid_t pid=fork();

if(pid==0)
{
printf("Quick sort, child process:\n");
quickSort(a,0,size-1);
printArray(a,size);
}
else
{   wait();
	//sleep(10);
    printf("Merge sort, parent process:\n");
    
    printf("Enter size:");
    scanf("%d",&size);
    
    printf("Enter elements:\n");

		for(i=0;i<size;i++)
		scanf("%d",&a[i]);
    
    MergeSort(a,size);
    printArray(a,size);
}
}
