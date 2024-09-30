#include<stdio.h>

// Define a structure 'Array' which represents an array along with its size and length.
struct Array
{
    int A[10];    // Array 'A' can hold up to 10 integers.
    int size;     // 'size' indicates the maximum size of the array.
    int length;   // 'length' represents the number of elements actually stored in the array.
};

// Function to display the elements of the array.
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    
    // Loop through each element of the array and print it.
    for(i=0; i<arr.length; i++)
        printf("%d ", arr.A[i]);  // Print each element of array 'A'.
}

// Utility function to swap two integer values.
void swap(int *x, int *y)
{
    int temp = *x; // Store the value of 'x' in a temporary variable.
    *x = *y;       // Assign the value of 'y' to 'x'.
    *y = temp;     // Assign the value of 'temp' (original 'x') to 'y'.
}

// Function to get the value at a given index in the array.
int Get(struct Array arr, int index)
{
    // Check if the index is within the valid range (0 to length-1).
    if (index >= 0 && index < arr.length)
        return arr.A[index];  // Return the element at the specified index.
    
    return -1;  // If the index is out of bounds, return -1.
}

// Function to set/replace the value at a given index in the array.
void Set(struct Array *arr, int index, int x)
{
    // Check if the index is valid.
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;  // Set the element at 'index' to the value 'x'.
}

// Function to find and return the maximum value in the array.
int Max(struct Array arr)
{
    int max = arr.A[0];  // Initialize 'max' to the first element of the array.
    int i;
    
    // Loop through the array to find the maximum value.
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];  // Update 'max' if a larger value is found.
    }
    
    return max;  // Return the maximum value found.
}

// Function to find and return the minimum value in the array.
int Min(struct Array arr)
{
    int min = arr.A[0];  // Initialize 'min' to the first element of the array.
    int i;
    
    // Loop through the array to find the minimum value.
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];  // Update 'min' if a smaller value is found.
    }
    
    return min;  // Return the minimum value found.
}

// Function to calculate and return the sum of all elements in the array.
int Sum(struct Array arr)
{
    int s = 0;  // Initialize sum to 0.
    int i;
    
    // Loop through the array and add each element to 's'.
    for (i = 0; i < arr.length; i++)
        s += arr.A[i];  // Accumulate the sum of elements.
    
    return s;  // Return the total sum.
}

// Function to calculate and return the average of all elements in the array.
float Avg(struct Array arr)
{
    // Return the average by dividing the sum of elements by the length of the array.
    return (float)Sum(arr) / arr.length;
}

int main()
{
    // Initialize an array 'arr1' with 9 elements, a size of 10, and length 9.
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};
    
    // Print the sum of all elements in 'arr1'.
    printf("%d", Sum(arr1));
    
    // Call the 'Display' function to show the elements of the array.
    Display(arr1);
    
    return 0;
}
