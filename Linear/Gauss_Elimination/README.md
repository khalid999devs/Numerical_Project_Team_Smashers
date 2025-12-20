# Gauss Elimination Method

## Gauss Elimination Theory

Gauss Elimination is a numerical technique used to solve a system of linear equations by systematically eliminating variables to transform the system into an upper triangular form.

**Key Concepts:**

- Transforms augmented matrix into upper triangular form
- Uses elementary row operations
- Two main stages: forward elimination and back substitution
- Suitable for systems with unique solutions

**Algorithm Steps:**

1. Form the augmented matrix [A|B] from the system of equations
2. Forward Elimination: For each pivot element
   - Make all elements below the pivot zero using row operations
   - Calculate ratio = a[j][i] / a[i][i]
   - Perform row operation: row[j] = row[j] - ratio × row[i]
3. Back Substitution: Starting from last equation
   - Calculate x[n-1] directly from last row
   - Substitute known values to find remaining variables working upward
   - Calculate each x[i] = (a[i][n] - sum) / a[i][i]

**Advantages:**

- Simple implementation and forms the foundation of advanced numerical methods
- Efficient for small to medium systems with reliable convergence

**Disadvantages:**

- Computationally expensive for large systems and sensitive to round-off errors
- May fail if pivot elements become zero during elimination

## Gauss Elimination Code

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

        double a[n][n + 1], x[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double ratio = a[j][i] / a[i][i];
                for (int k = 0; k <= n; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }

        x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= a[i][j] * x[j];
            }
            x[i] /= a[i][i];
        }


        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++)
            {
            fout << "Value of x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}

```

## Gauss Elimination Input

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
4
1 1 1 1 10
2 -1 3 -2 5
3 1 -1 2 7
4 -2 1 1 6
2
3 2 7
4 -1 5

```

## Gauss Elimination Output

```
Test Case 1:
Value of x1 = 2
Value of x2 = 3
Test Case 2:
Value of x1 = 2
Value of x2 = 3
Value of x3 = -1
Test Case 3:
Value of x1 = 1
Value of x2 = 2
Value of x3 = 3
Test Case 4:
Value of x1 = 1
Value of x2 = 2
Value of x3 = 3
Value of x4 = 4
Test Case 5:
Value of x1 = 1
Value of x2 = 1
```
