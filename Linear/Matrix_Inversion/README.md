# Matrix Inversion Method

## Matrix Inversion Theory

Matrix Inversion is a method used to find the inverse of a square matrix, which when multiplied with the original matrix produces the identity matrix.

**Key Concepts:**

- Only square and non-singular matrices can be inverted
- A × A^(-1) = I (identity matrix)
- If determinant is zero, matrix is singular and has no inverse
- Useful for solving systems of equations: x = A^(-1) × b

**Algorithm Steps:**

1. Start with augmented matrix [A | I] where I is identity matrix
2. Apply Gauss-Jordan elimination:
   - For each pivot row i:
     - Divide row i by pivot element to make a[i][i] = 1
     - Eliminate all other elements in column i (make them zero)
     - Apply same operations to both sides of augmented matrix
3. When left side becomes identity matrix, right side becomes A^(-1)
4. Check for singularity (if pivot becomes zero, matrix is singular)

**Advantages:**

- Provides direct solution for systems of equations 
- Once computed, can be reused for multiple problems with same coefficient matrix

**Disadvantages:**

- Computationally expensive O(n^3) operations 
- Not efficient for single system solution 

## Matrix Inversion Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++)
        {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<vector<double>> inv(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
            inv[i][i] = 1.0;
        }

        bool singular = false;

        for (int i = 0; i < n; i++)
            {
            if (fabs(a[i][i]) < 1e-9)
            {
                singular = true;
                break;
            }

            double pivot = a[i][i];
            for (int j = 0; j < n; j++)
            {
                a[i][j] /= pivot;
                inv[i][j] /= pivot;
            }

            for (int j = 0; j < n; j++)
                {
                if (j != i) {
                    double ratio = a[j][i];
                    for (int k = 0; k < n; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                        inv[j][k] -= ratio * inv[i][k];
                    }
                }
            }
        }

        fout << "Test Case " << i << ":\n";
        if (singular) {
            fout << "Matrix is singular and cannot be inverted.\n";
        } else {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fout << fixed << setprecision(6) << inv[i][j] << " ";
                }
                fout << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}

```

## Matrix Inversion Input

```
5
3
2 1 1
1 3 2
1 0 0
3
4 7 2
3 6 1
2 5 1
4
1 2 3 4
5 6 7 8
2 6 4 8
3 1 1 2
4
2 0 1 3
1 1 0 2
3 2 2 1
4 1 3 2
3
3 0 2
2 0 -2
0 1 1

```

## Matrix Inversion Output

```
Test Case 1:
0.000000 0.000000 1.000000
-2.000000 1.000000 3.000000
3.000000 -1.000000 -5.000000
Test Case 2:
0.333333 1.000000 -1.666667
-0.333333 0.000000 0.666667
1.000000 -2.000000 1.000000
Test Case 3:
-0.166667 0.055556 -0.055556 0.333333
-0.833333 0.277778 0.222222 -0.333333
0.166667 0.277778 -0.277778 -0.333333
0.583333 -0.361111 0.111111 0.333333
Test Case 4:
Matrix is singular and cannot be inverted.
Test Case 5:
Matrix is singular and cannot be inverted.

```
