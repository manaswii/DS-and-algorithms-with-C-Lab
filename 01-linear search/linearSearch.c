#include <stdio.h>
#include <stdlib.h>

int linearSearch(int array[], int value, int arraySize);

int main()
{
    int arraySize, value;
    printf("Enter array size: \n");
    scanf("%d", &arraySize);
    printf("Enter value to find: \n");
    scanf("%d", &value);

    int* array = malloc (sizeof(int) * arraySize);

    printf("input array values \n");
    for (int i = 0; i < arraySize; ++i)
    {
        scanf("%d", &array[i]);
    }

    int index = (linearSearch(array, value, arraySize));

    if (index == -1)
    {
        printf("element not found");
    }
    else
    {
        printf("element found at %d", index);
    }
}

int linearSearch(int array[], int value, int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        if (array[i] == value)
            return i;
    }

    return -1;
}