#include <iostream>  // Including the standard input-output stream for using cout and cin
using namespace std;  // Using the standard namespace to avoid writing 'std::' repeatedly

// Class to represent a diagonal matrix
class Diagonal
{
private:
    int *A;  // Pointer to dynamically allocate an array to store diagonal elements
    int n;  // Dimension of the matrix (n x n)

public:
    // Default constructor initializes a 2x2 matrix
    Diagonal()
    {
        n = 2;  // Default dimension is set to 2
        A = new int[2];  // Dynamically allocating memory for 2 elements (diagonal elements)
    }

    // Parametrized constructor to initialize the matrix with custom size
    Diagonal(int n)
    {
        this->n = n;  // Set the matrix dimension
        A = new int[n];  // Dynamically allocating memory for n elements to store diagonal
    }

    // Destructor to release the dynamically allocated memory when the object is destroyed
    ~Diagonal()
    {
        delete[] A;  // Free the memory allocated for the diagonal elements
    }

    // Function to set a value at position (i, j) in the matrix
    void Set(int i, int j, int x);

    // Function to get a value at position (i, j) in the matrix
    int Get(int i, int j);

    // Function to display the matrix
    void Display();

    // Function to return the dimension of the matrix
    int GetDimension() { return n; }
};

// Member function definition for setting a diagonal element in the matrix
void Diagonal::Set(int i, int j, int x)
{
    // Only set the element if it's on the diagonal (i == j)
    if (i == j)
        A[i - 1] = x;  // Store the element at index i-1 (since array index starts at 0)
}

// Member function definition for retrieving an element from the matrix
int Diagonal::Get(int i, int j)
{
    // If the element is on the diagonal (i == j), return the stored value
    if (i == j)
        return A[i - 1];  // Return the diagonal element at index i-1
    return 0;  // For non-diagonal elements, return 0
}

// Member function definition for displaying the matrix
void Diagonal::Display()
{
    // Iterate over rows of the matrix
    for (int i = 1; i <= n; i++)
    {
        // Iterate over columns of the matrix
        for (int j = 1; j <= n; j++)
        {
            // Print the diagonal element if i == j, otherwise print 0
            if (i == j)
                cout << A[i - 1] << " ";  // Print diagonal element
            else
                cout << "0 ";  // Print 0 for non-diagonal elements
        }
        cout << endl;  // New line after each row
    }
}

// Main function to demonstrate the diagonal matrix class
int main()
{
    int d;  // Variable to hold matrix dimensions

    // Asking the user to input the matrix dimension
    cout << "Enter Dimensions: ";
    cin >> d;  // Reading the dimension of the matrix

    // Creating an object of the Diagonal class with the specified dimension
    Diagonal dm(d);

    int x;  // Variable to store matrix elements

    // Prompt the user to enter all elements of the matrix
    cout << "Enter All Elements: ";
    for (int i = 1; i <= d; i++)  // Loop through rows
    {
        for (int j = 1; j <= d; j++)  // Loop through columns
        {
            cin >> x;  // Read the element
            dm.Set(i, j, x);  // Set the element in the matrix, only the diagonal elements will be stored
        }
    }

    // Display the diagonal matrix
    dm.Display();

    return 0;  // Return 0 to indicate successful program termination
}
