# Newton-Raphson Method

## Newton Raphson Theory

The Newton-Raphson Method is one of the most powerful and widely-used techniques for finding roots of equations. It uses the tangent line at a point to approximate the root and converges very quickly when starting near the actual root.

**Key Concepts:**

- Requires the function and its derivative
- Uses linear approximation via tangent lines
- Quadratic convergence (very fast when it works)
- Named after Isaac Newton and Joseph Raphson

**Formula:**

```
x(n+1) = x(n) - f(x(n)) / f'(x(n))
```

Where:

- x(n) is the current approximation
- f(x(n)) is the function value at x(n)
- f'(x(n)) is the derivative value at x(n)

**Geometric Interpretation:**
Draw a tangent line to f(x) at point x(n). The point where this tangent crosses the x-axis gives us the next approximation x(n+1).

**Algorithm Steps:**

1. Start with an initial guess x0 close to the root
2. Calculate f(x0) and f'(x0)
3. Compute x1 = x0 - f(x0)/f'(x0)
4. Repeat until |x(n+1) - x(n)| < tolerance

**Advantages:**

- Very fast convergence (quadratic) when near the root
- Can identify repeated roots
- Works well for most smooth functions

**Disadvantages:**

- Requires derivative calculation
- May diverge if f'(x) = 0 or initial guess is poor
- No guaranteed convergence
- Can oscillate between points

**When to Use:**

- When derivative is easy to compute
- When a good initial guess is available
- When fast convergence is needed

## Newton Raphson Code

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



double f(double x) {
    return x*x*x - x - 2;
}

double df(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(double x0, double tolerance, int maxIter) {
    cout << fixed << setprecision(6);


    double x1, fx, dfx;

    for (int i = 1; i <= maxIter; i++) {
        fx = f(x0);
        dfx = df(x0);


        if (fabs(dfx) < 1e-10) {
            cout << "\nError: Derivative is zero. Cannot continue." << endl;
            return;
        }


        x1 = x0 - fx / dfx;

        cout << i << "\t" << x0 << "\t" << fx << "\t"
             << dfx << "\t" << x1 << endl;


        if (fabs(x1 - x0) < tolerance) {
            cout << "\nConvergence achieved!" << endl;
            x0 = x1;
            break;
        }


        if (fabs(fx) < tolerance) {
            cout << "\nRoot found (f(x) ~ 0)!" << endl;
            break;
        }

        x0 = x1;
    }

    cout << "\nRoot found at x = " << x0 << endl;
    cout << "Function value at root: f(" << x0 << ") = " << f(x0) << endl;
}

int main() {
    double x0, tolerance;
    int maxIter;

    cout << "\nEnter initial guess (x0): ";
    cin >> x0;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    newtonRaphson(x0, tolerance, maxIter);

    return 0;
}
```

## Newton Raphson Input

```
2.0
0.0001
20
```

**Input Format:**

- Line 1: Initial guess (x0)
- Line 2: Tolerance (desired accuracy)
- Line 3: Maximum number of iterations

**Note:** Choose an initial guess reasonably close to the actual root for better convergence.

## Newton Raphson Output

```
Enter initial guess (x0): 2.0
Enter tolerance (e.g., 0.0001): 0.0001
Enter maximum iterations: 20

1	2.000000	4.000000	11.000000	1.636364
2	1.636364	0.360465	7.030992	1.585111
3	1.585111	0.014527	6.535517	1.582887
4	1.582887	0.000025	6.512039	1.582884

Convergence achieved!

Root found at x = 1.582884
Function value at root: f(1.582884) = 0.000001
```
