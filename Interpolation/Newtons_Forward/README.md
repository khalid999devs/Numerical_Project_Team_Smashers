# Newton's Forward Interpolation

## Newton's Forward Interpolation Theory

Newton’s forward interpolation is a numerical method used to estimate the value of a function when the required value lies near the beginning of the given data set. It requires equally spaced x-values. The method uses a forward difference table, where successive differences are calculated starting from the first data point. Using these forward differences, an interpolation polynomial is constructed step by step to approximate the function value. Newton’s forward interpolation is widely used in numerical analysis for points near the start of the data set and provides accurate results for equally spaced data.

## Newton's Forward Interpolation Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout << setprecision(6);

    int t;
    fin >> t;
    for (int i = 1; i <= t; ++i) {
        fout << "Test case #" <<i<< ":\n";

        int n;fin >> n;
        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++)
            fin>>x[i];
        for (int i = 0; i < n; i++)
            fin>>y[i];

        double h = x[1] - x[0];
        bool equal_spaced = true;

        for (int i = 2; i < n; i++)
            {

            double expected = x[0] + i * h;
            if (fabs(x[i] - expected) > 1e-6) {
                equal_spaced = false;
                break;
            }
        }

        if (!equal_spaced) {
            fout << "x-values are not equally spaced.\n\n";
            continue;
        }

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++)
            {
            for (int i = 0; i + j < n; i++)
            {
                diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
            }
        }

        int q;
        fin >> q;
        fout << "Given points (x, y):\n";
        for (int i = 0;i<n; i++)
            fout << "  " << x[i] << "  " << y[i] << "\n";

        fout << "Step size h = " << h << "\n\n";

        fout << "Forward Difference Table:\n";
        fout << "i        x[i]         y";
        for (int j = 1; j < n; j++) fout << "         Δ^" << j << "y";
        fout << "\n";

        for (int i = 0; i < n; i++) {
            fout << setw(2) << i << "   ";
            fout << setw(10) << x[i] << "   ";
            for (int j = 0; j < n - i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";

        for (int i=0; i<q;i++) 
        {
            double xq;
            fin >> xq;

            double s = (xq - x[0]) / h;
            double result = diff[0][0];

            double numer = 1.0;
            double denom_fact = 1.0;

            for (int k = 1; k < n; k++) 
            {
                numer *= (s - (k - 1));
                denom_fact *= k;
                result += (numer / denom_fact) * diff[0][k];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}

```

## Newton's Forward Interpolation Input

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

## Newton's Forward Interpolation Output

```
Test case #1:
Given points (x, y):
  0  1
  1  3
  2  7
  3  13
Step size h = 1

Forward Difference Table:
 i           x[i]            y         Δ^1y         Δ^2y        Δ^3y
 0            0              1           2           2           0
 1            1              3           4           2
 2            2              7           6
 3            3             13

Interpolated values:
  P(0.5) = 1.75
  P(2.5) = 9.75

Test case #2:
Given points (x, y):
  1  1
  2  8
  3  27
  4  64
  5  125
Step size h = 1

Forward Difference Table:
 i           x[i]            y          Δ^1y       Δ^2y         Δ^3y        Δ^4y
 0            1              1           7          12           6           0
 1            2              8          19          18           6
 2            3             27          37          24
 3            4             64          61
 4            5            125

Interpolated values:
  P(3.5) = 42.875

Test case #3:
Given points (x, y):
  10  5
  20  9
  30  15
  40  23
Step size h = 10

Forward Difference Table:
 i          x[i]             y          Δ^1y        Δ^2y        Δ^3y
 0           10              5           4           2           0
 1           20              9           6           2
 2           30             15           8
 3           40             23

Interpolated values:
  P(15) = 6.75
  P(35) = 18.75

Test case #4:
Given points (x, y):
  2  4
  4  16
  6  36
Step size h = 2

Forward Difference Table:
 i           x[i]            y         Δ^1y         Δ^2y
 0            2              4          12           8
 1            4             16          20
 2            6             36

Interpolated values:
  P(5) = 25

Test case #5:
Given points (x, y):
  1  2
  3  6
  5  14
  7  26
Step size h = 2

Forward Difference Table:
 i           x[i]            y          Δ^1y        Δ^2y        Δ^3y
 0            1              2           4           4           0
 1            3              6           8           4
 2            5             14          12
 3            7             26

Interpolated values:
  P(4) = 9.5
  P(6) = 19.5


```
