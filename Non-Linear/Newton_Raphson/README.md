# Newton-Raphson Method

## Newton Raphson Theory

The Newton-Raphson Method is one of the most powerful and widely-used techniques for finding roots of equations. It uses the tangent line at a point to approximate the root

**Key Concepts:**

- Requires the function and its derivative
- Uses linear approximation via tangent lines
- Quadratic convergence (very fast when it works)

**Formula:**

```
x(n+1) = x(n) - f(x(n)) / f'(x(n))
```

Where:

- x(n) is the current approximation
- f(x(n)) is the function value at x(n)
- f'(x(n)) is the derivative value at x(n)

**Algorithm Steps:**

1. Start with an initial guess x0 close to the root
2. Calculate f(x0) and f'(x0)
3. Compute x1 = x0 - f(x0)/f'(x0)
4. Repeat until |x(n+1) - x(n)| < tolerance

**Advantages:**

- Very fast quadratic convergence when near the root
- Works well for most smooth functions

**Disadvantages:**

- Requires derivative calculation and may diverge if f'(x) = 0
- No guaranteed convergence

## Newton Raphson Code

```cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

double df(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(ofstream &fout, double x0, double tolerance, int maxIter) {
    fout << fixed << setprecision(6);

    double x1, fx, dfx;

    for (int i = 1; i <= maxIter; i++) {
        fx = f(x0);
        dfx = df(x0);

        if (fabs(dfx) < 1e-10) {
            fout << "\nError: Derivative is zero. Cannot continue." << endl;
            return;
        }

        x1 = x0 - fx / dfx;

        fout << i << "\t" << x0 << "\t" << fx << "\t"
             << dfx << "\t" << x1 << endl;

        if (fabs(x1 - x0) < tolerance) {
            fout << "\nConvergence achieved!" << endl;
            x0 = x1;
            break;
        }

        if (fabs(fx) < tolerance) {
            fout << "\nRoot found (f(x) ~ 0)!" << endl;
            break;
        }

        x0 = x1;
    }

    fout << "\nRoot found at x = " << x0 << endl;
    fout << "Function value at root: f(" << x0 << ") = " << f(x0) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    double x0, tolerance;
    int maxIter;

    fin >> x0;
    fin >> tolerance;
    fin >> maxIter;

    newtonRaphson(fout, x0, tolerance, maxIter);

    fin.close();
    fout.close();

    return 0;
}
```

## Newton Raphson Input

```
2.0
0.0001
20
```

## Newton Raphson Output

```
1	2.000000	4.000000	11.000000	1.636364
2	1.636364	0.360465	7.030992	1.585111
3	1.585111	0.014527	6.535517	1.582887
4	1.582887	0.000025	6.512039	1.582884

Convergence achieved!

Root found at x = 1.582884
Function value at root: f(1.582884) = 0.000001
```
