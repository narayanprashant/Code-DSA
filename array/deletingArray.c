#include <stdio.h> // Include the standard input/output library for printf

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

// Function to delete an element at a specific index in the array
int Delete(struct Array *arr, int index) {
    int x = 0; // Variable to hold the value of the deleted element
    int i; // Declare an integer variable for loop iteration
    // Check if the index is valid for deletion
    if (index >= 0 && index < arr->length) {
        x = arr->A[index]; // Store the value of the element to be deleted
        // Shift elements to the left to fill the gap left by the deleted element
        for (i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1]; // Move elements one position to the left
        arr->length--; // Decrement the length of the array to reflect the deletion
        return x; // Return the value of the deleted element
    }
    return 0; // Return 0 if the index is invalid
}

int main() {
    // Initialize an instance of the Array structure with some elements
    struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5}; // Elements, size, and length

    // Call the Delete function to remove the element at index 0 and print its value
    printf("%d", Delete(&arr1, 0)); 

    // Display the contents of the array after deletion
    Display(arr1); 

    return 0; // Return 0 to indicate successful execution
}
