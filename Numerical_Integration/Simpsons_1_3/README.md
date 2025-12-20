# Simpson's 1/3 Rule

## Simpson's 1/3 Rule Theory

Simpson's 1/3 rule is a numerical integration method used to approximate definite integrals by dividing the interval into an even number of sub-intervals and using parabolic approximation.

**Key Concepts:**

- Divides interval into even number of sub-intervals (n must be even)
- Approximates function using parabolas instead of straight lines
- More accurate than trapezoidal rule
- Based on fitting parabolas through three consecutive points

**Formula:**

Integral = (h/3) * [f(x0) + 4*f(x1) + 2*f(x2) + 4*f(x3) + ... + 4\*f(xn-1) + f(xn)]

Where h = (b-a)/n

**Algorithm Steps:**

1. Divide interval [a,b] into even number of sub-intervals (n)
2. Calculate step size h=(b-a)/n
3. Calculate function values at all points xi= a + i\*h
4. Add f(a) + f(b)
5. Add 4 times sum of odd-indexed terms
6. Add 2 times sum of even-indexed terms
7. Multiply total by h/3

**Advantages:**

- Higher accuracy than trapezoidal rule
- Works well and widely used in calculation

**Disadvantages:**

- Requires even number of intervals
- Complex than trapezoidal rule

## Simpson's 1/3 Rule Code

```cpp
#include<bits/stdc++.h>

using namespace std;

double f(double x)
 {
    return 1/(1+x*x);
 }

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin>>t;

    for (int i = 1; i <= t; i++) {
        double a, b, h, sum;
        int n;
        fin>>a>>b>>n;
        h =(b - a)/n;
        sum =f(a)+f(b);

        for (int i = 1; i < n; i++)
            {

            double x = a + i * h;
            if (i % 2 == 0)sum += 2 * f(x);

            else
                sum += 4 * f(x);
        }
              sum =(h/3)*sum;

        fout << "Test Case " << i
             << ": Value of integral = " << sum << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

```

## Simpson's 1/3 Rule Input

```
3
0 1 4
0 2 6
1 3 8

```

## Simpson's 1/3 Rule Output

```
Test Case 1: Value of integral = 0.785392
Test Case 2: Value of integral = 1.10705
Test Case 3: Value of integral = 0.463649

```
