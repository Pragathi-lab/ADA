#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10000

void mergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void merge(int arr[],int low,int mid,int high)
{
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    int L[max],R[max];
    for(i=0;i<n1;i++)
        L[i]=arr[low+i];
    for(j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while(i<n1)
    {
        arr[k++]=L[i++];
    }
    while(j<n2)
    {
        arr[k++]=R[j++];
    }
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

    clock_t start=clock();
    mergeSort(arr,0,N-1);
    clock_t end=clock();

    printf("Sorted elements: ");
    for (int i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\n");

    double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", N, time_taken);

    return 0;
}
