#include <stdio.h>  // Include standard input/output library for printf
#include <stdlib.h> // Include standard library for memory allocation

int main() {
    int *p, *q;  // Declare two integer pointers, 'p' and 'q'
    int i;       // Declare an integer variable 'i' for loop iteration

    // Allocate memory for an array of 5 integers and assign it to pointer 'p'
    p = (int *)malloc(5 * sizeof(int));  
    // Initialize the allocated memory with specific values
    p[0] = 3; p[1] = 5; p[2] = 7; p[3] = 9; p[4] = 11; 

    // Allocate memory for an array of 10 integers and assign it to pointer 'q'
    q = (int *)malloc(10 * sizeof(int));  
    // Copy the values from array 'p' to the first 5 elements of array 'q'
    for (i = 0; i < 5; i++)
        q[i] = p[i];  // Copy values from 'p' to 'q'

    // Free the memory allocated to 'p' since we no longer need it
    free(p);  
    // Point 'p' to the memory allocated for 'q'
    p = q;  
    // Set 'q' to NULL to avoid dangling pointer
    q = NULL;  

    // Print the values stored in the array pointed to by 'p'
    for (i = 0; i < 5; i++)
        printf("%d \n", p[i]);  // Output the values of 'p' (which are now in 'q')

    return 0;  // Return 0 to indicate successful execution
}
