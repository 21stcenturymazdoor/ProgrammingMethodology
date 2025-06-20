#include <stdio.h>

int isValidSubGrid(int sudoku[9][9], int rowStart, int colStart) {
    int visited[10];
    int num;

    for (int i = 0; i < 10; i++) {
        visited[i] = 0; // Initialize visited array
    }

    for (int row = rowStart; row < rowStart + 3; row++) {
        for (int col = colStart; col < colStart + 3; col++) {
            num = sudoku[row][col];

            if (visited[num]) {
                return 0; // If a value comes twice, sudoku is invalid
            } else {
                visited[num] = 1;
            }
        }
    }

    return 1;
}

int isSudokuValid(int sudoku[9][9]) {
    // Checking the validity of each row
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (sudoku[i][j] == sudoku[i][k] && j != k && sudoku[i][j] != 0) {
                    //printf("RowError");
                    return 0;
                }
            }
        }
    }

    // Checking the validity of each column
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (sudoku[j][i] == sudoku[k][i] && j != k && sudoku[j][i] != 0) {
                    //printf("ColumnError");
                    return 0;
                }
            }
        }
    }

    // Checking the validity of each subgrid
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            if (!isValidSubGrid(sudoku, row, col)) {
                //printf("GridError %d %d", row, col);
                return 0;
            }
        }
    }
    return 1;
}


int main(int argc, char *argv[])
{
    FILE *sudokuFile;
    char *filename;
    int digit;
    
    int sudokuGrid[9][9];
    
    for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                sudokuGrid[i][j] = 0;
            }
        }
    
    
    
    // Check if a filename has been inputed in the command
    if (argc < 2)
    {
        printf ("Missing Filename\n");
        return (1);
    }
    else
    {
        filename = argv[1];
        printf ("Filename : %s\n", filename);
    }
    
    // Open file in read-only mode
    sudokuFile = fopen (filename, "r");
    
    // If file opened successfully, input the values of the grid to the 2D Grid
    if (!feof(sudokuFile)){

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                fscanf(sudokuFile, "%d", &sudokuGrid[i][j]);
            }
        }
    
    }else{
        printf ("Failed to open the file\n");
    }
    
    //Here, sudoku grid has been successfully inputted from the text file given.
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (sudokuGrid[i][j] == 0){
                printf("\nINVALID INPUTS !!\n");
                return 0;
            }
        }
    }
    
    if (isSudokuValid(sudokuGrid)){
        printf("\nGiven Sudoku Puzzle is Correct !!\n");
    }else{
        printf("\nGiven Sudoku Puzzle is Incorrect !!\n");
    }
}
