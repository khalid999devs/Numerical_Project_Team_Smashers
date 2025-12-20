# Runge-Kutta Method

## Runge Kutta Theory

The Runge-Kutta Method is one of the most powerful and widely-used numerical techniques for solving ordinary differential equations (ODEs). The 4th order Runge-Kutta method provides a good balance between accuracy and computational efficiency.

**Key Concepts:**

- Used to solve first-order differential equations of the form dy/dx = f(x, y)
- Does not require calculation of higher-order derivatives
- Fourth-order method means error is proportional to h^5
- More accurate than Euler's method while still being relatively simple

**Formula:**

The method calculates four slopes at different points within the interval and takes their weighted average:

```
k1 = h * f(x, y)
k2 = h * f(x + h/2, y + k1/2)
k3 = h * f(x + h/2, y + k2/2)
k4 = h * f(x + h, y + k3)

y(next) = y + (k1 + 2*k2 + 2*k3 + k4) / 6
```

**Algorithm Steps:**

1. Start with initial values x0 and y0
2. Calculate k1 using current point
3. Calculate k2 using midpoint with k1
4. Calculate k3 using midpoint with k2
5. Calculate k4 using endpoint with k3
6. Compute next y value using weighted average
7. Move to next x value and repeat

**Advantages:**

- High accuracy with reasonable computational cost and no derivative calculations needed
- Self-starting method requiring only initial condition with wide applicability

**Disadvantages:**

- Requires four function evaluations per step increasing computational load
- Fixed step size may not be optimal for all problems

**When to Use:**

- When high accuracy is needed for ODEs
- When function derivatives are difficult to compute
- For initial value problems in engineering and physics

## Runge Kutta Code

```cpp
#include<bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return x + y;
}

int main() {
    double x0, y0, x, h;

    cin >> x0;
    cin >> y0;
    cin >> x;
    cin >> h;

    int n = (int)((x - x0) / h);
    double y = y0;

    cout << fixed << setprecision(6);

    for (int i = 1; i <= n; i++) {
        double k1 = h * f(x0, y);
        double k2 = h * f(x0 + h/2.0, y + k1/2.0);
        double k3 = h * f(x0 + h/2.0, y + k2/2.0);
        double k4 = h * f(x0 + h, y + k3);

        cout << i << "\t" << x0 << "\t" << y << "\t" << k1 << "\t" << k2 << "\t" << k3 << "\t" << k4 << endl;

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x0 = x0 + h;
    }

    cout << "\nRoot: " << y << endl;

    return 0;
}
```

## Runge Kutta Input

```
0
1
1
0.2
```

## Runge Kutta Output

```
1	0.000000	1.000000	0.200000	0.220000	0.222000	0.248400
2	0.200000	1.221403	0.284281	0.312627	0.315256	0.349576
3	0.400000	1.583650	0.396730	0.433992	0.437541	0.483300
4	0.600000	2.127230	0.545446	0.596697	0.601534	0.664204
5	0.800000	2.896481	0.739296	0.808508	0.814995	0.899558

Root: 3.718282
```
