#include<stdio.h>
#include<stdlib.h>

// Define a structure 'Array' to represent an array along with its size and length
struct Array
{
    int A[10];   // Array 'A' can hold up to 10 integers.
    int size;    // 'size' represents the maximum size the array can hold (in this case, 10).
    int length;  // 'length' indicates the actual number of elements stored in the array.
};

// Function to display the elements of the array
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");

    // Loop through each element of the array and print it
    for(i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);  // Print each element in the array 'A'
}

// Utility function to swap two integer values using pointers
void swap(int *x, int *y)
{
    int temp = *x;  // Store the value of 'x' in a temporary variable 'temp'
    *x = *y;        // Assign the value of 'y' to 'x'
    *y = temp;      // Assign the value of 'temp' (original 'x') to 'y'
}

// Function to reverse the array by creating a new array
void Reverse(struct Array *arr)
{
    int *B;  // Pointer to a new array for storing the reversed elements
    int i, j;

    // Allocate memory dynamically for the new array 'B', based on the length of the original array
    B = (int *)malloc(arr->length * sizeof(int));

    // Copy elements from the original array 'A' to the new array 'B' in reverse order
    for(i = arr->length - 1, j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];  // Reverse copy: last element becomes the first, and so on

    // Copy the reversed elements from 'B' back into the original array 'A'
    for(i = 0; i < arr->length; i++)
        arr->A[i] = B[i];  // Transfer the reversed elements

    // Note: The dynamically allocated memory for 'B' should ideally be freed after use, but it's not done here
}

// Function to reverse the array in-place (without using extra space)
void Reverse2(struct Array *arr)
{
    int i, j;

    // Swap the elements of the array starting from both ends (front and back) and move towards the center
    for(i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);  // Swap the elements at index 'i' and 'j'
    }
}

// Main function to demonstrate array reversal
int main()
{
    // Initialize an array 'arr1' with 9 elements
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    // Call the 'Reverse' function to reverse the elements of the array
    Reverse(&arr1);

    // Call the 'Display' function to print the reversed array
    Display(arr1);

    return 0;  // End of the program
}
