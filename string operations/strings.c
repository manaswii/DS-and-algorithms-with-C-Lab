#include <stdio.h>
#include <string.h>

void insertCharacter(char* str, int *length)
{
    for ( int i = 0; i < *length; ++i)
    {
        printf("%c[%d] + ", str[i], i);
    }
    printf("\n Enter the index position to add character at: \n");
    int index;
    scanf("%d", &index);
    fflush(stdin);
    for (int i = *length; i >= index; --i)
    {
        str[i + 1] = str[i];
    }
    printf("\nEnter the character to add: \n");
    char input;
    scanf("%c", &input);
    str[index] = input;
    printf("\n new string -> %s\n", str);
    *length += 1;
}

void deleteChar(char* str, int *length)
{
    for ( int i = 0; i < *length; ++i)
    {
        printf("%c[%d] + ", str[i], i);
    }
    printf("\n Enter the index position to to delete: \n");
    int index;
    scanf("%d", &index);

    for (int i = index; i < *length - 1; ++i)
    {
        str[i] = str[i + 1];
    }
    *length -= 1;
    printf("\n new string -> %s\n", str);
}

void reverseString(char* str, int *length)
{
    printf("old string -> %s\n", str);
    for (int i  = 0; i < *length / 2; ++i)
    {
        int tmp = str[i];
        str[i] = str[*length - 1 - i];
        str[*length - i - 1] = tmp;
    }
    printf("new string -> %s\n", str);
} 

int main()
{
    char str[100];
    printf("Please enter a string :\n");
    gets(str);
    int length = strlen(str);

    //note- all the functions modify the value of length variable and the strings.
    while(1)
    {
        printf("Enter 1 to reverse string,\nEnter 2 to delete a character,\nEnter 3 to insert character,\nEnter 4 to print string\nEnter -1 to exit");
        int input;
        printf("\n");
        scanf("%d", &input);

        if (input == 1)
        {
            reverseString(str, &length);
        }
        else if (input == -1)
        {
            break;
        }
        else if (input == 3)
        {
            insertCharacter(str, &length);
        }
        else if(input == 2)
        {
            deleteChar(str, &length);
        }
        else if (input == 4)
        {
            printf("%s\n", str);
        }
    }
}