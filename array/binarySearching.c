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
    for(i = 0; i < arr.length; i++) // Loop through each element in the array
        printf("%d ", arr.A[i]);    // Print each element followed by a space
}

// Function to swap two integers using pointers
void swap(int *x, int *y)
{
    int temp = *x; // Store the value of *x in temp
    *x = *y;       // Assign the value of *y to *x
    *y = temp;     // Assign the value of temp to *y (original *x value)
}

// Function to perform an iterative binary search in the array for a given key
int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;               // Set the lower bound to the first index
    h = arr.length - 1;   // Set the upper bound to the last index of the array

    // Loop until lower bound is less than or equal to upper bound
    while(l <= h)
    {
        mid = (l + h) / 2; // Find the middle index of the current range
        if(key == arr.A[mid])  // If key is found at the middle, return the index
            return mid;
        else if(key < arr.A[mid])  // If key is less than the middle element
            h = mid - 1;  // Move the upper bound to the left half
        else              // If key is greater than the middle element
            l = mid + 1;  // Move the lower bound to the right half
    }
    return -1; // Return -1 if the key is not found in the array
}

// Function to perform recursive binary search for a key
int RBinSearch(int a[], int l, int h, int key)
{
    int mid = 0;
    if(l <= h)  // Check if the range is valid
    {
        mid = (l + h) / 2;  // Find the middle index
        if(key == a[mid])   // If key is found at the middle, return the index
            return mid;
        else if(key < a[mid])  // If key is less than the middle element
            return RBinSearch(a, l, mid - 1, key);  // Recurse on the left half
        else
            return RBinSearch(a, mid + 1, h, key);  // Recurse on the right half
    }
    return -1; // Return -1 if the key is not found
}

// Main function where execution starts
int main()
{
    // Initialize an instance of the Array structure with sorted elements and properties
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9}; 
    // Array: {2, 3, 9, 16, 18, 21, 28, 32, 35}, size: 10, length: 9

    // Call BinarySearch to search for the key '16' in the array and print the index
    printf("%d", BinarySearch(arr1, 16)); // It will print the index of the key if found

    // Call the Display function to show the elements of the array
    Display(arr1);

    return 0; // Return 0 to indicate successful execution
}
