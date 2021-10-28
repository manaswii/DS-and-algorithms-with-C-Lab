#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coEfficient;
    int power;
    struct Node *next;
};

void createList(struct Node **head)
{
    int input, coEfficient, power;
    while (1)
    {
        printf("Enter 1 to add a new element\nEnter 2 to finish list: ");
        scanf("%d", &input);
        if (input == 1)
        {
            printf("\nEnter the new term's coEfficient: ");
            scanf("%d", &coEfficient);
            printf("\nEnter the new term's power: ");
            scanf("%d", &power);

            struct Node* tmp = malloc(sizeof(struct Node));
            struct Node* tmp2 = *head;
            tmp->coEfficient = coEfficient;
            tmp->power = power;
            *head = tmp;
            (*head)->next = tmp2;

        }
        else if (input == 2)
        {
            return;
        }
    }
}

void addPolynomials(struct Node* head1, struct Node* head2, struct Node** answer)
{
    if (head1 == NULL && head2 == NULL)
        return;
    
    
    else if (head1->power == head2->power)
    {
        struct Node* tmp = malloc(sizeof(struct Node));
        struct Node* tmp2 = *answer;
        tmp->coEfficient = head1->coEfficient + head2->coEfficient;
        tmp->power = head1->power;
        tmp->next = tmp2;
        *answer = tmp;
        addPolynomials(head1->next, head2->next, answer);
    }
    else if (head1->power > head2->power)
    {
        struct Node* tmp = malloc(sizeof(struct Node));
        struct Node* tmp2 = *answer;
        tmp->coEfficient = head1->coEfficient;
        tmp->power = head1->power;
        tmp->next = tmp2;
        *answer = tmp;
        addPolynomials(head1->next, head2, answer);
    }
    else
    {
        struct Node* tmp = malloc(sizeof(struct Node));
        struct Node* tmp2 = *answer;
        tmp->coEfficient = head2->coEfficient;
        tmp->power = head2->power;
        tmp->next = tmp2;
        *answer = tmp;
        addPolynomials(head1, head2->next, answer);
    }

}

void printList(struct Node* head)
{
    while(head != NULL)
    {
        if (head->coEfficient > 0)
            printf("+");
        else
            printf("-");

        printf("%d x^%d ", head->coEfficient, head->power);
        head = head->next;
    }
}

int main()
{
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node* answer = NULL;
    printf("\nCreating list 1.\n");
    createList(&head1);
    printf("\nCreating list 2.\n");
    createList(&head2);
    addPolynomials(head1, head2, &answer);
    printList(answer);
}