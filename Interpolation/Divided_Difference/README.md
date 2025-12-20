# Newton's Divided Difference Method

## Divided Difference Theory

Divided difference is a flexible interpolation method used to estimate function values from given data points when the x-values are not equally spaced.

**Key Concepts:**

- Works with unequally spaced data points
- Uses divided difference table instead of regular difference table
- Each column represents successive divided differences
- Interpolation polynomial built using top row of table
- More flexible than Newton's forward/backward methods

**Algorithm Steps:**

1. Arrange data points (x0,y0), (x1,y1), ..., (xn,yn)
2. Construct divided difference table:
   - First column: f[xi] = yi (function values)
   - Second column: f[xi,xi+1] = (f[xi+1] - f[xi]) / (xi+1 - xi)
   - Continue: f[xi,...,xi+k] = (f[xi+1,...,xi+k] - f[xi,...,xi+k-1]) / (xi+k - xi)
3. Build interpolation polynomial:
   ```
   P(x) = f[x0] + f[x0,x1](x-x0) + f[x0,x1,x2](x-x0)(x-x1) + ...
   ```
4. Evaluate polynomial at desired interpolation point

**Advantages:**

- Handles unequally spaced data points with no spacing restrictions on x-values
- Flexible and efficient for adding new data points with easy implementation

**Disadvantages:**

- More complex calculations than equal-spacing methods with potential numerical precision issues
- Divided differences can become large for widely spaced points affecting stability

## Divided Difference Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << setprecision(3) << fixed;

    int t;
    fin >> t;

    for (int tc = 1; tc <= t; tc++) {
        fout << "Test case #" << tc << ":\n";

        int n;
        fin >> n;

        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) fin >> x[i];
        for (int i = 0; i < n; i++) fin >> y[i];

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
            }
        }

        int q;
        fin >> q;

        fout << "Given points (x, y):\n";
        for (int i = 0; i < n; i++)
            fout << setw(6) << x[i] << "  " << setw(6) << y[i] << "\n";

        fout << "\nDivided Difference Table:\n";

        // Header
        fout << setw(2) << "i" << "   " << setw(8) << "x[i]" << "   " << setw(8) << "f[xi]";
        for (int j = 1; j < n; j++) {
            fout << "   " << setw(12) << "f[x0";
            for (int k = 1; k <= j; k++) fout << ",x" << k;
            fout << "]";
        }
        fout << "\n";

        // Table values
        for (int i = 0; i < n; i++) {
            fout << setw(2) << i << "   ";
            fout << setw(8) << x[i] << "   ";
            for (int j = 0; j < n - i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";
        for (int qi = 0; qi < q; qi++) {
            double xq;
            fin >> xq;

            double result = diff[0][0];
            for (int i = 1; i < n; i++)
            {
                double term = 1.0;
                for (int j = 0; j < i; j++)
                    term *= (xq - x[j]);
                result += term * diff[0][i];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}

```

## Divided Difference Input

```
5
4
0 1 2 3
1 3 7 13
2
0.5
2.5
5
1 2 3 4 5
1 8 27 64 125
1
3.5
4
10 20 30 40
5 9 15 23
2
15
35
3
2 4 6
4 16 36
1
5
4
1 3 5 7
2 6 14 26
2
4
6

```

## Divided Difference Output

```
Test case #1:
Given points (x, y):
 0.000   1.000
 1.000   3.000
 2.000   7.000
 3.000  13.000

Divided Difference Table:
 i       x[i]          f[xi]      f[x0,x1]   f[x0,x1,x2]  f[x0,x1,x2,x3]
 0      0.000          1.000       2.000       1.000         0.000
 1      1.000          3.000       4.000       1.000
 2      2.000          7.000       6.000
 3      3.000         13.000

Interpolated values:
  P(0.500) = 1.750
  P(2.500) = 9.750

Test case #2:
Given points (x, y):
 1.000   1.000
 2.000   8.000
 3.000   27.000
 4.000   64.000
 5.000   125.000

Divided Difference Table:
 i       x[i]          f[xi]     f[x0,x1]   f[x0,x1,x2] f[x0,x1,x2,x3]   f[x0,x1,x2,x3,x4]
 0      1.000          1.000       7.000       6.000       1.000              0.000
 1      2.000          8.000      19.000       9.000       1.000
 2      3.000         27.000      37.000      12.000
 3      4.000         64.000      61.000
 4      5.000        125.000

Interpolated values:
  P(3.500) = 42.875

Test case #3:
Given points (x, y):
10.000   5.000
20.000   9.000
30.000  15.000
40.000  23.000

Divided Difference Table:
 i       x[i]          f[xi]     f[x0,x1]   f[x0,x1,x2] f[x0,x1,x2,x3]
 0     10.000          5.000       0.400       0.010       0.000
 1     20.000          9.000       0.600       0.010
 2     30.000         15.000       0.800
 3     40.000         23.000

Interpolated values:
  P(15.000) = 6.750
  P(35.000) = 18.750

Test case #4:
Given points (x, y):
 2.000   4.000
 4.000  16.000
 6.000  36.000

Divided Difference Table:
 i       x[i]          f[xi]     f[x0,x1]    f[x0,x1,x2]
 0      2.000          4.000       6.000       1.000
 1      4.000         16.000      10.000
 2      6.000         36.000

Interpolated values:
  P(5.000) = 25.000

Test case #5:
Given points (x, y):
 1.000   2.000
 3.000   6.000
 5.000  14.000
 7.000  26.000

Divided Difference Table:
 i       x[i]          f[xi]      f[x0,x1]   f[x0,x1,x2]  f[x0,x1,x2,x3]
 0      1.000          2.000       2.000       0.500         0.000
 1      3.000          6.000       4.000       0.500
 2      5.000         14.000       6.000
 3      7.000         26.000

Interpolated values:
  P(4.000) = 9.500
  P(6.000) = 19.500


```
