#include<stdio.h>
#include<stdlib.h>

// Define a structure 'Array' that holds an array of integers, its size, and the number of elements in it
struct Array
{
    int A[10];    // Static array of size 10
    int size;     // Maximum size of the array (capacity)
    int length;   // Actual number of elements currently stored in the array
};

// Function to display the elements of the array
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");

    // Loop through the array and print each element up to the 'length' of the array
    for(i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);  // Print each element followed by a space
}

// Function to perform the union of two sorted arrays
struct Array* Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;  // Initialize indices for arr1, arr2, and arr3

    // Dynamically allocate memory for a new array 'arr3' to store the result of the union
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // Traverse both arrays arr1 and arr2
    while(i < arr1->length && j < arr2->length)
    {
        // If the current element of arr1 is smaller, add it to arr3
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];  // Add arr1's element to arr3 and increment i and k
        // If the current element of arr2 is smaller, add it to arr3
        else if(arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];  // Add arr2's element to arr3 and increment j and k
        // If the elements are equal, add only one of them to arr3 and skip the duplicate
        else
        {
            arr3->A[k++] = arr1->A[i++];  // Add the element from arr1 (or arr2)
            j++;  // Skip the duplicate in arr2 by incrementing j
        }
    }

    // Copy any remaining elements from arr1 to arr3
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    // Copy any remaining elements from arr2 to arr3
    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    // Set the length of arr3 to the number of elements added
    arr3->length = k;
    arr3->size = 10;  // Set the size of arr3 (same as arr1 and arr2)

    return arr3;  // Return the pointer to the merged array (union of arr1 and arr2)
}

// Function to find the intersection of two sorted arrays
struct Array* Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;  // Initialize indices for arr1, arr2, and arr3

    // Dynamically allocate memory for a new array 'arr3' to store the result of the intersection
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // Traverse both arrays arr1 and arr2
    while(i < arr1->length && j < arr2->length)
    {
        // If arr1's element is smaller, skip it
        if(arr1->A[i] < arr2->A[j])
            i++;  // Increment i to move to the next element in arr1
        // If arr2's element is smaller, skip it
        else if(arr2->A[j] < arr1->A[i])
            j++;  // Increment j to move to the next element in arr2
        // If the elements are equal, add it to arr3 (intersection)
        else if(arr1->A[i] == arr2->A[j])
        {
            arr3->A[k++] = arr1->A[i++];  // Add the element to arr3 and increment i and j
            j++;
        }
    }

    // Set the length of arr3 to the number of elements added
    arr3->length = k;
    arr3->size = 10;  // Set the size of arr3 (same as arr1 and arr2)

    return arr3;  // Return the pointer to the array containing the intersection
}

// Function to find the difference between two sorted arrays (arr1 - arr2)
struct Array* Difference(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;  // Initialize indices for arr1, arr2, and arr3

    // Dynamically allocate memory for a new array 'arr3' to store the result of the difference
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    // Traverse both arrays arr1 and arr2
    while(i < arr1->length && j < arr2->length)
    {
        // If arr1's element is smaller, add it to arr3 (it's not in arr2)
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];  // Add arr1's element to arr3 and increment i and k
        // If arr2's element is smaller, skip it
        else if(arr2->A[j] < arr1->A[i])
            j++;  // Increment j to move to the next element in arr2
        // If elements are equal, skip both (they're common to both arrays)
        else
        {
            i++;  // Skip the element in arr1
            j++;  // Skip the element in arr2
        }
    }

    // Copy any remaining elements from arr1 to arr3 (those that weren't in arr2)
    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    // Set the length of arr3 to the number of elements added
    arr3->length = k;
    arr3->size = 10;  // Set the size of arr3 (same as arr1 and arr2)

    return arr3;  // Return the pointer to the array containing the difference (arr1 - arr2)
}

int main()
{
    // Initialize two sorted arrays arr1 and arr2
    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};  // arr1 contains elements {2, 9, 21, 28, 35}
    struct Array arr2 = {{2, 3, 9, 18, 28}, 10, 5};  // arr2 contains elements {2, 3, 9, 18, 28}

    // Declare a pointer to hold the result of the union of arr1 and arr2
    struct Array *arr3;

    // Perform the union of arr1 and arr2 and store the result in arr3
    arr3 = Union(&arr1, &arr2);

    // Display the result of the union
    Display(*arr3);

    return 0;  // End of program
}
