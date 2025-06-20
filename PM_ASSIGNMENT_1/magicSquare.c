#include <stdio.h>

void generateMagicSquare(int n, int magicSquare[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    int num = 1;
    int i = n / 2;
    int j = n - 1;

    while (num <= n * n) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            if (j == n) {
                j = 0;
            }
            if (i < 0) {
                i = n - 1;
            }
        }
        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }

        j++;
        i--;
    }
}

void print(int n, int array[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int checkMagicSquare(int n, int array[n][n]) {
    int sum = n * (n * n + 1) / 2;

    // Check rows and columns sums
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        int colSum = 0;
        
        for (int j = 0; j < n; j++) {
            rowSum += array[i][j];
            colSum += array[j][i];
        }

        if (rowSum != sum || colSum != sum) {
            return 0;
        }
    }

    // Check diagonal sums
    int diagSum1 = 0;
    int diagSum2 = 0;
    
    for (int i = 0; i < n; i++) {
        diagSum1 += array[i][i];
        diagSum2 += array[i][n - i - 1];
    }

    if (diagSum1 != sum || diagSum2 != sum) {
        return 0;
    }

    return 1; // If all sums match, it's a valid magic square
}


int main() {
    int n;
    printf("Enter the number of sides in the magic square: ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 == 0) {
        printf("INVALID INPUT\n");
        return 0;
    }

    int printOrCheck;
    printf("Enter '1' to print a magic square or '2' to check if a magic square is valid: ");
    scanf("%d", &printOrCheck);

    int magicSquare[n][n];

    if (printOrCheck == 1) {
        generateMagicSquare(n, magicSquare);
        printf("Generated Magic Square:\n");
        print(n, magicSquare);
    } else if (printOrCheck == 2) {
        printf("Enter the values of the magic square row-wise separated by spaces:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &magicSquare[i][j]);
            }
        }

        int isValid = checkMagicSquare(n, magicSquare);

        if (isValid) {
            printf("\nGiven Magic Square is Valid!!\n");
        } else {
            printf("\nGiven Magic Square is Invalid!!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
