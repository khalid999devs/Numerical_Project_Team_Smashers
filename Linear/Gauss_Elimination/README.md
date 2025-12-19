# Gauss Elimination Method

## Gauss Elimination Theory

Gauss Elimination is a numerical technique used to solve a system of linear equations. The method works by systematically eliminating variables to transform the given system into an upper triangular form, where each equation contains fewer unknowns than the previous one. This simplification makes the system easy to solve.The process is carried out in two main stages. In the first stage, called forward elimination, elementary row operations are applied to eliminate the coefficients of variables below the main diagonal. In the second stage, known as back substitution, the values of the unknowns are determined starting from the last equation and moving upward.Gauss Elimination is widely used because it is simple, efficient for small to medium-sized systems, and forms the basis of many advanced numerical methods. It is commonly applied in engineering and scientific computations where systems of linear equations arise.

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
Value of x1 = 2
Value of x2 = 3
Value of x3 = 2
Test Case 4:
Value of x1 = 0.844444
Value of x2 = 2.17778
Value of x3 = 3.88889
Value of x4 = 3.08889
Test Case 5:
Value of x1 = 1.54545
Value of x2 = 1.18182

```
