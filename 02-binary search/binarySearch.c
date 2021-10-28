#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[], int arraysize);
void arraySort(int array[], int arraysize);
void printArray(int array[], int arrayLen);

int main(){

    int size;
    printf("Enter the arary size: \n");
    scanf("%d", &size);

    int* array = malloc(sizeof(int) * size);

    if (array == NULL)
    {
        return 1;
    }
        
    for (int i = 0; i < size; ++i)
    {
        printf("enter the %d element of array = ", i );
        scanf("%d", &array[i]);
    }

    arraySort(array, size);
    printf("sorted array is: ");
    printArray(array, size);

    int val = binarySearch(array, size);
    
    if (val == -1)
    {
        printf("value not found \n");
    }
    else
    {
        printf("value found at index = %d", val);
    }
}

void arraySort(int array[], int arraysize)
{
    for (int i = 0; i < arraysize - 1; ++i)
    {
        int smallest = i;

        for (int j = i + 1; j < arraysize; ++j)
        {
            if (array[j] < array[smallest])
            {
                smallest = j;
            }
        }
        
        int tmp = array[i];
        array[i] = array[smallest];
        array[smallest] = tmp;
    }

}

int binarySearch(int array[], int arraysize)
{
    int low = 0, high = arraysize - 1, key, mid;
    printf("enter the value to find: \n");
    scanf("%d", &key);

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (array[mid] == key)
        {
            return mid;
        }
        else if (array[mid] < key)
        {
            low = mid + 1;
        }
        else if (array[mid] > key)
        {
            high = mid - 1;
        }
    }

    return -1;
    
}
void printArray(int array[], int arraysize)
{
    for (int i = 0; i < arraysize; ++i)
    {
        printf("%d   ", array[i]);
    }
    printf("\n");
}