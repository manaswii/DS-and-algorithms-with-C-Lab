#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* tmp= malloc(sizeof(struct Node));
    //in case heap is full.
    if (tmp == NULL)
    {
        return NULL;
    }
    tmp->val = data;
    tmp->next = NULL;
    return tmp;
}


int isEmpty(struct Node* root)
{
    return !root;
}

void push(struct Node** root, int data)
{
    struct Node* tmp = newNode(data);
    if (tmp == NULL)
    {
        printf("Heap overflow\n");
        return;
    }
    tmp->next = *root;
    *root = tmp;
}

int pop(struct Node** root)
{
    if(isEmpty(*root))
    {
        printf("Stack is empty LMAO\n");
        return INT_MIN;
    }
    int popped = (*root)->val;
    struct Node* tmpHead = (*root)->next;
    free (*root);
    *root = tmpHead;
    return popped;
}

int main()
{
    struct Node* stack = NULL;

    while(1)
    {
        printf("\n1 to push\n2 to pop\n3 to exit\n");
        int input;
        scanf("%d", &input);
        
        if(input == 1)
        {
            printf("Enter num to push: ");
            int num;
            scanf("%d", &num);
            push(&stack, num);
        }
        else if (input == 2)
        {
            int poppedNum = pop(&stack);
            printf("Popped number is : %d", poppedNum);
        }
        else if (input == 3)
        {
            break;
        }
    }
}