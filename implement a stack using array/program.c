#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

//stack structure
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(sizeof(int) * stack->capacity);
    return stack;
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
    if (isFull(stack))
        printf("Stack overflow\n");
    else
        stack->array[++stack->top] = num;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty lol\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty lol\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int main()
{
    printf("Enter the stack size: ");
    int size;
    scanf("%d", &size);
    struct Stack* stack = createStack(size);

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