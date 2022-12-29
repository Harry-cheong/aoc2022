#include <iostream>
#include <vector>

using namespace std;

// Generating a triple
// Euclid's formula 
// a = m**2 - n**2, b = 2mn, c = m^2 + n^2

int pythagoreanTriplets()
{
    // triplet: a^2 + b^2 = c^2
    int a, b, c = 0;

    // loop from 2 to max_limit
    int m = 2;
    while (true)
    {
        // now loop on j from 1 to i-1
        for (int n = 1; n < m; ++n)
        {
            // Evaluate and print triplets using
            // the relation between a, b and c
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;

            if (a + b + c == 1000) {
                return a * b * c;
            }
        }
        m++;
    }
}

// Driver code
int main()
{

    cout << pythagoreanTriplets() << endl; // Answer: 31875000

    return 0; 
}