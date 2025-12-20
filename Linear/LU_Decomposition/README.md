# LU Decomposition Method

## LU Decomposition Theory

LU Decomposition is a numerical method that breaks a square matrix into the product of a lower triangular matrix (L) and an upper triangular matrix (U) to efficiently solve systems of linear equations.

**Key Concepts:**

- Decomposes matrix A into A = L × U
- L is lower triangular (elements below diagonal)
- U is upper triangular (elements on and above diagonal)
- Solves system in two stages: Ly = b, then Ux = y
- Particularly efficient for multiple systems with same coefficient matrix

**Algorithm Steps:**

1. Initialize L as identity matrix and U as zero matrix
2. Decomposition Process:
   - For each row i:
     - Calculate U[i][j] for j >= i using: U[i][j] = A[i][j] - sum(L[i][k] × U[k][j])
     - Calculate L[j][i] for j > i using: L[j][i] = (A[j][i] - sum(L[j][k] × U[k][i])) / U[i][i]
     - Set L[i][i] = 1
3. Forward Substitution: Solve Ly = b for y
   - y[i] = (b[i] - sum(L[i][j] × y[j])) / L[i][i]
4. Back Substitution: Solve Ux = y for x
   - x[i] = (y[i] - sum(U[i][j] × x[j])) / U[i][i]

**Advantages:**

- Very efficient when solving multiple systems with same coefficient matrix
- Decomposition can be reused reducing computational complexity for repeated solutions

**Disadvantages:**

- Requires square non-singular matrix and may fail if pivot elements are zero
- Not efficient for single system solution due to initial decomposition overhead

## LU Decomposition Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++) 
        {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<vector<double>> L(n, vector<double>(n, 0.0));
        vector<vector<double>> U(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                fin >> a[i][j];
            }
        }

        vector<double> b(n);
        for (int i = 0; i < n; i++) 
        {
            fin >> b[i];
        }

        for (int i = 0; i < n; i++) 
            {
            for (int k = i; k < n; k++) 
            {
                double sum = 0;
                for (int j = 0; j < i; j++) sum += L[i][j] * U[j][k];
                U[i][k] = a[i][k] - sum;
            }
            for (int k = i; k < n; k++) 
            {
                if (i == k) L[i][i] = 1;
                else {
                    double sum = 0;
                    for (int j = 0; j < i; j++) sum += L[k][j] * U[j][i];
                    L[k][i] = (a[k][i] - sum) / U[i][i];
                }
            }
        }

        vector<double> y(n);
        for (int i = 0; i < n; i++) 
        {
            double sum = 0;
            for (int j = 0; j < i; j++) sum += L[i][j] * y[j];
            y[i] = b[i] - sum;
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--) 
        {
            double sum = 0;
            for (int j = i + 1; j < n; j++) sum += U[i][j] * x[j];
            x[i] = (y[i] - sum) / U[i][i];
        }

        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++) {
            fout << "Value of x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}

```

## LU Decomposition Input

```
5
3
2 3 1
4 7 7
6 18 22
1 2 3
2
1 2
3 4
5 6
3
3 2 -1
2 -2 4
-1 0.5 -1
1 -2 0
4
1 2 3 4
2 5 2 1
3 2 6 3
4 1 3 8
10 5 12 15
2
4 3
6 3
10 12
3
2 -1 1
3 3 9
3 3 5
8 0 -6

```

## LU Decomposition Output

```
Test Case 1:
Value of x1 = 0.5
Value of x2 = 0
Value of x3 = 0
Test Case 2:
Value of x1 = -4
Value of x2 = 4.5
Test Case 3:
Value of x1 = 1
Value of x2 = -2
Value of x3 = -2
Test Case 4:
Value of x1 = -0.181818
Value of x2 = 0.272727
Value of x3 = 1.27273
Value of x4 = 1.45455
Test Case 5:
Value of x1 = 1
Value of x2 = 2

```
