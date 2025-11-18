#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[10][10], t[10][10];

    // ---- INPUT MATRIX SIZE ----
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // ---- INPUT MATRIX ELEMENTS ----
    printf("Enter the matrix elements:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // ---- COMPUTE TRANSPOSE ----
    // Transpose is obtained by swapping row and column indices
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }

    // ---- DISPLAY TRANSPOSE ----
    printf("\nTranspose Matrix:\n");
    for (i = 0; i < c; i++) {       // NOTE: rows & columns swapped
        for (j = 0; j < r; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/*
#include <stdio.h>

int main() {
    int s[20][3], t[20][3];
    int i, j, m, n, num;

    // ---- INPUT TRIPLET REPRESENTATION ----
    printf("Enter rows, columns and number of non-zero elements: ");
    scanf("%d %d %d", &m, &n, &num);

    printf("Enter sparse matrix triplets (row col value):\n");
    for (i = 0; i <= num; i++) {
        scanf("%d %d %d", &s[i][0], &s[i][1], &s[i][2]);
    }

    // ---- FIRST ROW OF RESULT ----
    t[0][0] = n;      // Rows become columns
    t[0][1] = m;      // Columns become rows
    t[0][2] = num;

    int count[20] = {0};   // To count non-zero in each column

    // ---- COUNT OCCURRENCES OF EACH COLUMN ----
    for (i = 1; i <= num; i++) {
        count[s[i][1]]++;
    }

    // ---- COMPUTE STARTING INDEX FOR EACH COLUMN ----
    int index[20];
    index[0] = 1;

    for (i = 1; i < n; i++) {
        index[i] = index[i - 1] + count[i - 1];
    }

    // ---- BUILD TRANSPOSE USING FAST METHOD ----
    for (i = 1; i <= num; i++) {
        int col = s[i][1];          // Current column becomes row
        int pos = index[col];       // Position in result matrix
        index[col]++;

        t[pos][0] = s[i][1];        // New row = old column
        t[pos][1] = s[i][0];        // New col = old row
        t[pos][2] = s[i][2];        // Copy value
    }

    // ---- OUTPUT TRANSPOSETED TRIPLET ----
    printf("\nFast Transpose Triplet:\n");
    for (i = 0; i <= num; i++) {
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
    }

    return 0;
} */
