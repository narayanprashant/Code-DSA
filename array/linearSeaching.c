#include<stdio.h> // Standard Input/Output header file for printf

// Define a structure named Array to represent an array with additional properties
struct Array
{
    int A[10];    // Array to hold up to 10 integers
    int size;     // Maximum size of the array
    int length;   // Current number of elements in the array
};

// Function to display the elements of the array
void Display(struct Array arr)
{
    int i; // Variable for loop iteration
    printf("\nElements are\n"); // Print a header
    for(i=0; i < arr.length; i++) // Loop through each element in the array
        printf("%d ", arr.A[i]);  // Print each element followed by a space
}

// Function to swap two integers using pointers
void swap(int *x, int *y)
{
    int temp = *x; // Store the value of *x in temp
    *x = *y;       // Assign the value of *y to *x
    *y = temp;     // Assign the value of temp to *y (original *x value)
}

// Function to perform linear search in the array for a given key
int LinearSearch(struct Array *arr, int key)
{
    int i; // Variable for loop iteration
    // Loop through the array from index 0 to the length of the array
    for(i = 0; i < arr->length; i++)
    {
        // Check if the current element matches the key
        if(key == arr->A[i])
        {
            // Swap the found element with the first element (for efficiency in future searches)
            swap(&arr->A[i], &arr->A[0]);
            return i; // Return the index where the key was found
        }
    }
    return -1; // Return -1 if the key is not found in the array
}

// Main function where execution starts
int main()
{
    // Initialize an instance of the Array structure with values and properties
    struct Array arr1 = {{2, 23, 14, 5, 6, 9, 8, 12}, 10, 8}; 
    // Array: {2, 23, 14, 5, 6, 9, 8, 12}, size: 10, length: 8

    // Call LinearSearch to search for the key '14' and print the index where it's found
    printf("%d", LinearSearch(&arr1, 14)); // It will print the index

    // Call the Display function to show the updated array
    Display(arr1); 

    return 0; // Return 0 to indicate successful execution
}
