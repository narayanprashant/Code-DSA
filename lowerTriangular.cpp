#include <iostream>  // Including the standard input-output stream library
using namespace std;  // Using the standard namespace to avoid using 'std::' repeatedly

// Class to represent a Lower Triangular Matrix
class LowerTri
{
private:
    int *A;  // Pointer to dynamically allocate an array for storing lower triangular elements
    int n;   // Dimension of the matrix (n x n)

public:
    // Default constructor to initialize a 2x2 matrix
    LowerTri()
    {
        n = 2;  // Set matrix dimension to 2
        A = new int[2 * (2 + 1) / 2];  // Allocate memory for lower triangular elements (size 3 for 2x2 matrix)
    }

    // Parametrized constructor to initialize matrix with custom dimension
    LowerTri(int n)
    {
        this->n = n;  // Set matrix dimension to n
        A = new int[n * (n + 1) / 2];  // Allocate memory for lower triangular elements (size n*(n+1)/2)
    }

    // Destructor to release dynamically allocated memory
    ~LowerTri()
    {
        delete[] A;  // Free the memory allocated for the lower triangular elements
    }

    // Function to set an element at position (i, j) in the matrix
    void Set(int i, int j, int x);

    // Function to get an element at position (i, j) in the matrix
    int Get(int i, int j);

    // Function to display the matrix
    void Display();

    // Function to return the dimension of the matrix
    int GetDimension() { return n; }
};

// Member function to set an element at position (i, j) in the lower triangular matrix
void LowerTri::Set(int i, int j, int x)
{
    // Only set the element if it's in the lower triangle (i >= j)
    if (i >= j)
        A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] = x;  // Store the element using the compact storage formula
}

// Member function to get an element at position (i, j) in the lower triangular matrix
int LowerTri::Get(int i, int j)
{
    // If the element is in the lower triangle (i >= j), return the value
    if (i >= j)
        return A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j];  // Retrieve the element using the compact storage formula
    return 0;  // If it's not a lower triangular element, return 0
}

// Member function to display the full n x n matrix
void LowerTri::Display()
{
    // Loop through each row
    for (int i = 1; i <= n; i++)
    {
        // Loop through each column
        for (int j = 1; j <= n; j++)
        {
            // If the element is in the lower triangle, display it
            if (i >= j)
                cout << A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j] << " ";
            else
                // Otherwise, display 0 for upper triangular elements
                cout << "0 ";
        }
        cout << endl;  // Move to the next line after each row
    }
}

// Main function to demonstrate the lower triangular matrix
int main()
{
    int d;  // Variable to hold matrix dimensions

    // Asking the user to input the matrix dimension
    cout << "Enter Dimensions: ";
    cin >> d;  // Reading the dimension of the matrix

    // Creating an object of the LowerTri class with the specified dimension
    LowerTri lm(d);

    int x;  // Variable to store matrix elements

    // Prompt the user to enter all elements of the matrix
    cout << "Enter All Elements: ";
    for (int i = 1; i <= d; i++)  // Loop through rows
    {
        for (int j = 1; j <= d; j++)  // Loop through columns
        {
            cin >> x;  // Read the element
            lm.Set(i, j, x);  // Set the element in the matrix (only lower triangular elements will be stored)
        }
    }

    // Display the lower triangular matrix
    lm.Display();

    return 0;  // Return 0 to indicate successful program termination
}
