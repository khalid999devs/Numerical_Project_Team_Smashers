# Differentiation Using Forward Interpolation

## Differentiation Using Forward Interpolation Theory

Forward interpolation differentiation is a numerical method used to approximate derivatives when function values are available at equally spaced points near the beginning of the data set.

**Key Concepts:**

- Uses forward difference table to calculate derivatives
- Suitable for points near the beginning of tabulated data
- Requires equally spaced data points
- Approximates derivatives without explicit function formula
- Based on finite difference approximation of derivatives

**Algorithm Steps:**

1. Verify data points are equally spaced with step size h
2. Construct forward difference table:
   - Calculate successive forward differences: Δ^k f
   - Build difference table up to required order
3. Apply differentiation formulas:
   - First derivative: f'(x0) = (Δf0 - Δ²f0/2 + Δ³f0/3 - ...) / h
   - Higher derivatives use corresponding formulas
4. Calculate derivative at desired point using appropriate formula
5. Use sufficient terms for required accuracy

**Advantages:**

- No explicit function formula needed and works well for equally spaced tabulated data
- Systematic approach using difference tables with wide applicability

**Disadvantages:**

- Limited to equally spaced data
- Accuracy decreases with higher order derivatives

## Differentiation Using Forward Interpolation Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout<<fixed<<setprecision(6);

    int t;
    fin>>t;

    for (int i=1; i<=t;i++)
    {
        fout << "Test case #" <<i<< ":\n";

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
            for (int i = 0; i < n - j; i++)
            {
                diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
            }
        }

        double h = x[1] - x[0];
        double first_derivative = 0.0;
        for (int i = 1; i < n; i++)
        {
            first_derivative += pow(-1, i - 1) * diff[0][i] / i;
        }
        first_derivative /= h;

        double second_derivative = 0.0;
        if (n >= 3)
        {
            second_derivative = diff[0][2];
            if (n >= 4) second_derivative -= diff[0][3];
            if (n >= 5) second_derivative += (11.0 / 12.0) * diff[0][4];
            second_derivative /= (h * h);
        }

        fout << "First derivative at x = " << x[0] << " : " << first_derivative << "\n";
        fout << "Second derivative at x = " << x[0] << " : " << second_derivative << "\n\n";
    }

    return 0;
}

```

## Differentiation Using Forward Interpolation Input

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

## Differentiation Using Forward Interpolation Output

```
Test case #1:
First derivative at x = 0.000000 : 1.000000
Second derivative at x = 0.000000 : 2.000000

Test case #2:
First derivative at x = 1.000000 : 3.000000
Second derivative at x = 1.000000 : 6.000000

Test case #3:
First derivative at x = 10.000000 : 0.300000
Second derivative at x = 10.000000 : 0.020000

Test case #4:
First derivative at x = 2.000000 : 4.000000
Second derivative at x = 2.000000 : 2.000000


```
