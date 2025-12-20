# Newton's Backward Interpolation

## Newton's Backward Interpolation Theory

Newton's backward interpolation is a numerical method used to estimate function values when the required point lies near the end of equally spaced data points.

**Key Concepts:**

- Requires equally spaced x-values
- Uses backward difference table starting from last data point
- Best suited for interpolation near the end of data set
- Constructs interpolation polynomial using backward differences
- Complementary method to forward interpolation

**Algorithm Steps:**

1. Verify that x-values are equally spaced with step size h
2. Construct backward difference table:
   - First column: y-values
   - Calculate backward differences: ∇y[i] = y[i] - y[i-1]
   - Continue with higher order backward differences
3. For interpolation at point x near the end:
   - Calculate s = (x - xn) / h (where xn is last point)
   - Apply Newton's backward formula:
     ```
     P(x) = yn + s×∇yn + s(s+1)×∇²yn/2! + s(s+1)(s+2)×∇³yn/3! + ...
     ```
4. Use appropriate number of terms for desired accuracy

**Advantages:**

- Excellent accuracy for points near end of data with systematic organized approach
- Easy to implement for equally spaced data and widely used in numerical analysis

**Disadvantages:**

- Limited to equally spaced data points and less accurate for points far from end
- Backward differences may amplify errors and not suitable for sparse data

## Newton's Backward Interpolation Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout.setf(std::ios::fixed);
    fout << setprecision(3);

    int t;
    fin>>t;

    for (int i=1;i<=t; i++)
        {
        fout << "Test case #" << i << ":\n";

        int n;
        fin >> n;
        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) fin >> x[i];
        for (int i = 0; i < n; i++) fin >> y[i];

        double h = x[1] - x[0];

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++)
        {
            for (int i = n - 1; i >= j; i--)
            {
                diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
            }
        }

        int q;
        fin >> q;

        fout << "Given points (x, y):\n";
        for (int i = 0; i < n; i++)
            fout << "  " << x[i] << "  " << y[i] << "\n";

        fout << "Step size h = " << h << "\n\n";

        fout << "Backward Difference Table:\n";
        fout << "i        x[i]         y";
        for (int j = 1; j < n; j++) fout << "         Δ^" << j << "y";
        fout << "\n";

        for (int i = 0; i < n; i++)
        {
            fout << setw(2) << i << "   ";
            fout << setw(10) << x[i] << "   ";
            for (int j = 0; j <= i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";

        for (int i = 0; i < q; i++) {
            double xq;
            fin >> xq;

            double s = (xq - x[n-1]) / h;
            double result = diff[n-1][0];

            double numer = 1.0;
            double denom_fact = 1.0;

            for (int k = 1; k < n; k++) {
                numer *= (s + (k - 1));
                denom_fact *= k;
                result += (numer / denom_fact) * diff[n-1][k];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}

```

## Newton's Backward Interpolation Input

```
5
4
0 1 2 3
1 3 7 13
2
2.5
2.8
5
1 2 3 4 5
1 8 27 64 125
1
4.6
4
10 20 30 40
5 9 15 23
2
28
38
3
2 4 6
4 16 36
1
5.5
4
1 3 5 7
2 6 14 26
2
5.5
6.5

```

## Newton's Backward Interpolation Output

```
Test case #1:
Given points (x, y):
  0.000  1.000
  1.000  3.000
  2.000  7.000
  3.000  13.000
Step size h = 1.000

Backward Difference Table:
 i         x[i]            y          Δ^1y        Δ^2y        Δ^3y
 0        0.000          1.000
 1        1.000          3.000       2.000
 2        2.000          7.000       4.000       2.000
 3        3.000         13.000       6.000       2.000       0.000

Interpolated values:
  P(2.500) = 9.750
  P(2.800) = 11.640

Test case #2:
Given points (x, y):
  1.000  1.000
  2.000  8.000
  3.000  27.000
  4.000  64.000
  5.000  125.000
Step size h = 1.000

Backward Difference Table:
 i         x[i]            y          Δ^1y       Δ^2y        Δ^3y        Δ^4y
 0        1.000          1.000
 1        2.000          8.000       7.000
 2        3.000         27.000      19.000      12.000
 3        4.000         64.000      37.000      18.000       6.000
 4        5.000        125.000      61.000      24.000       6.000       0.000

Interpolated values:
  P(4.600) = 97.336

Test case #3:
Given points (x, y):
  10.000  5.000
  20.000  9.000
  30.000  15.000
  40.000  23.000
Step size h = 10.000

Backward Difference Table:
 i        x[i]             y          Δ^1y        Δ^2y        Δ^3y
 0       10.000          5.000
 1       20.000          9.000       4.000
 2       30.000         15.000       6.000       2.000
 3       40.000         23.000       8.000       2.000       0.000

Interpolated values:
  P(28.000) = 13.640
  P(38.000) = 21.240

Test case #4:
Given points (x, y):
  2.000  4.000
  4.000  16.000
  6.000  36.000
Step size h = 2.000

Backward Difference Table:
 i         x[i]            y         Δ^1y         Δ^2y
 0        2.000          4.000
 1        4.000         16.000      12.000
 2        6.000         36.000      20.000       8.000

Interpolated values:
  P(5.500) = 30.250

Test case #5:
Given points (x, y):
  1.000  2.000
  3.000  6.000
  5.000  14.000
  7.000  26.000
Step size h = 2.000

Backward Difference Table:
 i         x[i]            y         Δ^1y         Δ^2y        Δ^3y
 0        1.000          2.000
 1        3.000          6.000       4.000
 2        5.000         14.000       8.000       4.000
 3        7.000         26.000      12.000       4.000       0.000

Interpolated values:
  P(5.500) = 16.625
  P(6.500) = 22.625


```
