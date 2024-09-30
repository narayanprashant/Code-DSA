#include <stdio.h> // Include standard input/output library for printf

// Define a structure named Array to represent an array with additional properties
struct Array {
    int A[10];   // Array to hold a maximum of 10 integers
    int size;    // Maximum size of the array
    int length;  // Current number of elements in the array
};

// Function to display the elements of the array
void Display(struct Array arr) {
    int i; // Declare an integer variable for loop iteration
    printf("\nElements are\n"); // Print a header for the elements
    for (i = 0; i < arr.length; i++) // Loop through each element in the array
        printf("%d ", arr.A[i]); // Print each element followed by a space
}

// Function to append an element at the end of the array
void Append(struct Array *arr, int x) {
    // Check if there is space to add a new element
    if (arr->length < arr->size) 
        arr->A[arr->length++] = x; // Add the element and increment the length
}

// Function to insert an element at a specific index in the array
void Insert(struct Array *arr, int index, int x) {
    int i; // Declare an integer variable for loop iteration
    // Check if the index is valid for insertion
    if (index >= 0 && index <= arr->length) {
        // Shift elements to the right to create space for the new element
        for (i = arr->length; i > index; i--) 
            arr->A[i] = arr->A[i - 1]; // Move elements one position to the right
        arr->A[index] = x; // Insert the new element at the specified index
        arr->length++; // Increment the length of the array
    }
}

int main() {
    // Initialize an instance of the Array structure with some elements
    struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5}; // Elements, size, and length

    // Append the value 10 to the array
    Append(&arr1, 10); 

    // Insert the value 12 at index 0 (beginning) of the array
    Insert(&arr1, 0, 12); 

    // Display the contents of the array
    Display(arr1); 

    return 0; // Return 0 to indicate successful execution
}
