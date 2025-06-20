#include <stdio.h>

void getMagicSquare(int n) 
{
    int magicSquare[n][n];
    // Initialize the matrix with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Set initial position for 1
    int i = n / 2;
    int j = n - 1;
    // Fill the magic square
    for (int num = 1; num <= n * n;) 
    {
        if (i == -1 && j == n) 
        {
            j = n - 2;
            i = 0;
        } else 
        {
            // Wrap around if needed
            if (j == n)
                j = 0;
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j] != 0) 
        {
            j -= 2;
            i++;
            continue;
        } else
            magicSquare[i][j] = num++;
        j++;
        i--;
    }
    // Print the magic square
    printf("Magic Square for n=%d:\nSum of each row/column/diagonal is %d\n\n", n, n * (n * n + 1) / 2);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
            printf("%3d ", magicSquare[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    // Get user input for the size of the magic square
    printf("Enter an odd positive number to generate magic square: ");
    scanf("%d", &n);
    if (n % 2 == 0 || n <= 0) {
        printf("INVALID INPUT\n");
        return 0;
    }
    // Generate and print the magic square
    getMagicSquare(n);

    return 0;
}
