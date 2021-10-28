#include <stdio.h>

void takeInput(int array[], int size);
void printSeparator();
void printArray(int array[], int size);


int main()
{
    int size;
    printf("enter the size of the array: ");
    scanf("%d", &size);
    int array[100];
    takeInput(array, size);

    while(1)
    {
        printf(" Enter 1 to add element\n Enter 2 to delete element\n Enter 3 to exit:  ");
        int input;
        scanf("%d", &input);

        if (input == 3)
            break;
    }
}

void takeInput(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("Enter value for index position %d: ", i);
        scanf("%d", &array[i]);
    }
    printArray(array, size);
}

void printSeparator()
{
    printf("\n");
    for (int i = 0; i < 10; ++i)
    {
        printf('=');
    }
    printf("\n");
}

void printArray(int array[], int size)
{
    printSeparator();
    printf("final array: \n");
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printSeparator();
}


