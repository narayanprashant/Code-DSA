#include<stdio.h>
#include<stdlib.h>

// Define a structure 'Array' to represent an array along with its size and length
struct Array
{
    int A[10];   // Array 'A' can hold up to 10 integers.
    int size;    // 'size' represents the maximum capacity of the array (in this case, 10).
    int length;  // 'length' indicates the actual number of elements present in the array.
};

// Function to display the elements of the array
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");

    // Loop through the array 'A' and print each element
    for(i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);  // Print each element in the array
}

// Function to check if the array is sorted in non-decreasing order
int isSorted(struct Array arr)
{
    int i;

    // Loop through the array and check each adjacent pair of elements
    for(i = 0; i < arr.length - 1; i++)
    {
        // If any element is greater than the next, the array is not sorted
        if(arr.A[i] > arr.A[i + 1])
            return 0;  // Return 0 if the array is not sorted
    }

    // If the loop completes without finding any unsorted pair, the array is sorted
    return 1;  // Return 1 if the array is sorted
}

// Main function to demonstrate the isSorted function and display array elements
int main()
{
    // Initialize an array 'arr1' with 9 elements
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    // Call the 'isSorted' function to check if the array is sorted and print the result (1 = sorted, 0 = not sorted)
    printf("%d", isSorted(arr1));  // Output will be '1' because the array is sorted

    // Call the 'Display' function to print the array elements
    Display(arr1);

    return 0;  // End of the program
}
