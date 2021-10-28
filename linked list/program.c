//linked list, creation, adding element at any position.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

int display(struct Node *head);

int isEmpty(struct Node *head)
{
    return (head == NULL);
}

void deleteElement(struct Node ** head)
{
    if (isEmpty(*head))
    {
        printf("\nList is already empty. \n");
        return;
    }
    int index;
    int size = display(*head);
    printf("\nEnter the index you want to delete:");
    scanf("%d", &index);

    if (index == 0)
    {
        struct Node* tmp = *head;
        *head = (*head)->next;
        free(tmp);
        printf("\nremoved successfully.\n");
    }
    else if (index == size - 1)
    {
        int tmpIndex = 0;
        struct Node* tmp = *head;
        while(tmpIndex != index - 1)
        {
            tmp = tmp->next;
            ++tmpIndex;
        }
        struct Node* tmp2 = tmp->next;
        tmp->next = NULL;
        free(tmp2);
        printf("\nremoved successfully.\n");
    }
    else
    {
        int tmpIndex = 0;
        struct Node* tmp = *head;
        while(tmpIndex != index - 1)
        {
            tmp = tmp->next;
            ++tmpIndex;
        }
        struct Node* tmp2 = tmp->next;
        tmp->next = tmp->next->next;
        free(tmp2);
        printf("\nremoved successfully.\n");
    }

}

void addElement(struct Node **head)
{
    int value, index;
    int maxIndex = display(*head);

    struct Node *tmp = malloc(sizeof(struct Node)); //new node to be added.
    if (tmp == NULL)
    {
        printf("\nHeap is full.\n");
        return;
    }
    //if maxIndex possible is 0, we will enter at 0th index. else we will ask the user for position to input the value at.
    if (maxIndex == 0)
    {
        printf("\nEnter the value to add: ");
        int index = 0;
        scanf("%d", &value);
        tmp->val = value;
        tmp->next = (*head);
        *head = tmp;
    }
    //if we need to add the node at a specific index.
    else
    {
        //asking user input for the index position to add the value at.
        do
        {
            printf("\nEnter the index to add the value at: ");
            scanf("%d", &index);
        } while (index > maxIndex);
        printf("\nEnter the value to add: ");
        scanf("%d", &value);
        //if we want to add at 0th index.
        if (index == 0)
        {
            tmp->val = value;
            tmp->next = (*head);
            *head = tmp;
            return;
        }
        tmp->val = value;
        //traversing the linked list to that node.
        int currentIndex = 0;
        struct Node *tmpHead = *head;
        while (currentIndex < index - 1)
        {
            tmpHead = tmpHead->next;
            ++currentIndex;
        }
        tmp->next = tmpHead->next;
        tmpHead->next = tmp;
    }
    printf("\nElement successfully added.\n");
}

//returns the list size.
int display(struct Node *head)
{
    printf("\nDisplaying list: \n");
    int index = 0;
    if (isEmpty(head))
    {
        printf("\nList is empty \n");
        return index;
    }
    while (head != NULL)
    {
        printf("[%d] %d\n", index, head->val);
        ++index;
        head = head->next;
    }
    return index;
}

int main()
{
    struct Node *head = NULL;

    while (1)
    {
        printf("Enter 1 to display list\nEnter 2 to add an element at a specific index\nEnter 3 to delete an element from a specific index.\nEnter -1 to exit\nEnter the input value: ");
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            display(head);
            break;
        case 2:
            addElement(&head);
            break;
        case 3:
            deleteElement(&head);
            break;
        case -1:
            return 0;
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
        }
    }
}