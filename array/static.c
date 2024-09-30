#include <stdio.h>   // Include standard input/output library for printf
#include <stdlib.h>  // Include standard library for memory allocation functions

int main()
{
    // Declare and initialize a static array 'A' with 5 integers
    int A[5] = {2, 4, 6, 8, 10};

    // Declare a pointer 'p' that will point to an integer
    int *p;

    // Declare an integer variable 'i' for loop iteration
    int i;

    // Dynamically allocate memory for an array of 5 integers
    p = (int *)malloc(5 * sizeof(int));
    // Note: It's good practice to check if malloc succeeded, like this:
    // if (p == NULL) { /* handle allocation failure */ }

    // Initialize the dynamically allocated array 'p' with values
    p[0] = 3;  // Assign 3 to the first element of the dynamic array
    p[1] = 5;  // Assign 5 to the second element
    p[2] = 7;  // Assign 7 to the third element
    p[3] = 9;  // Assign 9 to the fourth element
    p[4] = 11; // Assign 11 to the fifth element

    // Loop to print elements of the static array 'A'
    for(i = 0; i < 5; i++)
        printf("%d ", A[i]);  // Print each element of array A
    printf("\n");  // Print a newline for better output formatting

    // Loop to print elements of the dynamically allocated array 'p'
    for(i = 0; i < 5; i++)
        printf("%d ", p[i]);  // Print each element of array p

    // Free the dynamically allocated memory to prevent memory leaks
    free(p);

    return 0;  // Return 0 to indicate successful completion of the program
}
