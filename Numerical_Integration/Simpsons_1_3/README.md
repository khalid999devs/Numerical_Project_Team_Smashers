# Simpson's 1/3 Rule

## Simpson's 1/3 Rule Theory

Simpson’s 1/3 rule is a numerical integration method used to approximate the area under a curve (definite integral) when the function is known at discrete points. It divides the interval into an even number of sub-intervals and approximates the function using parabolas instead of straight lines.This method is more accurate than the trapezoidal rule because it captures the curve’s shape better. It works best when the function is smooth and the points are equally spaced.It’s widely used in numerical analysis when the exact integral is difficult or impossible to calculate.

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
