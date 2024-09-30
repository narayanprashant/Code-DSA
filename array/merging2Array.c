#include<stdio.h>
#include<stdlib.h>

// Define a structure 'Array' to represent an array along with its size and length
struct Array
{
    int A[10];   // Array 'A' can hold up to 10 integers
    int size;    // 'size' represents the maximum capacity of the array (in this case, 10)
    int length;  // 'length' indicates the actual number of elements present in the array
};

// Function to display the elements of the array
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");

    // Loop through the array 'A' and print each element
    for(i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);  // Print each element of the array
}

// Function to merge two sorted arrays into a new sorted array
struct Array* Merge(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;  // Initialize i, j, and k to 0 to track indices for arr1, arr2, and arr3 respectively

    // Dynamically allocate memory for the new array 'arr3'
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // Merge the arrays by comparing elements from both arr1 and arr2
    while(i < arr1->length && j < arr2->length)
    {
        // If the current element of arr1 is smaller, add it to arr3
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];  // Add arr1's element to arr3 and increment both i and k
        else
            arr3->A[k++] = arr2->A[j++];  // Otherwise, add arr2's element to arr3 and increment both j and k
    }

    // If any elements remain in arr1, add them to arr3
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];  // Add remaining elements of arr1 to arr3

    // If any elements remain in arr2, add them to arr3
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];  // Add remaining elements of arr2 to arr3

    // Set the length of arr3 to be the sum of arr1's and arr2's lengths
    arr3->length = arr1->length + arr2->length;

    // Set the size of arr3 (in this case, 10, since we're working with arrays of size 10)
    arr3->size = 10;

    // Return the pointer to the newly merged array
    return arr3;
}

int main()
{
    // Initialize two sorted arrays 'arr1' and 'arr2' with 5 elements each
    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};  // arr1 contains elements {2, 9, 21, 28, 35}
    struct Array arr2 = {{2, 3, 16, 18, 28}, 10, 5};  // arr2 contains elements {2, 3, 16, 18, 28}

    // Declare a pointer 'arr3' to hold the merged array
    struct Array *arr3;

    // Call the Merge function to merge arr1 and arr2, and store the result in arr3
    arr3 = Merge(&arr1, &arr2);

    // Display the merged array
    Display(*arr3);

    return 0;  // End of the program
}
