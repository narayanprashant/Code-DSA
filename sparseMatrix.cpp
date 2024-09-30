#include <iostream>  // Including the input-output stream library
using namespace std;  // Using the standard namespace to avoid using 'std::' repeatedly

// Class to represent a non-zero element in a sparse matrix
class Element
{
public:
    int i;  // Row index of the element
    int j;  // Column index of the element
    int x;  // Value of the non-zero element
};

// Class to represent a sparse matrix using its non-zero elements
class Sparse
{
private:
    int m;  // Number of rows in the sparse matrix
    int n;  // Number of columns in the sparse matrix
    int num;  // Number of non-zero elements in the matrix
    Element *ele;  // Pointer to an array of non-zero elements (of class `Element`)

public:
    // Constructor to initialize the sparse matrix with rows, columns, and number of non-zero elements
    Sparse(int m, int n, int num)
    {
        this->m = m;  // Set number of rows
        this->n = n;  // Set number of columns
        this->num = num;  // Set number of non-zero elements
        ele = new Element[this->num];  // Dynamically allocate memory for non-zero elements
    }

    // Destructor to release the dynamically allocated memory
    ~Sparse()
    {
        delete[] ele;  // Free the memory allocated for non-zero elements
    }

    // Operator overloading function to add two sparse matrices
    Sparse operator+(Sparse &s);

    // Friend function to overload the input stream operator to read a sparse matrix
    friend istream & operator>>(istream &is, Sparse &s);

    // Friend function to overload the output stream operator to display a sparse matrix
    friend ostream & operator<<(ostream &os, Sparse &s);
};

// Overloading the '+' operator to add two sparse matrices
Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;  // Indices for iterating through the non-zero elements

    // Check if the two matrices have the same dimensions
    if (m != s.m || n != s.n)
        return Sparse(0, 0, 0);  // Return an empty matrix if the dimensions don't match

    // Create a new sparse matrix to store the result of the sum
    Sparse *sum = new Sparse(m, n, num + s.num);  // Sum will have at most `num + s.num` non-zero elements
    i = j = k = 0;  // Initialize indices to 0

    // Traverse through both matrices and add their elements
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)  // Compare row indices, and if element in the first matrix comes first
            sum->ele[k++] = ele[i++];  // Add the element from the first matrix to the result
        else if (ele[i].i > s.ele[j].i)  // If the element in the second matrix comes first
            sum->ele[k++] = s.ele[j++];  // Add the element from the second matrix to the result
        else  // If both elements are in the same row
        {
            if (ele[i].j < s.ele[j].j)  // Compare column indices
                sum->ele[k++] = ele[i++];  // Add the element from the first matrix to the result
            else if (ele[i].j > s.ele[j].j)  // If the second matrix's element has a smaller column index
                sum->ele[k++] = s.ele[j++];  // Add the element from the second matrix
            else  // If both elements are in the same position (same row and column)
            {
                sum->ele[k] = ele[i];  // Add the element from the first matrix
                sum->ele[k++].x = ele[i++].x + s.ele[j++].x;  // Sum the values of the two elements
            }
        }
    }

    // If there are remaining elements in the first matrix, add them to the result
    for (; i < num; i++) sum->ele[k++] = ele[i];

    // If there are remaining elements in the second matrix, add them to the result
    for (; j < s.num; j++) sum->ele[k++] = s.ele[j];

    // Update the number of non-zero elements in the result matrix
    sum->num = k;
    return *sum;  // Return the result matrix
}

// Overloading the '>>' operator to input a sparse matrix
istream & operator>>(istream &is, Sparse &s)
{
    cout << "Enter non-zero elements: ";  // Prompt the user to enter non-zero elements
    for (int i = 0; i < s.num; i++)  // Loop through all non-zero elements
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;  // Input row, column, and value for each element
    return is;  // Return the input stream
}

// Overloading the '<<' operator to output a sparse matrix
ostream & operator<<(ostream &os, Sparse &s)
{
    int k = 0;  // Initialize the index to iterate through non-zero elements
    for (int i = 0; i < s.m; i++)  // Loop through each row
    {
        for (int j = 0; j < s.n; j++)  // Loop through each column
        {
            // If the current position matches the row and column of a non-zero element
            if (s.ele[k].i == i && s.ele[k].j == j)
                cout << s.ele[k++].x << " ";  // Output the non-zero element
            else
                cout << "0 ";  // Output 0 for positions with no non-zero element
        }
        cout << endl;  // Move to the next line after each row
    }
    return os;  // Return the output stream
}

// Main function to demonstrate sparse matrix addition
int main()
{
    Sparse s1(5, 5, 5);  // Create a 5x5 sparse matrix with 5 non-zero elements
    Sparse s2(5, 5, 5);  // Create another 5x5 sparse matrix with 5 non-zero elements

    // Input the non-zero elements for both matrices
    cin >> s1;
    cin >> s2;

    // Add the two sparse matrices and store the result in 'sum'
    Sparse sum = s1 + s2;

    // Display the first matrix
    cout << "First Matrix" << endl << s1;

    // Display the second matrix
    cout << "Second Matrix" << endl << s2;

    // Display the result (sum of the two matrices)
    cout << "Sum Matrix" << endl << sum;

    return 0;  // Return 0 to indicate successful program termination
}
