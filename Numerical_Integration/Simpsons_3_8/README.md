# Simpson's 3/8 Rule

## Simpson's 3/8 Rule Theory

Simpson's 3/8 rule is another numerical integration method used to approximate the area under a curve (definite integral). It is similar to Simpson's 1/3 rule but divides the interval into segments that are multiples of 3 and uses cubic polynomials for approximation.

This method is more accurate than the trapezoidal rule and can be used when the number of intervals is a multiple of 3. It provides better accuracy for functions with more curvature.

**Key Concepts:**

- Divides the interval into n segments where n must be a multiple of 3
- Approximates the curve using cubic polynomials
- More accurate than trapezoidal rule
- Requires equally spaced points

**Formula:**

Integral = (3h/8) * [f(x0) + 3*f(x1) + 3*f(x2) + 2*f(x3) + 3\*f(x4) + ... + f(xn)]

Where coefficients follow the pattern: 1, 3, 3, 2, 3, 3, 2, ..., 3, 3, 1

**Advantages:**

- Good accuracy for smooth functions and can handle curves with higher variation
- Useful alternative when number of intervals is multiple of 3

**Disadvantages:**

- Requires specific number of intervals (multiple of 3) limiting flexibility
- More complex than trapezoidal rule with slightly higher computational cost

## Simpson's 3/8 Rule Code

```cpp
#include<bits/stdc++.h>

using namespace std;

double f(double x)
{
    return 1 / (1+2*x*x+3*x*x*x);
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin>> t;

    for (int i = 1;i <= t;i++) {
        double a,b,h,sum;
        int n;

        fin>>a>>b>>n;
        h =(b -a)/n;
        sum =f(a)+f(b);

        for (int i = 1; i < n; i++)
            {
            double x = a + i * h;
            if (i % 3 == 0)sum += 2 * f(x);
            else
                sum += 3 * f(x);
        }
        sum = (3 * h / 8) * sum;
        fout << "Test Case " << i
             << ": Value of integral = " << sum << endl;
    }
    fin.close();
    fout.close();

    return 0;
}

```

## Simpson's 3/8 Rule Input

```
3
0 1 6
0 3 9
1 4 12

```

## Simpson's 3/8 Rule Output

```
Test Case 1: Value of integral = 0.568488
Test Case 2: Value of integral = 0.654928
Test Case 3: Value of integral = 0.0993483

```
