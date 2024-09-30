#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a term in the polynomial.
// A term consists of a coefficient (coeff) and an exponent (exp).
struct Term
{
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
};

// Define a structure to represent a polynomial.
// A polynomial consists of 'n' terms and a pointer to an array of terms.
struct Poly
{
    int n;              // Number of terms in the polynomial
    struct Term *terms; // Pointer to an array of terms
};

// Function to create a polynomial by inputting its terms.
void create(struct Poly *p)
{
    int i;
    printf("Number of terms? ");
    // Read the number of terms in the polynomial from the user
    scanf("%d", &p->n);
    
    // Allocate memory for the terms based on the number of terms
    p->terms = (struct Term*)malloc(p->n * sizeof(struct Term));

    printf("Enter terms (coeff and exp)\n");
    // Input the coefficient and exponent for each term from the user
    for (i = 0; i < p->n; i++)
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
}

// Function to display a polynomial in a readable format
void display(struct Poly p)
{
    int i;
    // Loop through each term in the polynomial and display it
    for (i = 0; i < p.n; i++)
        // Print the term as coeff*x^exp
        printf("%dx^%d + ", p.terms[i].coeff, p.terms[i].exp);
    printf("\n"); // Move to the next line after printing the polynomial
}

// Function to add two polynomials and return the result as a new polynomial
struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    struct Poly *sum;

    // Allocate memory for the resulting polynomial (sum)
    // The sum polynomial will have at most p1->n + p2->n terms
    sum = (struct Poly*)malloc(sizeof(struct Poly));
    sum->terms = (struct Term*)malloc((p1->n + p2->n) * sizeof(struct Term));

    i = j = k = 0; // Initialize indices for p1, p2, and sum

    // Loop to add terms of both polynomials based on the exponent
    while (i < p1->n && j < p2->n)
    {
        // If the exponent of the term in p1 is greater than the term in p2
        if (p1->terms[i].exp > p2->terms[j].exp)
            sum->terms[k++] = p1->terms[i++]; // Copy the term from p1 to sum
        // If the exponent of the term in p2 is greater than the term in p1
        else if (p1->terms[i].exp < p2->terms[j].exp)
            sum->terms[k++] = p2->terms[j++]; // Copy the term from p2 to sum
        else
        {
            // If the exponents are equal, add the coefficients
            sum->terms[k].exp = p1->terms[i].exp; // Set the common exponent
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff; // Add the coefficients and store
        }
    }

    // Copy remaining terms from p1 if any
    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];

    // Copy remaining terms from p2 if any
    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    // Update the number of terms in the sum polynomial
    sum->n = k;
    return sum; // Return the resulting sum polynomial
}

int main()
{
    struct Poly p1, p2, *p3;

    // Create two polynomials p1 and p2
    create(&p1);
    create(&p2);

    // Add p1 and p2, and store the result in p3
    p3 = add(&p1, &p2);

    // Display the polynomials
    printf("\nPolynomial 1: ");
    display(p1);
    printf("\nPolynomial 2: ");
    display(p2);
    printf("\nSum of Polynomial 1 and Polynomial 2: ");
    display(*p3);

    return 0;
}
