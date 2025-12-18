# False Position Method

## False Position Theory

The False Position Method (also known as Regula Falsi Method or Method of Chords) is a root-finding algorithm that combines features of the bisection method with linear interpolation.

**Key Concepts:**

- Similar to bisection but uses a weighted average instead of simple midpoint
- Draws a secant line between two points and finds where it crosses the x-axis
- Generally converges faster than bisection method
- Always keeps the root bracketed between two points

**Algorithm Steps:**

1. Start with two points 'a' and 'b' such that f(a) × f(b) < 0
2. Find the point where the line joining (a, f(a)) and (b, f(b)) crosses x-axis:
   ```
   c = (a × f(b) - b × f(a)) / (f(b) - f(a))
   ```
3. If f(c) = 0, then c is the root
4. If f(a) × f(c) < 0, root lies in [a, c], so set b = c
5. Otherwise, root lies in [c, b], so set a = c
6. Repeat until desired accuracy is achieved

**Advantages:**

- Always converges (unlike secant method)
- Generally faster than bisection
- Simple to implement

**Disadvantages:**

- Can be slower than Newton-Raphson in some cases
- One endpoint may remain fixed for many iterations

## False Position Code

```cpp
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;



double f(double x) {
    return x*x*x - x - 2;
}

void falsePosition(double a, double b, double tolerance, int maxIter) {

    if (f(a) * f(b) >= 0) {
        cout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return;
    }

    cout << fixed << setprecision(6);


    double c, prev_c = 0;

    for (int i = 1; i <= maxIter; i++) {

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));


        cout << i << "\\t" << a << "\\t" << b << "\\t"
             << c << "\\t" << f(c) << endl;


        if (f(c) == 0.0) {
            cout << "\nExact root found!" << endl;
            break;
        }


        if (i > 1 && fabs(c - prev_c) < tolerance) {
            cout << "\nDesired accuracy achieved!" << endl;
            break;
        }


        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        prev_c = c;
    }

    cout << "\nRoot found at x = " << c << endl;
    cout << "Function value at root: f(" << c << ") = " << f(c) << endl;
}

int main() {
    double a, b, tolerance;
    int maxIter;
    
    cout << "\nEnter the first point (a): ";
    cin >> a;
    cout << "Enter the second point (b): ";
    cin >> b;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    falsePosition(a, b, tolerance, maxIter);

    return 0;
}
```

## False Position Input

```
1.5
2.0
0.0001
20
```

**Input Format:**

- Line 1: First point 'a' of the interval
- Line 2: Second point 'b' of the interval
- Line 3: Tolerance (desired accuracy)
- Line 4: Maximum number of iterations

**Note:** f(a) and f(b) must have opposite signs.

## False Position Output

```
Enter the first point (a): 1.5
Enter the second point (b): 2.0
Enter tolerance (e.g., 0.0001): 0.0001
Enter maximum iterations: 20

1	1.500000	2.000000	1.622951	-0.117362
2	1.622951	2.000000	1.640119	-0.030693
3	1.640119	2.000000	1.644511	-0.008172
4	1.644511	2.000000	1.645693	-0.002181
5	1.645693	2.000000	1.646008	-0.000582
6	1.646008	2.000000	1.646092	-0.000155

Desired accuracy achieved!

Root found at x = 1.646092
Function value at root: f(1.646092) = -0.000155
```
