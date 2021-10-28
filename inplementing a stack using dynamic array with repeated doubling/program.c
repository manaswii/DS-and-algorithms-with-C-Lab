//time complexity to push n element = O(n)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack()
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = 1;
    stack->array = malloc(stack->capacity * sizeof(int));
}

void doubleStack(struct Stack* stack)
{
    stack->capacity *= 2;
    stack->array = realloc(stack->array, stack->capacity * sizeof(int));
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int num)
{
    if(isFull(stack))
    {
        doubleStack(stack);
    }
    stack->array[++(stack->top)] = num;
    printf("\nSuccessfully Pushed\n");
}

int pop(struct Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("\nStack is empty lol.\n");
        return INT_MIN; 
    }
    else
    {
        return stack->array[stack->top--];
    }
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack is empty lol.\n");
        return INT_MIN; 
    }
    else
    {
        return stack->array[stack->top];
    }
}

int main()
{

    struct Stack* stack = createStack();

    while(1)
    {
        printf("\n------------Menu-----------\n");
        printf("Enter 1 for push\nEnter 2 for pop\nEnter 3 for peeking\nEnter 4 to exit\nEnter value: ");
        int num;
        scanf("%d", &num);

        if(num == 1)
        {
            printf("Enter the value to push: ");
            int tmp;
            scanf("%d", &tmp);
            push(stack, tmp);
        }
        else if (num == 2 )
        {
            printf("Popped value is : %d",pop(stack));
        }
        else if (num == 3)
        {
            printf("Peeked value is : %d", peek(stack));
        }
        else if (num == 4)
        {
            printf("Thank You!!\n");
            break;
        }
    }
}