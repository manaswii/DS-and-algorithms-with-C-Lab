//doubly linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* next;
    struct Node* prev;
};

//to check if the list is empty
int isEmpty(struct Node* head)
{
    return (head == NULL);
}

//function to add a number at the start of a linked list
void addElementAtStart(struct Node** head, int num)
{
    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->val = num;
    tmp->next = (*head);
    if((*head) != NULL)
        (*head)->prev = tmp;
    tmp->prev = NULL;
    *head = tmp;
    printf("\nElement added successfully.\n");
}

//function to add a node at the end of the linked list
void addElementAtEnd(struct Node* head, int num)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->val = num;
    tmp->next = NULL;
    tmp->prev = head;
    head->next = tmp;
    printf("\nElement added successfully.\n");
}

//add an element in the middle of a list.
void addElementAtMiddle(struct Node* head, int num, int indexToAddAt)
{
    int indexCounter = 0;
    while(indexCounter != indexToAddAt)
    {
        head = head->next;
        ++indexCounter;
    }
    struct Node* tmp = malloc(sizeof(struct Node));
    tmp->val = num;
    tmp->prev = head->prev;
    (head->prev)->next = tmp;
    tmp->next = head;
    printf("\nElement added successfully.\n");
}

//to print the list and return it's size, if list has 2 items, it return 2
int displayList(struct Node* head)
{
    printf("\nDisplaying list\n");
    int index = 0;
    if (isEmpty(head))
    {
        printf("\nList is empty!\n");
        return 0;
    }
    while(head != NULL)
    {
        printf("[ %d ]      %d", index, head->val);
        head = head->next;
        ++index;
        printf("\n");
    }
    printf("\n");
    printf("returning size : %d\n", index);
    return (index);
}

//main function to add Node, it calls other functions to add node at the proper position
void addNode(struct Node** head)
{
    int index;
    int value;
    int size = displayList(*head);
    do
    {
        printf("Enter an index <= %d and >= 0: ", size);
        scanf("%d", &index);
    } while (index > size || index < 0);

    printf("Enter the value you want to add: ");
    scanf("%d", &value);
    if(index == 0)
        addElementAtStart(head, value);
    else if (index == size)
        addElementAtEnd(*head, value);
    else
        addElementAtMiddle(*head, value, index);

}


int main()
{
    struct Node* head = NULL;

    while(1)
    {
        int input;
        printf("\nEnter 1 for adding a node\nEnter 2 to display the list\nEnter 3 to delete an element\nEnter -1 to exit\nInput : ");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                addNode(&head);
                break;
            case 2:
                displayList(head);
                break;
            
            case 3:
                printf("Not implemented yet");
                break;

            case -1:
                return 0;

            default:
                printf("Invalid input!\n");
                break;
        }
        
    }
}
