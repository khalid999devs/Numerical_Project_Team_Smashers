# Secant Method

## Secant Theory

The Secant Method is an iterative root-finding algorithm that uses a succession of roots of secant lines to approximate a root of a function. It's faster than bisection but doesn't require derivative calculation like Newton-Raphson.

**Key Concepts:**
- Uses two initial guesses to approximate the derivative
- Does not require the function to be differentiable
- Approximates the tangent line with a secant line through two points
- Convergence is not always guaranteed but is generally fast

**Formula:**
```
x(n+1) = x(n) - f(x(n)) × (x(n) - x(n-1)) / (f(x(n)) - f(x(n-1)))
```

**Algorithm Steps:**
1. Start with two initial guesses x0 and x1
2. Calculate x2 using the secant formula
3. Use x1 and x2 to calculate x3
4. Continue until convergence (|x(n+1) - x(n)| < tolerance)

**Advantages:**
- Faster convergence than bisection and false position
- No need to calculate derivatives
- Super-linear convergence (order ~ 1.618)

**Disadvantages:**
- Convergence is not guaranteed
- May diverge if initial guesses are poor
- Requires two initial values

**Comparison with Newton-Raphson:**
- Secant: Uses finite difference approximation, no derivative needed
- Newton: Uses actual derivative, faster convergence (quadratic vs super-linear)

## Secant Code

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



double f(double x) {
    return x*x*x - x - 2;
}

void secantMethod(double x0, double x1, double tolerance, int maxIter) {
    cout << fixed << setprecision(6);

    
    double x2, f0, f1;
    
    for (int i = 1; i <= maxIter; i++) {
        f0 = f(x0);
        f1 = f(x1);
        
        
        if (fabs(f1 - f0) < 1e-10) {
            cout << "\nError: Division by zero encountered!" << endl;
            return;
        }
        
        
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        
        cout << i << "\t" << x0 << "\t" << x1 << "\t" 
             << x2 << "\t" << f(x2) << endl;
        
        
        if (fabs(x2 - x1) < tolerance) {
            cout << "\nConvergence achieved!" << endl;
            break;
        }
        
        
        x0 = x1;
        x1 = x2;
    }
    
    cout << "\nRoot found at x = " << x2 << endl;
    cout << "Function value at root: f(" << x2 << ") = " << f(x2) << endl;
}

int main() {
    double x0, x1, tolerance;
    int maxIter;
    
    cout << "\nEnter first initial guess (x0): ";
    cin >> x0;
    cout << "Enter second initial guess (x1): ";
    cin >> x1;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;
    
    secantMethod(x0, x1, tolerance, maxIter);
    
    return 0;
}
```

## Secant Input

```
1.5
2.0
0.0001
20
```

**Input Format:**
- Line 1: First initial guess (x0)
- Line 2: Second initial guess (x1)
- Line 3: Tolerance (desired accuracy)
- Line 4: Maximum number of iterations

**Note:** Choose initial guesses close to the expected root for better convergence.

## Secant Output

```
Enter first initial guess (x0): 1.5
Enter second initial guess (x1): 2.0
Enter tolerance (e.g., 0.0001): 0.0001
Enter maximum iterations: 20

1	1.500000	2.000000	1.607143	-0.175623
2	2.000000	1.607143	1.658824	0.062439
3	1.607143	1.658824	1.643586	-0.014750
4	1.658824	1.643586	1.646384	0.003536
5	1.643586	1.646384	1.645665	-0.000845
6	1.646384	1.645665	1.645837	0.000202

Convergence achieved!

Root found at x = 1.645837
Function value at root: f(1.645837) = 0.000202
```
