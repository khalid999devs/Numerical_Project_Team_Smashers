# Polynomial Regression

## Polynomial Regression Theory

Polynomial regression is a curve fitting technique used when the relation is nonlinear. It uses a polynomial equation of higher degree for approximation.

**Key Concepts:**

- Based on Least Squares Method
- Fits data to a polynomial of degree m
- It is an extension of linear regression

**Algorithm Steps:**

- Assume a polynomial equation of required degree
- Form normal equations using sums of powers of x
- Convert equation into matrix
- Solve it using Gauss Elimination
- Determine polynomial coefficients
- Construct the fitted polynomial equation

**Advantages:**

- Model complex non-linear relation
- Provides accurate approximation within a given range

**Disadvantages:**

- Higher degree polynomial may cause overfitting
- Poor extrapolation outside data range with potential numerical instability

## Polynomial Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<double> solveGaussian(vector<vector<double>> A, vector<double> B) {
    int n = A.size();

    for (int i = 0; i < n; i++)
        A[i].push_back(B[i]);

    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];
        for (int j = 0; j <= n; j++)
            A[i][j] /= pivot;

        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = A[k][i];
            for (int j = 0; j <= n; j++)
                A[k][j] -= factor * A[i][j];
        }
    }

    vector<double> x(n);
    for (int i = 0; i < n; i++)
        x[i] = A[i][n];

    return x;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];

    vector<vector<double>> A(m + 1, vector<double>(m + 1, 0));
    vector<double> B(m + 1, 0);

    vector<double> S(2 * m + 1, 0);
    for (int i = 0; i < n; i++) {
        double xi = 1;
        for (int k = 0; k <= 2 * m; k++) {
            S[k] += xi;
            xi *= x[i];
        }
    }

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            A[i][j] = S[i + j];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++)
            B[i] += y[j] * pow(x[j], i);
    }

    vector<double> coeff = solveGaussian(A, B);

    fout << fixed << setprecision(6);
    fout << "Fitted Polynomial: y = ";
    for (int i = 0; i <= m; i++) {
        fout << coeff[i];
        if (i >= 1) fout << "x^" << i;
        if (i != m) fout << " + ";
    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}
```

## Polynomial Regression Input

```
5 2
1 1
2 4
3 9
4 16
5 25
```

## Polynomial Regression Output

```
Fitted Polynomial: y = 0.000000 + 0.000000x^1 + 1.000000x^2
```
