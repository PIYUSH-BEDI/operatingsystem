#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[30], int n)
{
    int i, j, min_idx;

// One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
void insertionsort(int arr[30], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
while(j>=0 && temp <= arr[j])
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp;
    }
}
void fork1()
{
        int arr[25],arr1[25],n,i,status;
        printf("\nEnter the no of values in array :");
        scanf("%d",&n);
        printf("\nEnter the array elements :");
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        int pid=fork();
        if(pid==0)
        {
                sleep(10);
                printf("\nchild process\n");
                printf("child process id=%d\n",getpid());
                selectionSort(arr,n);
printf("\nElements Sorted Using selectionsort:");
                printf("\n");
                for(i=0;i<n;i++)
                        printf("%d,",arr[i]);
                printf("\b");
                printf("\nparent process id=%d\n",getppid());
                system("ps -x");
       }
      else
       {
                printf("\nparent process\n");
                printf("\nparent process id=%d\n",getppid());
                insertionsort(arr,n);
                printf("Elements Sorted Using insertionsort:");
                printf("\n");
                for(i=0;i<n;i++)
                        printf("%d,",arr[i]);
                printf("\n\n\n");
      }
 }
 int main()
 {
        fork1();
        return 0;
 }
