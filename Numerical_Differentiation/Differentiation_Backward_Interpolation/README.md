# Differentiation Using Backward Interpolation

## Differentiation Using Backward Interpolation Theory

[Backward Interpolation for Differentiation (Concept):
Backward interpolation estimates the value of a function at points near the end of a tabulated data set. For differentiation, it uses the function values at equally spaced points to approximate derivatives. A backward difference table is constructed, and derivatives are expressed in terms of these backward differences.It is most useful when data is equally spaced and the point of interest is near the last entries of the table.This is essentially the reverse approach of forward interpolation, suitable for end-of-table calculations.]

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

    for (int i = 1; i <= t; i++) {
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
[4
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
]
```

## Differentiation Using Backward Interpolation Output

```
[Test case #1:
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

]
```
