#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10000
void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int p=Partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int Partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1,j;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i+1);
}

int main()
{
    int N;
    int arr[max];

    printf("Enter number of elements (max %d): ", max);
    scanf("%d", &N);

    if (N >max) {
        printf("Error: Maximum size exceeded.\n");
        return 1;
    }
    srand(time(0));
    for (int i=0;i<N;i++)
        arr[i]=rand()%10000;

    printf("Unsorted elements: ");
    for (int i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\n");

    clock_t start=clock();
    quickSort(arr,0,N-1);
    clock_t end=clock();

    printf("Sorted elements: ");
    for (int i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\n");

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", N, time_taken);

    return 0;
}
