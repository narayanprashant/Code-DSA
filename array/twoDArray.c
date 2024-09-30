#include <stdio.h>  // Include standard input/output library for printf
#include <stdlib.h> // Include standard library for memory allocation

int main() {
    // Declare and initialize a 2D array A with 3 rows and 4 columns
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};  

    // Declare an array of integer pointers B with 3 elements
    int *B[3];  
    // Declare a double pointer C, which will be used to create a 2D array dynamically
    int **C;  
    int i, j;  // Declare integer variables for loop iteration

    // Allocate memory for each row of B, which will hold 4 integers
    B[0] = (int *)malloc(4 * sizeof(int));  
    B[1] = (int *)malloc(4 * sizeof(int));  
    B[2] = (int *)malloc(4 * sizeof(int));  

    // Allocate memory for the double pointer C, which will point to 3 integer pointers
    C = (int **)malloc(3 * sizeof(int *));  
    // Allocate memory for each row of C, which will hold 4 integers
    C[0] = (int *)malloc(4 * sizeof(int));  
    C[1] = (int *)malloc(4 * sizeof(int));  
    C[2] = (int *)malloc(4 * sizeof(int));  

    // Loop through the rows of C
    for (i = 0; i < 3; i++) {
        // Loop through the columns of C
        for (j = 0; j < 4; j++)
            printf("%d ", C[i][j]);  // Print each element of C
        printf("\n");  // Print a newline after each row
    }

    // Free allocated memory for B
    for (i = 0; i < 3; i++) {
        free(B[i]);
    }
    // Free allocated memory for C
    for (i = 0; i < 3; i++) {
        free(C[i]);
    }
    free(C);  // Free the memory allocated for the pointer array C

    return 0;  // Return 0 to indicate successful execution
}
