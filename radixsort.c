# include <stdlib.h>
# include <stdio.h>

//Radix-sort is non-comparative sorting algorithm. Avoids comparison by using "buckets".
//This implementation starts at the LSD (least-significant digit) and works its way up to the MSD (most-significant digit).
//Radix sort operates in O(nw) where n is the number of keys and w is the key length.


//Step 1: Find the largest element in the array, and the number of digits in it.
//Step 2: Sort the elements based on each digit using "buckets" (Counting sort)

void radix_sort(int arr[], int n);
int max_element(int arr[], int n);
void countingsort(int arr[], int exp, int n);

int main(void)
{
    int arr[] = {12, 32, 453, 16, 679};
    int len = sizeof(arr) / sizeof(arr[0]);
    radix_sort(arr, len);
    printf("Sorted array: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void radix_sort(int arr[], int n)
{
    int max;
    int exp;

    max = max_element(arr, n);
    exp = 1;

    while (max / exp > 0) 
    {
        countingsort(arr, exp, n);
        exp *= 10;
    }
    
}

int max_element(int arr[], int n)
{
    int max;
    int i;

    max = arr[0];
    i = 0;
    while (i < n)
    {
        if (max < arr[i])
            max = arr[i];
        i++;
    }
    return max;
}

void countingsort(int arr[], int exp, int n)
{
    int count[10];
    int *output;
    int index;
    int i;

    output = malloc(sizeof(int) * n);
    if (!output)
    {
        printf("Error: malloc failed.\n");
        return;
    }

    i = 0;
    while (i < 10)
    {
        count[i] = 0;
        i++;
    }
    //count number of elements for each digit.
    i = 0;
    while (i < n)
    {
        count[(arr[i] / exp) % 10] += 1;
        i++;
    }

    //cumulative sum of count array.
    i = 1;
    while (i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }

    //Sort numbers into output array.
    i = n;
    while (i-- >= 0)
    {
        index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index] -= 1;
        //We need to decrement count[index] because we decrement the values isnide the count array... to preserve the stability of the previous array/sort.
    }

    //Copy output array to original array.
    i = 0;
    while (i < n)
    {
        arr[i] = output[i];
        i++;
    }

}



