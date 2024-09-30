#include <iostream>
using namespace std;

// Template class definition for an array that can store elements of any data type.
template<class T>
class Array
{
private:
    T *A;  // Pointer to dynamically allocated array of type T
    int size;  // The total size of the array
    int length;  // The number of elements in the array (logical size)

public:
    // Default constructor to initialize the array with size 10
    Array()
    {
        size = 10;  // Default size is set to 10
        A = new T[10];  // Dynamically allocating an array of size 10
        length = 0;  // Initializing the length (number of elements) to 0
    }

    // Parametrized constructor to initialize the array with a custom size
    Array(int sz)
    {
        size = sz;  // Size is set to the value passed by the user
        length = 0;  // Initially, the array has no elements
        A = new T[size];  // Dynamically allocate an array of the given size
    }

    // Destructor to release the dynamically allocated memory when the object is destroyed
    ~Array()
    {
        delete []A;  // Freeing the memory allocated for the array
    }

    // Function to display the elements of the array
    void Display();

    // Function to insert an element at a given index
    void Insert(int index, T x);

    // Function to delete an element from a given index and return the deleted element
    T Delete(int index);
};

// Template function definition for displaying the array
template<class T>
void Array<T>::Display()
{
    // Loop through the array and print each element up to 'length'
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";  // Print each element followed by a space
    cout << endl;  // Print a new line after displaying the array
}

// Template function definition for inserting an element at a given index
template<class T>
void Array<T>::Insert(int index, T x)
{
    // Check if the index is valid (it should be between 0 and the current length)
    if (index >= 0 && index <= length)
    {
        // Shift elements to the right to make space for the new element
        for (int i = length - 1; i >= index; i--)
            A[i + 1] = A[i];  // Move each element one position to the right

        A[index] = x;  // Insert the new element at the specified index
        length++;  // Increment the logical length of the array
    }
}

// Template function definition for deleting an element at a given index
template<class T>
T Array<T>::Delete(int index)
{
    T x = 0;  // Initialize a variable to store the deleted element (0 is a default value)
    
    // Check if the index is valid (it should be within the range of the current length)
    if (index >= 0 && index < length)
    {
        x = A[index];  // Store the element to be deleted
        
        // Shift elements to the left to fill the gap created by the deletion
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];  // Move each element one position to the left

        length--;  // Decrease the logical length of the array
    }
    
    return x;  // Return the deleted element
}

// Main function to demonstrate the use of the Array class
int main()
{
    // Create an instance of Array class with char type and size 10
    Array<char> arr(10);

    // Insert 'a' at index 0
    arr.Insert(0, 'a');

    // Insert 'c' at index 1
    arr.Insert(1, 'c');

    // Insert 'd' at index 2
    arr.Insert(2, 'd');

    // Display the array after inserting three elements: a c d
    arr.Display();

    // Delete the element at index 0 ('a') and display the deleted element
    cout << arr.Delete(0) << endl;  // Output will be 'a'

    // Display the array after deletion: c d
    arr.Display();

    return 0;
}
