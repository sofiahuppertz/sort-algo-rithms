#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// time complexity: O(nlogn), worst case: O(n^2).

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int *a, int *b);


int main(void)
{
    srand(time(NULL));
    int arr[] = {4, 5, 6, 3, 2, 1, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivotal = partition(arr, low, high);
        quicksort(arr, low, pivotal - 1);
        quicksort(arr, pivotal + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivotal_idx = rand() % (high - low) + low;
    int pivotal = arr[pivotal_idx];

    swap(&arr[pivotal_idx], &arr[high]);
    
    int i = low;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivotal)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[high], &arr[i]);
    return i;

}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}