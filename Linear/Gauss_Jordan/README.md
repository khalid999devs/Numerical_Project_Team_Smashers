# Gauss Jordan Elimination Method

## Gauss Jordan Theory

Gauss-Jordan Elimination is a numerical method used to solve a system of linear equations by transforming the augmented matrix into reduced row-echelon form (diagonal form).

**Key Concepts:**

- Transforms matrix into reduced row-echelon form (diagonal matrix)
- Eliminates variables both below and above the main diagonal
- Each pivot element is made equal to one

**Algorithm Steps:**

1. Form the augmented matrix [A|B] from the system
2. For each pivot element a[i][i]:
   - Divide the entire pivot row by a[i][i] to make pivot = 1
   - Eliminate all other elements in the pivot column (both above and below)
   - For each row j (where j ≠ i):
     - Calculate ratio = a[j][i]
     - Perform row[j] = row[j] - ratio × row[i]
3. After complete elimination, read solution directly from last column

**Advantages:**

- No back substitution required with solution directly readable from matrix
- Straightforward systematic approach useful for finding matrix inverses

**Disadvantages:**

- Requires more computations than Gauss Elimination 
- Less efficient for large systems
  

## Gauss Jordan Code

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        fin >> n;

        double a[n][n + 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            double pivot = a[i][i];

            for (int j = 0; j <= n; j++)
            {
                a[i][j] /= pivot;
            }

            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    double ratio = a[j][i];
                    for (int k = 0; k <= n; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                    }
                }
            }
        }

        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++)
        {
            fout << "Value of x" << i + 1 << " = " << a[i][n] << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}

```

## Gauss Jordan Input

```
5
2
1 1 5
2 -1 1
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
3
1 2 3 14
2 -1 1 3
3 1 -2 5
2
3 2 7
4 -1 5
2
1 -2 4
3 1 5

```

## Gauss Jordan Output

```
Test Case 1:
Value of x1 = 2
Value of x2 = 3
Test Case 2:
Value of x1 = 2
Value of x2 = 3
Value of x3 = -1
Test Case 3:
Value of x1 = 2
Value of x2 = 3
Value of x3 = 2
Test Case 4:
Value of x1 = 1.54545
Value of x2 = 1.18182
Test Case 5:
Value of x1 = 2
Value of x2 = -1

```
