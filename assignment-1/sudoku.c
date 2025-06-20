#include <stdio.h>

/*defining size of sudoku to be 9*/
#define SIZE 9


int okSudoku(int sudoku[SIZE][SIZE], int row, int col, int num) 
{

    for (int i=0;i<SIZE;i++) 
    {
        if (sudoku[row][i]==num || sudoku[i][col]==num) 
        {
            return 0;
        }
    }

    /* Check the presence of number in sudoku grid  (3X3) */
    int startRow=row-row%3;
    int startCol=col-col%3;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (sudoku[i+startRow][j+startCol]==num) 
            {
                return 0; 
            }
        }
    }

    return 1; 
}


/*to validate the sudoku grid */
int isValidSudoku(int sudoku[SIZE][SIZE]) 
{
    for (int i=0; i<SIZE;i++) 
    {
        for (int j=0; j<SIZE;j++) 
        {
            if (sudoku[i][j] != 0) 
            {
                int num = sudoku[i][j];
                sudoku[i][j] = 0;

                
                if (!okSudoku(sudoku, i, j, num))
                 {
                    return 0;
                 }
                sudoku[i][j]=num;
            }
        }
    }
    
    /* Checking the validity of each row */
    for (int i=0;i <SIZE;i++)
    {
        for (int j=0;j<SIZE;j++)
        {
            for (int k=0; k<SIZE;k++)
            {
                if ((sudoku[i][j]==sudoku[i][k])&&(j != k)&&(sudoku[i][j] != 0))
                {
                    return 0;
                }
            }
        }
    }

    /* Checking the validity of each column */
    for (int i=0; i<SIZE;i++)
    {
        for (int j=0;j<SIZE;j++)
        {
            for (int k=0; k<9;k++)
            {
                if ((sudoku[j][i]==sudoku[k][i]) && (j != k) && (sudoku[j][i]!=0))
                {
                    return 0;
                }
            }
        }
    }

    return 1; 
}

/*start of main function*/

int main(int argc, char *argv[]) 
{

	
    /*file input */	
    if (argc != 2)
    {
        printf("\nMISSING FILENAME\n\n");
        return 0;
    }
	
	/*file open in read-only mode*/
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("\nFAILED IN READING THE FILE\n\n");
        return 0;
    }

    int sudoku[SIZE][SIZE];

    for (int i=0;i<SIZE;i++) 
    {
        for (int j=0;j<SIZE;j++) 
        {
            if (fscanf(file, "%d", &sudoku[i][j]) != 1) 
            {
                printf("\nINVALID INPUTS\n\n");
                fclose(file);
                return 0;
            }
        }
    }

    fclose(file);

    /* Validating the Sudoku*/
    if (isValidSudoku(sudoku))
    {
        printf("\nTHE SUDOKU IS VALID\n\n");
    }
    else
    {
        printf("\nTHE SUDOKU IS NOT VALID\n\n");
    }

    return 0;/*program ended successfully*/
    
}/*end of main function*/
