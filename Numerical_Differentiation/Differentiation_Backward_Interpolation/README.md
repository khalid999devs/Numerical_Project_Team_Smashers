# Differentiation Using Backward Interpolation

## Differentiation Using Backward Interpolation Theory

Backward interpolation differentiation is a numerical method used to approximate derivatives when function values are available at equally spaced points near the end of the data set.

**Key Concepts:**

- Uses backward difference table to calculate derivatives
- Suitable for points near the end of tabulated data
- Requires equally spaced data points
- Based on finite difference approximation using backward differences

**Algorithm Steps:**

1. Verify data points are equally spaced with step size h
2. Construct backward difference table:
   - Calculate successive backward differences: ∇^k f
   - Build difference table up to required order
3. Apply backward differentiation formulas:
   - First derivative: f'(xn) = (∇fn + ∇²fn/2 + ∇³fn/3 + ...) / h
   - Higher derivatives use corresponding backward formulas
4. Calculate derivative at desired point using appropriate formula
5. Use sufficient terms for required accuracy

**Advantages:**

- Excellent for derivatives near end of data set without explicit function formula
- Systematic approach using backward differences 

**Disadvantages:**

- Limited to equally spaced data and accuracy decreases with higher order derivatives
- Backward differences may amplify errors and sensitive to data noise

## Differentiation Using Backward Interpolation Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout << fixed << setprecision(6);

    int t;
    fin>>t;

    for (int i = 1; i <= t; i++)
    {
        fout << "Test case #" << i << ":\n";
        int n;
        fin >> n;

        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) fin >> x[i];
        for (int i = 0; i < n; i++) fin >> y[i];

        vector<vector<double>> diff(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++)
            diff[i][0] = y[i];

        for (int j = 1; j < n; j++)
        {
            for (int i = n - 1; i >= j; i--)
            {
                diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
            }
        }

        double h = x[1] - x[0];

        double first_derivative = 0.0;
        for (int i = 1; i < n; i++)
        {
            first_derivative += diff[n - 1][i] / i;
        }
        first_derivative /= h;

        double second_derivative = 0.0;
        if (n >= 3)
        {
            second_derivative = diff[n - 1][2];
            if (n >= 4) second_derivative += diff[n - 1][3];
            if (n >= 5) second_derivative += (11.0 / 12.0) * diff[n - 1][4];
            second_derivative /= (h * h);
        }

        fout << "First derivative at x = " << x[n - 1] << " : " << first_derivative << "\n";
        fout << "Second derivative at x = " << x[n - 1] << " : " << second_derivative << "\n\n";
    }

    return 0;
}

```

## Differentiation Using Backward Interpolation Input

```
4
4
0 1 2 3
1 3 7 13
5
1 2 3 4 5
1 8 27 64 125
4
10 20 30 40
5 9 15 23
4
2 4 6 8
4 16 36 64

```

## Differentiation Using Backward Interpolation Output

```
Test case #1:
First derivative at x = 3.000000 : 7.000000
Second derivative at x = 3.000000 : 2.000000

Test case #2:
First derivative at x = 5.000000 : 75.000000
Second derivative at x = 5.000000 : 30.000000

Test case #3:
First derivative at x = 40.000000 : 0.900000
Second derivative at x = 40.000000 : 0.020000

Test case #4:
First derivative at x = 8.000000 : 16.000000
Second derivative at x = 8.000000 : 2.000000


```
