#include <stdio.h>  // Include standard input/output library for printf

// Global variable 'x' initialized to 0
int x = 0;  

// Function that takes an integer 'n' as a parameter
int fun(int n)
{
    // Check if 'n' is greater than 0
    if (n > 0)
    {
        x++;  // Increment 'x' by 1
        // Call 'fun' recursively with 'n-1', adding the current value of 'x' to the result
        return fun(n - 1) + x; 
    }
    return 0;  // If 'n' is not greater than 0, return 0
}

int main() {
    int r;  // Declare an integer variable 'r' to store return values from 'fun'

    // First call to 'fun' with 5
    r = fun(5);  
    printf("%d\n", r);  // Print the result of the first call to 'fun'

    // Second call to 'fun' with 5
    r = fun(5);  
    printf("%d\n", r);  // Print the result of the second call to 'fun'

    return 0;  // Return 0 to indicate successful execution
}
