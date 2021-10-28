#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numRows = 0, numCols = 0, numOfNonZero = 0;
    while(numRows < 1 || numCols < 1)
    {
        printf("Enter number of rows:");
        scanf("%d", &numRows);
        printf("Enter number of columns: ");
        scanf("%d", &numCols);
    }

    //creating the 2d matrix
    int array [numRows][numCols];
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            printf("Enter the %d element of the %d row: ", j + 1, i + 1);
            scanf("%d", &array[i][j]);
            if (array[i][j] != 0)
            {
                ++numOfNonZero;
            }
        }
    }
    //creating the sparse matrix
    int sparse [3] [numOfNonZero];
    int numOfElementsInserted = 0;
    for(int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            if (array[i][j] != 0)
            {
                sparse[0][numOfElementsInserted] = i;
                sparse[1][numOfElementsInserted] = j;
                sparse[2][numOfElementsInserted] = array[i][j];
                ++numOfElementsInserted;
            }
        }
    }

    //printing the sparse matrix
    for(int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < numOfNonZero; ++j)
        {
            printf(" %d ", sparse[i][j]);
        }
        printf("\n");
    }
}