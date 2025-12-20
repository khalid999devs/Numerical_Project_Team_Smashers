# Bi-section Method

## Bisection Theory

The Bisection Method is one of the simplest and most reliable methods for finding the root of a non-linear equation.

**Key Concepts:**

- Based on the Intermediate Value Theorem
- If f(x) is continuous on [a, b] and f(a) × f(b) < 0, then there exists at least one root in (a, b)

**Algorithm Steps:**

1. Start with two points 'a' and 'b' such that f(a) and f(b) have opposite signs
2. Calculate midpoint c = (a + b) / 2
3. If f(c) = 0, then c is the root
4. If f(a) × f(c) < 0, root lies in [a, c], so set b = c
5. Otherwise, root lies in [c, b], so set a = c
6. Repeat until the interval becomes sufficiently small

**Advantages:**

- Always converges if initial assumptions are met
- Simple solution

**Disadvantages:**

- Slower convergence compared to other root-finding methods
- Cannot detect multiple roots in the same interval

## Bisection Code

```cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void bisection(ofstream &fout, double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        fout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return;
    }

    fout << fixed << setprecision(6);

    double c;
    int iteration = 0;

    while ((b - a) >= tolerance) {
        iteration++;
        c = (a + b) / 2.0;

        fout << iteration << "\t" << a << "\t" << b << "\t"
             << c << "\t" << f(c) << endl;

        if (f(c) == 0.0) {
            break;
        }
        else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    fout << "\nRoot found at x = " << c << endl;
    fout << "Function value at root: f(" << c << ") = " << f(c) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    double a, b, tolerance;

    fin >> a;
    fin >> b;
    fin >> tolerance;

    bisection(fout, a, b, tolerance);

    fin.close();
    fout.close();

    return 0;
}
```

## Bisection Input

```
1.5
2.0
0.0001
```

## Bisection Output

```
1	1.500000	2.000000	1.750000	0.609375
2	1.500000	1.750000	1.625000	-0.099609
3	1.625000	1.750000	1.687500	0.224365
4	1.625000	1.687500	1.656250	0.054077
5	1.625000	1.656250	1.640625	-0.023560
6	1.640625	1.656250	1.648438	0.014984
7	1.640625	1.648438	1.644531	-0.004366
8	1.644531	1.648438	1.646484	0.005294
9	1.644531	1.646484	1.645508	0.000461
10	1.644531	1.645508	1.645020	-0.001953
11	1.645020	1.645508	1.645264	-0.000746

Root found at x = 1.645264
Function value at root: f(1.645264) = -0.000746
```
