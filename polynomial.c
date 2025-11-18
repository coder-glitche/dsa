#include <stdio.h>

#define MAX 20   // Maximum number of polynomial terms

int main() {
    int poly1[MAX][2], poly2[MAX][2], result[MAX][2];
    int n1, n2, i = 0, j = 0, k = 0;

    // ------- INPUT FIRST POLYNOMIAL -------
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    printf("Enter coefficient and power for each term:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d", &poly1[i][0], &poly1[i][1]);  
        // poly1[i][0] = coefficient
        // poly1[i][1] = power
    }

    // ------- INPUT SECOND POLYNOMIAL -------
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);

    printf("Enter coefficient and power for each term:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d", &poly2[i][0], &poly2[i][1]);
    }

    // Reset pointers for merging
    i = j = k = 0;

    // ------- ADDING POLYNOMIALS (MERGE LIKE MERGE-SORT) -------
    while (i < n1 && j < n2) {
        // If powers are equal → add coefficients
        if (poly1[i][1] == poly2[j][1]) {
            result[k][0] = poly1[i][0] + poly2[j][0];
            result[k][1] = poly1[i][1];
            i++; j++; k++;
        }
        // Higher power → directly copy
        else if (poly1[i][1] > poly2[j][1]) {
            result[k][0] = poly1[i][0];
            result[k][1] = poly1[i][1];
            i++; k++;
        } 
        else {
            result[k][0] = poly2[j][0];
            result[k][1] = poly2[j][1];
            j++; k++;
        }
    }

    // ------- COPY REMAINING TERMS -------
    while (i < n1) {
        result[k][0] = poly1[i][0];
        result[k][1] = poly1[i][1];
        i++; k++;
    }

    while (j < n2) {
        result[k][0] = poly2[j][0];
        result[k][1] = poly2[j][1];
        j++; k++;
    }

    // ------- DISPLAY RESULT -------
    printf("\nResultant Polynomial: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d ", result[i][0], result[i][1]);
    }

    return 0;
}