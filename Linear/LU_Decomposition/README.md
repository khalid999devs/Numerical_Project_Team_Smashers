# LU Decomposition Method

## LU Decomposition Theory

LU Decomposition is a numerical method used to solve systems of linear equations efficiently. It involves breaking a square matrix into two matrices: a lower triangular matrix and an upper triangular matrix. The lower triangular matrix contains elements below the main diagonal, while the upper triangular matrix contains elements on and above the main diagonal. Once the decomposition is done, the system is solved in two steps: first solving the lower triangular system to get an intermediate vector, then solving the upper triangular system to find the final solution. This method reduces computation time and is particularly useful when the same matrix is used with different right-hand side vectors. It is widely applied in engineering, computer simulations, and numerical analysis.

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
