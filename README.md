# Numerical Methods Project - Team Smashers

This is a Numerical Methods Laboratory Project based on the Numerical Lab of the 2nd year 2nd semester of Department of CSE of Khulna University of Engineering and Technology. This Project is all about 19 different numerical methods which we have categorized into 7 different segments.

## Table of Contents

### **[Solution of Linear Equations](#solution-of-linear-equations)**

- **[Gauss Elimination Method](#gauss-elimination-method)**

  - [Theory](#gauss-elimination-theory)
  - [Code](#gauss-elimination-code)
  - [Input](#gauss-elimination-input)
  - [Output](#gauss-elimination-output)

- **[Gauss Jordan Elimination Method](#gauss-jordan-elimination-method)**

  - [Theory](#gauss-jordan-theory)
  - [Code](#gauss-jordan-code)
  - [Input](#gauss-jordan-input)
  - [Output](#gauss-jordan-output)

- **[LU Decomposition Method](#lu-decomposition-method)**

  - [Theory](#lu-decomposition-theory)
  - [Code](#lu-decomposition-code)
  - [Input](#lu-decomposition-input)
  - [Output](#lu-decomposition-output)

- **[Matrix Inversion Method](#matrix-inversion-method)**
  - [Theory](#matrix-inversion-theory)
  - [Code](#matrix-inversion-code)
  - [Input](#matrix-inversion-input)
  - [Output](#matrix-inversion-output)

### **[Solution of Non-Linear Equations](#solution-of-non-linear-equations)**

- **[Bi-section Method](#bi-section-method)**

  - [Theory](#bisection-theory)
  - [Code](#bisection-code)
  - [Input](#bisection-input)
  - [Output](#bisection-output)

- **[False Position Method](#false-position-method)**

  - [Theory](#false-position-theory)
  - [Code](#false-position-code)
  - [Input](#false-position-input)
  - [Output](#false-position-output)

- **[Secant Method](#secant-method)**

  - [Theory](#secant-theory)
  - [Code](#secant-code)
  - [Input](#secant-input)
  - [Output](#secant-output)

- **[Newton-Raphson Method](#newton-raphson-method)**
  - [Theory](#newton-raphson-theory)
  - [Code](#newton-raphson-code)
  - [Input](#newton-raphson-input)
  - [Output](#newton-raphson-output)

### **[Interpolation & Approximation](#interpolation--approximation)**

- **[Newton's Forward Interpolation](#newtons-forward-interpolation)**

  - [Theory](#newtons-forward-interpolation-theory)
  - [Code](#newtons-forward-interpolation-code)
  - [Input](#newtons-forward-interpolation-input)
  - [Output](#newtons-forward-interpolation-output)

- **[Newton's Backward Interpolation](#newtons-backward-interpolation)**

  - [Theory](#newtons-backward-interpolation-theory)
  - [Code](#newtons-backward-interpolation-code)
  - [Input](#newtons-backward-interpolation-input)
  - [Output](#newtons-backward-interpolation-output)

- **[Newton's Divided Difference Method](#newtons-divided-difference-method)**
  - [Theory](#divided-difference-theory)
  - [Code](#divided-difference-code)
  - [Input](#divided-difference-input)
  - [Output](#divided-difference-output)

### **[Curve Fitting/Regression](#curve-fittingregression)**

- **[Linear Regression](#linear-regression)**

  - [Theory](#linear-regression-theory)
  - [Code](#linear-regression-code)
  - [Input](#linear-regression-input)
  - [Output](#linear-regression-output)

- **[Polynomial Regression](#polynomial-regression)**

  - [Theory](#polynomial-regression-theory)
  - [Code](#polynomial-regression-code)
  - [Input](#polynomial-regression-input)
  - [Output](#polynomial-regression-output)

- **[Transcendental Regression](#transcendental-regression)**
  - [Theory](#transcendental-regression-theory)
  - [Code](#transcendental-regression-code)
  - [Input](#transcendental-regression-input)
  - [Output](#transcendental-regression-output)

### **[Numerical Integration](#numerical-integration)**

- **[Simpson's 1/3 Rule](#simpsons-13-rule)**

  - [Theory](#simpsons-13-rule-theory)
  - [Code](#simpsons-13-rule-code)
  - [Input](#simpsons-13-rule-input)
  - [Output](#simpsons-13-rule-output)

- **[Simpson's 3/8 Rule](#simpsons-38-rule)**
  - [Theory](#simpsons-38-rule-theory)
  - [Code](#simpsons-38-rule-code)
  - [Input](#simpsons-38-rule-input)
  - [Output](#simpsons-38-rule-output)

### **[Numerical Differentiation](#numerical-differentiation)**

- **[Differentiation Using Forward Interpolation](#differentiation-using-forward-interpolation)**

  - [Theory](#differentiation-using-forward-interpolation-theory)
  - [Code](#differentiation-using-forward-interpolation-code)
  - [Input](#differentiation-using-forward-interpolation-input)
  - [Output](#differentiation-using-forward-interpolation-output)

- **[Differentiation Using Backward Interpolation](#differentiation-using-backward-interpolation)**
  - [Theory](#differentiation-using-backward-interpolation-theory)
  - [Code](#differentiation-using-backward-interpolation-code)
  - [Input](#differentiation-using-backward-interpolation-input)
  - [Output](#differentiation-using-backward-interpolation-output)

### **[Solution of Ordinary Differential Equations](#solution-of-ordinary-differential-equations)**

- **[Runge-Kutta Method](#runge-kutta-method)**
  - [Theory](#runge-kutta-theory)
  - [Code](#runge-kutta-code)
  - [Input](#runge-kutta-input)
  - [Output](#runge-kutta-output)

---

<a id="solution-of-linear-equations"></a>
# Solution of Linear Equations

<a id="gauss-elimination-method"></a>

# Gauss Elimination Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Gauss Elimination Theory

Gauss Elimination is a numerical technique used to solve a system of linear equations by systematically eliminating variables to transform the system into an upper triangular form.

**Key Concepts:**

- Transforms augmented matrix into upper triangular form
- Uses elementary row operations
- Two main stages: forward elimination and back substitution
- Suitable for systems with unique solutions

**Algorithm Steps:**

1. Form the augmented matrix [A|B] from the system of equations
2. Forward Elimination: For each pivot element
   - Make all elements below the pivot zero using row operations
   - Calculate ratio = a[j][i] / a[i][i]
   - Perform row operation: row[j] = row[j] - ratio × row[i]
3. Back Substitution: Starting from last equation
   - Calculate x[n-1] directly from last row
   - Substitute known values to find remaining variables working upward
   - Calculate each x[i] = (a[i][n] - sum) / a[i][i]

**Advantages:**

- Simple implementation and forms the foundation of advanced numerical methods
- Efficient for small to medium systems with reliable convergence

**Disadvantages:**

- Computationally expensive for large systems and sensitive to round-off errors
- May fail if pivot elements become zero during elimination

## Gauss Elimination Code

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        fin >> n;

        double a[n][n + 1], x[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double ratio = a[j][i] / a[i][i];
                for (int k = 0; k <= n; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }

        x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= a[i][j] * x[j];
            }
            x[i] /= a[i][i];
        }


        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++)
            {
            fout << "Value of x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}

```

## Gauss Elimination Input

```
5
2
1 1 5
2 -1 1
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
3
1 2 3 14
2 -1 1 3
3 1 -2 5
4
1 1 1 1 10
2 -1 3 -2 5
3 1 -1 2 7
4 -2 1 1 6
2
3 2 7
4 -1 5

```

## Gauss Elimination Output

```
Test Case 1:
Value of x1 = 2
Value of x2 = 3
Test Case 2:
Value of x1 = 2
Value of x2 = 3
Value of x3 = -1
Test Case 3:
Value of x1 = 1
Value of x2 = 2
Value of x3 = 3
Test Case 4:
Value of x1 = 1
Value of x2 = 2
Value of x3 = 3
Value of x4 = 4
Test Case 5:
Value of x1 = 1
Value of x2 = 1
```

<a id="gauss-jordan-elimination-method"></a>

# Gauss Jordan Elimination Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Gauss Jordan Theory

Gauss-Jordan Elimination is a numerical method used to solve a system of linear equations by transforming the augmented matrix into reduced row-echelon form (diagonal form).

**Key Concepts:**

- Transforms matrix into reduced row-echelon form (diagonal matrix)
- Eliminates variables both below and above the main diagonal
- Each pivot element is made equal to one

**Algorithm Steps:**

1. Form the augmented matrix [A|B] from the system
2. For each pivot element a[i][i]:
   - Divide the entire pivot row by a[i][i] to make pivot = 1
   - Eliminate all other elements in the pivot column (both above and below)
   - For each row j (where j ≠ i):
     - Calculate ratio = a[j][i]
     - Perform row[j] = row[j] - ratio × row[i]
3. After complete elimination, read solution directly from last column

**Advantages:**

- No back substitution required with solution directly readable from matrix
- Straightforward systematic approach useful for finding matrix inverses

**Disadvantages:**

- Requires more computations than Gauss Elimination
- Less efficient for large systems

## Gauss Jordan Code

```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        fin >> n;

        double a[n][n + 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            double pivot = a[i][i];

            for (int j = 0; j <= n; j++)
            {
                a[i][j] /= pivot;
            }

            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    double ratio = a[j][i];
                    for (int k = 0; k <= n; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                    }
                }
            }
        }

        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++)
        {
            fout << "Value of x" << i + 1 << " = " << a[i][n] << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}

```

## Gauss Jordan Input

```
5
2
1 1 5
2 -1 1
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
3
1 2 3 14
2 -1 1 3
3 1 -2 5
2
3 2 7
4 -1 5
2
1 -2 4
3 1 5

```

## Gauss Jordan Output

```
Test Case 1:
Value of x1 = 2
Value of x2 = 3
Test Case 2:
Value of x1 = 2
Value of x2 = 3
Value of x3 = -1
Test Case 3:
Value of x1 = 2
Value of x2 = 3
Value of x3 = 2
Test Case 4:
Value of x1 = 1.54545
Value of x2 = 1.18182
Test Case 5:
Value of x1 = 2
Value of x2 = -1

```

<a id="lu-decomposition-method"></a>

# LU Decomposition Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## LU Decomposition Theory

LU Decomposition is a numerical method that breaks a square matrix into the product of a lower triangular matrix (L) and an upper triangular matrix (U) to efficiently solve systems of linear equations.

**Key Concepts:**

- Decomposes matrix A into A = L × U
- L is lower triangular (elements below diagonal)
- U is upper triangular (elements on and above diagonal)
- Solves system in two stages: Ly = b, then Ux = y

**Algorithm Steps:**

1. Initialize L as identity matrix and U as zero matrix
2. Decomposition Process:
   - For each row i:
     - Calculate U[i][j] for j >= i using: U[i][j] = A[i][j] - sum(L[i][k] × U[k][j])
     - Calculate L[j][i] for j > i using: L[j][i] = (A[j][i] - sum(L[j][k] × U[k][i])) / U[i][i]
     - Set L[i][i] = 1
3. Forward Substitution: Solve Ly = b for y
   - y[i] = (b[i] - sum(L[i][j] × y[j])) / L[i][i]
4. Back Substitution: Solve Ux = y for x
   - x[i] = (y[i] - sum(U[i][j] × x[j])) / U[i][i]

**Advantages:**

- Very efficient when solving multiple systems with same coefficient matrix
- Decomposition can be reused for reducing computational complexity

**Disadvantages:**

- Requires square non-singular matrix and may fail if pivot elements are zero
- Not efficient for single system solution

## LU Decomposition Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++)
        {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<vector<double>> L(n, vector<double>(n, 0.0));
        vector<vector<double>> U(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
        }

        vector<double> b(n);
        for (int i = 0; i < n; i++)
        {
            fin >> b[i];
        }

        for (int i = 0; i < n; i++)
            {
            for (int k = i; k < n; k++)
            {
                double sum = 0;
                for (int j = 0; j < i; j++) sum += L[i][j] * U[j][k];
                U[i][k] = a[i][k] - sum;
            }
            for (int k = i; k < n; k++)
            {
                if (i == k) L[i][i] = 1;
                else {
                    double sum = 0;
                    for (int j = 0; j < i; j++) sum += L[k][j] * U[j][i];
                    L[k][i] = (a[k][i] - sum) / U[i][i];
                }
            }
        }

        vector<double> y(n);
        for (int i = 0; i < n; i++)
        {
            double sum = 0;
            for (int j = 0; j < i; j++) sum += L[i][j] * y[j];
            y[i] = b[i] - sum;
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--)
        {
            double sum = 0;
            for (int j = i + 1; j < n; j++) sum += U[i][j] * x[j];
            x[i] = (y[i] - sum) / U[i][i];
        }

        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++) {
            fout << "Value of x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}

```

## LU Decomposition Input

```
5
3
2 3 1
4 7 7
6 18 22
1 2 3
2
1 2
3 4
5 6
3
3 2 -1
2 -2 4
-1 0.5 -1
1 -2 0
4
1 2 3 4
2 5 2 1
3 2 6 3
4 1 3 8
10 5 12 15
2
4 3
6 3
10 12
3
2 -1 1
3 3 9
3 3 5
8 0 -6

```

## LU Decomposition Output

```
Test Case 1:
Value of x1 = 0.5
Value of x2 = 0
Value of x3 = 0
Test Case 2:
Value of x1 = -4
Value of x2 = 4.5
Test Case 3:
Value of x1 = 1
Value of x2 = -2
Value of x3 = -2
Test Case 4:
Value of x1 = -0.181818
Value of x2 = 0.272727
Value of x3 = 1.27273
Value of x4 = 1.45455
Test Case 5:
Value of x1 = 1
Value of x2 = 2

```

<a id="matrix-inversion-method"></a>

# Matrix Inversion Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Matrix Inversion Theory

Matrix Inversion is a method used to find the inverse of a square matrix, which when multiplied with the original matrix produces the identity matrix.

**Key Concepts:**

- Only square and non-singular matrices can be inverted
- A × A^(-1) = I (identity matrix)
- If determinant is zero, matrix is singular and has no inverse
- Useful for solving systems of equations: x = A^(-1) × b

**Algorithm Steps:**

1. Start with augmented matrix [A | I] where I is identity matrix
2. Apply Gauss-Jordan elimination:
   - For each pivot row i:
     - Divide row i by pivot element to make a[i][i] = 1
     - Eliminate all other elements in column i (make them zero)
     - Apply same operations to both sides of augmented matrix
3. When left side becomes identity matrix, right side becomes A^(-1)
4. Check for singularity (if pivot becomes zero, matrix is singular)

**Advantages:**

- Provides direct solution for systems of equations
- Once computed, can be reused for multiple problems with same coefficient matrix

**Disadvantages:**

- Computationally expensive O(n^3) operations
- Not efficient for single system solution

## Matrix Inversion Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++)
        {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<vector<double>> inv(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
            inv[i][i] = 1.0;
        }

        bool singular = false;

        for (int i = 0; i < n; i++)
            {
            if (fabs(a[i][i]) < 1e-9)
            {
                singular = true;
                break;
            }

            double pivot = a[i][i];
            for (int j = 0; j < n; j++)
            {
                a[i][j] /= pivot;
                inv[i][j] /= pivot;
            }

            for (int j = 0; j < n; j++)
                {
                if (j != i) {
                    double ratio = a[j][i];
                    for (int k = 0; k < n; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                        inv[j][k] -= ratio * inv[i][k];
                    }
                }
            }
        }

        fout << "Test Case " << i << ":\n";
        if (singular) {
            fout << "Matrix is singular and cannot be inverted.\n";
        } else {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fout << fixed << setprecision(6) << inv[i][j] << " ";
                }
                fout << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}

```

## Matrix Inversion Input

```
5
3
2 1 1
1 3 2
1 0 0
3
4 7 2
3 6 1
2 5 1
4
1 2 3 4
5 6 7 8
2 6 4 8
3 1 1 2
4
2 0 1 3
1 1 0 2
3 2 2 1
4 1 3 2
3
3 0 2
2 0 -2
0 1 1

```

## Matrix Inversion Output

```
Test Case 1:
0.000000 0.000000 1.000000
-2.000000 1.000000 3.000000
3.000000 -1.000000 -5.000000
Test Case 2:
0.333333 1.000000 -1.666667
-0.333333 0.000000 0.666667
1.000000 -2.000000 1.000000
Test Case 3:
-0.166667 0.055556 -0.055556 0.333333
-0.833333 0.277778 0.222222 -0.333333
0.166667 0.277778 -0.277778 -0.333333
0.583333 -0.361111 0.111111 0.333333
Test Case 4:
Matrix is singular and cannot be inverted.
Test Case 5:
Matrix is singular and cannot be inverted.

```

<a id="solution-of-non-linear-equations"></a>
# Solution of Non-Linear Equations

<a id="bi-section-method"></a>

# Bi-section Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

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

<a id="false-position-method"></a>

# False Position Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## False Position Theory

The False Position Method is a root-finding algorithm that combines features of the bisection method with linear interpolation.

**Key Concepts:**

- Similar to bisection but uses a weighted average instead of simple midpoint
- Generally converges faster than bisection method

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

- Always converges unlike secant method and generally faster than bisection
- Simple to implement with guaranteed bracketing of root

**Disadvantages:**

- Can be slower than Newton-Raphson in some cases
- One endpoint may remain fixed for many iterations causing slow convergence

## False Position Code

```cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void falsePosition(ofstream &fout, double a, double b, double tolerance, int maxIter) {
    if (f(a) * f(b) >= 0) {
        fout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return;
    }

    fout << fixed << setprecision(6);

    double c, prev_c = 0;

    for (int i = 1; i <= maxIter; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        fout << i << "\t" << a << "\t" << b << "\t"
             << c << "\t" << f(c) << endl;

        if (f(c) == 0.0) {
            fout << "\nExact root found!" << endl;
            break;
        }

        if (i > 1 && fabs(c - prev_c) < tolerance) {
            fout << "\nDesired accuracy achieved!" << endl;
            break;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        prev_c = c;
    }

    fout << "\nRoot found at x = " << c << endl;
    fout << "Function value at root: f(" << c << ") = " << f(c) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    double a, b, tolerance;
    int maxIter;

    fin >> a;
    fin >> b;
    fin >> tolerance;
    fin >> maxIter;

    falsePosition(fout, a, b, tolerance, maxIter);

    fin.close();
    fout.close();

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

## False Position Output

```
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

<a id="secant-method"></a>

# Secant Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Secant Theory

The Secant Method is an iterative root-finding algorithm that uses a succession of roots of secant lines to approximate a root of a function.

**Key Concepts:**

- Uses two initial guesses to approximate the derivative
- Does not require the function to be differentiable
- Approximates the tangent line with a secant line through two points

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

- Faster super-linear convergence than bisection and false position methods
- No need to calculate derivatives

**Disadvantages:**

- Convergence not guaranteed
- Requires two initial values unlike Newton-Raphson method

## Secant Code

```cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void secantMethod(ofstream &fout, double x0, double x1, double tolerance, int maxIter) {
    fout << fixed << setprecision(6);

    double x2, f0, f1;

    for (int i = 1; i <= maxIter; i++) {
        f0 = f(x0);
        f1 = f(x1);

        if (fabs(f1 - f0) < 1e-10) {
            fout << "\nError: Division by zero encountered!" << endl;
            return;
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        fout << i << "\t" << x0 << "\t" << x1 << "\t"
             << x2 << "\t" << f(x2) << endl;

        if (fabs(x2 - x1) < tolerance) {
            fout << "\nConvergence achieved!" << endl;
            break;
        }

        x0 = x1;
        x1 = x2;
    }

    fout << "\nRoot found at x = " << x2 << endl;
    fout << "Function value at root: f(" << x2 << ") = " << f(x2) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    double x0, x1, tolerance;
    int maxIter;

    fin >> x0;
    fin >> x1;
    fin >> tolerance;
    fin >> maxIter;

    secantMethod(fout, x0, x1, tolerance, maxIter);

    fin.close();
    fout.close();

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

## Secant Output

```
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

<a id="newton-raphson-method"></a>

# Newton-Raphson Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

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

**Algorithm Steps:\*\***

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

<a id="interpolation--approximation"></a>
# Interpolation & Approximation

<a id="newtons-forward-interpolation"></a>

# Newton's Forward Interpolation &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Newton's Forward Interpolation Theory

Newton's forward interpolation is a numerical method used to estimate function values when the required point lies near the beginning of equally spaced data points.

**Key Concepts:**

- Requires equally spaced x-values
- Uses forward difference table starting from first data point
- Best suited for interpolation near the beginning of data set
- Constructs interpolation polynomial step by step
- Based on finite difference approximation

**Algorithm Steps:**

1. Verify that x-values are equally spaced with step size h
2. Construct forward difference table:
   - First column: y-values (Δ^0y)
   - Second column: First differences (Δy[i] = y[i+1] - y[i])
   - Continue calculating higher order differences
3. For interpolation at point x:
   - Calculate s = (x - x0) / h
   - Apply Newton's forward formula:
     ```
     P(x) = y0 + s×Δy0 + s(s-1)×Δ²y0/2! + s(s-1)(s-2)×Δ³y0/3! + ...
     ```
4. Use appropriate number of terms based on required accuracy

**Advantages:**

- Simple systematic approach with good accuracy for points near beginning of data
- Easy to implement and widely used in numerical analysis

**Disadvantages:**

- Limited to equally spaced data and less accurate for points far from starting point
- Forward differences may accumulate errors for large datasets

## Newton's Forward Interpolation Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout << setprecision(6);

    int t;
    fin >> t;
    for (int i = 1; i <= t; ++i) {
        fout << "Test case #" <<i<< ":\n";

        int n;fin >> n;
        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++)
            fin>>x[i];
        for (int i = 0; i < n; i++)
            fin>>y[i];

        double h = x[1] - x[0];
        bool equal_spaced = true;

        for (int i = 2; i < n; i++)
            {

            double expected = x[0] + i * h;
            if (fabs(x[i] - expected) > 1e-6) {
                equal_spaced = false;
                break;
            }
        }

        if (!equal_spaced) {
            fout << "x-values are not equally spaced.\n\n";
            continue;
        }

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i + j < n; i++)
            {
                diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
            }
        }

        int q;
        fin >> q;
        fout << "Given points (x, y):\n";
        for (int i = 0;i<n; i++)
            fout << "  " << x[i] << "  " << y[i] << "\n";

        fout << "Step size h = " << h << "\n\n";

        fout << "Forward Difference Table:\n";
        fout << "i        x[i]         y";
        for (int j = 1; j < n; j++) fout << "         Δ^" << j << "y";
        fout << "\n";

        for (int i = 0; i < n; i++)
        {
            fout << setw(2) << i << "   ";
            fout << setw(10) << x[i] << "   ";
            for (int j = 0; j < n - i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";

        for (int i=0; i<q;i++)
        {
            double xq;
            fin >> xq;

            double s = (xq - x[0]) / h;
            double result = diff[0][0];

            double numer = 1.0;
            double denom_fact = 1.0;

            for (int k = 1; k < n; k++)
            {
                numer *= (s - (k - 1));
                denom_fact *= k;
                result += (numer / denom_fact) * diff[0][k];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}
```

## Newton's Forward Interpolation Input

```
5
4
0 1 2 3
1 3 7 13
2
0.5
2.5
5
1 2 3 4 5
1 8 27 64 125
1
3.5
4
10 20 30 40
5 9 15 23
2
15
35
3
2 4 6
4 16 36
1
5
4
1 3 5 7
2 6 14 26
2
4
6
```

## Newton's Forward Interpolation Output

```
Test case #1:
Given points (x, y):
  0  1
  1  3
  2  7
  3  13
Step size h = 1

Forward Difference Table:
 i           x[i]            y         Δ^1y         Δ^2y        Δ^3y
 0            0              1           2           2           0
 1            1              3           4           2
 2            2              7           6
 3            3             13

Interpolated values:
  P(0.5) = 1.75
  P(2.5) = 9.75

Test case #2:
Given points (x, y):
  1  1
  2  8
  3  27
  4  64
  5  125
Step size h = 1

Forward Difference Table:
 i           x[i]            y          Δ^1y       Δ^2y         Δ^3y        Δ^4y
 0            1              1           7          12           6           0
 1            2              8          19          18           6
 2            3             27          37          24
 3            4             64          61
 4            5            125

Interpolated values:
  P(3.5) = 42.875

Test case #3:
Given points (x, y):
  10  5
  20  9
  30  15
  40  23
Step size h = 10

Forward Difference Table:
 i          x[i]             y          Δ^1y        Δ^2y        Δ^3y
 0           10              5           4           2           0
 1           20              9           6           2
 2           30             15           8
 3           40             23

Interpolated values:
  P(15) = 6.75
  P(35) = 18.75

Test case #4:
Given points (x, y):
  2  4
  4  16
  6  36
Step size h = 2

Forward Difference Table:
 i           x[i]            y         Δ^1y         Δ^2y
 0            2              4          12           8
 1            4             16          20
 2            6             36

Interpolated values:
  P(5) = 25

Test case #5:
Given points (x, y):
  1  2
  3  6
  5  14
  7  26
Step size h = 2

Forward Difference Table:
 i           x[i]            y          Δ^1y        Δ^2y        Δ^3y
 0            1              2           4           4           0
 1            3              6           8           4
 2            5             14          12
 3            7             26

Interpolated values:
  P(4) = 9.5
  P(6) = 19.5
```

<a id="newtons-backward-interpolation"></a>

# Newton's Backward Interpolation &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Newton's Backward Interpolation Theory

Newton's backward interpolation is a numerical method used to estimate function values when the required point lies near the end of equally spaced data points.

**Key Concepts:**

- Requires equally spaced x-values
- Uses backward difference table starting from last data point
- Best suited for interpolation near the end of data set
- Constructs interpolation polynomial using backward differences

**Algorithm Steps:**

1. Verify that x-values are equally spaced with step size h
2. Construct backward difference table:
   - First column: y-values
   - Calculate backward differences: ∇y[i] = y[i] - y[i-1]
   - Continue with higher order backward differences
3. For interpolation at point x near the end:
   - Calculate s = (x - xn) / h (where xn is last point)
   - Apply Newton's backward formula:
     ```
     P(x) = yn + s×∇yn + s(s+1)×∇²yn/2! + s(s+1)(s+2)×∇³yn/3! + ...
     ```
4. Use appropriate number of terms for desired accuracy

**Advantages:**

- Excellent accuracy for points near end of data
- Easy to implement for equally spaced data

**Disadvantages:**

- Limited to equally spaced data points and less accurate for points far from end
- Backward differences may amplify errors and not suitable for sparse data

## Newton's Backward Interpolation Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout.setf(std::ios::fixed);
    fout << setprecision(3);

    int t;
    fin>>t;

    for (int i=1;i<=t; i++)
        {
        fout << "Test case #" << i << ":\n";

        int n;
        fin >> n;
        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) fin >> x[i];
        for (int i = 0; i < n; i++) fin >> y[i];

        double h = x[1] - x[0];

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++)
        {
            for (int i = n - 1; i >= j; i--)
            {
                diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
            }
        }

        int q;
        fin >> q;

        fout << "Given points (x, y):\n";
        for (int i = 0; i < n; i++)
            fout << "  " << x[i] << "  " << y[i] << "\n";

        fout << "Step size h = " << h << "\n\n";

        fout << "Backward Difference Table:\n";
        fout << "i        x[i]         y";
        for (int j = 1; j < n; j++) fout << "         Δ^" << j << "y";
        fout << "\n";

        for (int i = 0; i < n; i++)
        {
            fout << setw(2) << i << "   ";
            fout << setw(10) << x[i] << "   ";
            for (int j = 0; j <= i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";

        for (int i = 0; i < q; i++) {
            double xq;
            fin >> xq;

            double s = (xq - x[n-1]) / h;
            double result = diff[n-1][0];

            double numer = 1.0;
            double denom_fact = 1.0;

            for (int k = 1; k < n; k++) {
                numer *= (s + (k - 1));
                denom_fact *= k;
                result += (numer / denom_fact) * diff[n-1][k];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}

```

## Newton's Backward Interpolation Input

```
5
4
0 1 2 3
1 3 7 13
2
2.5
2.8
5
1 2 3 4 5
1 8 27 64 125
1
4.6
4
10 20 30 40
5 9 15 23
2
28
38
3
2 4 6
4 16 36
1
5.5
4
1 3 5 7
2 6 14 26
2
5.5
6.5

```

## Newton's Backward Interpolation Output

```
Test case #1:
Given points (x, y):
  0.000  1.000
  1.000  3.000
  2.000  7.000
  3.000  13.000
Step size h = 1.000

Backward Difference Table:
 i         x[i]            y          Δ^1y        Δ^2y        Δ^3y
 0        0.000          1.000
 1        1.000          3.000       2.000
 2        2.000          7.000       4.000       2.000
 3        3.000         13.000       6.000       2.000       0.000

Interpolated values:
  P(2.500) = 9.750
  P(2.800) = 11.640

Test case #2:
Given points (x, y):
  1.000  1.000
  2.000  8.000
  3.000  27.000
  4.000  64.000
  5.000  125.000
Step size h = 1.000

Backward Difference Table:
 i         x[i]            y          Δ^1y       Δ^2y        Δ^3y        Δ^4y
 0        1.000          1.000
 1        2.000          8.000       7.000
 2        3.000         27.000      19.000      12.000
 3        4.000         64.000      37.000      18.000       6.000
 4        5.000        125.000      61.000      24.000       6.000       0.000

Interpolated values:
  P(4.600) = 97.336

Test case #3:
Given points (x, y):
  10.000  5.000
  20.000  9.000
  30.000  15.000
  40.000  23.000
Step size h = 10.000

Backward Difference Table:
 i        x[i]             y          Δ^1y        Δ^2y        Δ^3y
 0       10.000          5.000
 1       20.000          9.000       4.000
 2       30.000         15.000       6.000       2.000
 3       40.000         23.000       8.000       2.000       0.000

Interpolated values:
  P(28.000) = 13.640
  P(38.000) = 21.240

Test case #4:
Given points (x, y):
  2.000  4.000
  4.000  16.000
  6.000  36.000
Step size h = 2.000

Backward Difference Table:
 i         x[i]            y         Δ^1y         Δ^2y
 0        2.000          4.000
 1        4.000         16.000      12.000
 2        6.000         36.000      20.000       8.000

Interpolated values:
  P(5.500) = 30.250

Test case #5:
Given points (x, y):
  1.000  2.000
  3.000  6.000
  5.000  14.000
  7.000  26.000
Step size h = 2.000

Backward Difference Table:
 i         x[i]            y         Δ^1y         Δ^2y        Δ^3y
 0        1.000          2.000
 1        3.000          6.000       4.000
 2        5.000         14.000       8.000       4.000
 3        7.000         26.000      12.000       4.000       0.000

Interpolated values:
  P(5.500) = 16.625
  P(6.500) = 22.625

```

---

<a id="newtons-divided-difference-method"></a>

# Newton's Divided Difference Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Divided Difference Theory

Divided difference is a flexible interpolation method used to estimate function values from given data points when the x-values are not equally spaced.

**Key Concepts:**

- Works with unequally spaced data points
- Uses divided difference table instead of regular difference table
- More flexible than Newton's forward/backward methods

**Algorithm Steps:**

1. Arrange data points (x0,y0), (x1,y1), ..., (xn,yn)
2. Construct divided difference table:
   - First column: f[xi] = yi (function values)
   - Second column: f[xi,xi+1] = (f[xi+1] - f[xi]) / (xi+1 - xi)
   - Continue: f[xi,...,xi+k] = (f[xi+1,...,xi+k] - f[xi,...,xi+k-1]) / (xi+k - xi)
3. Build interpolation polynomial:
   ```
   P(x) = f[x0] + f[x0,x1](x-x0) + f[x0,x1,x2](x-x0)(x-x1) + ...
   ```
4. Evaluate polynomial at desired interpolation point

**Advantages:**

- Handles unequally spaced data points with no spacing restrictions on x-values
- Flexible and efficient for adding new data points with easy implementation

**Disadvantages:**

- More complex calculations than equal-spacing methods
- Divided differences can become large for widely spaced points

## Divided Difference Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << setprecision(3) << fixed;

    int t;
    fin >> t;

    for (int tc = 1; tc <= t; tc++) {
        fout << "Test case #" << tc << ":\n";

        int n;
        fin >> n;

        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) fin >> x[i];
        for (int i = 0; i < n; i++) fin >> y[i];

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
            }
        }

        int q;
        fin >> q;

        fout << "Given points (x, y):\n";
        for (int i = 0; i < n; i++)
            fout << setw(6) << x[i] << "  " << setw(6) << y[i] << "\n";

        fout << "\nDivided Difference Table:\n";

        // Header
        fout << setw(2) << "i" << "   " << setw(8) << "x[i]" << "   " << setw(8) << "f[xi]";
        for (int j = 1; j < n; j++) {
            fout << "   " << setw(12) << "f[x0";
            for (int k = 1; k <= j; k++) fout << ",x" << k;
            fout << "]";
        }
        fout << "\n";

        // Table values
        for (int i = 0; i < n; i++) {
            fout << setw(2) << i << "   ";
            fout << setw(8) << x[i] << "   ";
            for (int j = 0; j < n - i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";
        for (int qi = 0; qi < q; qi++) {
            double xq;
            fin >> xq;

            double result = diff[0][0];
            for (int i = 1; i < n; i++)
            {
                double term = 1.0;
                for (int j = 0; j < i; j++)
                    term *= (xq - x[j]);
                result += term * diff[0][i];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}

```

## Divided Difference Input

```
5
4
0 1 2 3
1 3 7 13
2
0.5
2.5
5
1 2 3 4 5
1 8 27 64 125
1
3.5
4
10 20 30 40
5 9 15 23
2
15
35
3
2 4 6
4 16 36
1
5
4
1 3 5 7
2 6 14 26
2
4
6

```

## Divided Difference Output

```
Test case #1:
Given points (x, y):
 0.000   1.000
 1.000   3.000
 2.000   7.000
 3.000  13.000

Divided Difference Table:
 i       x[i]          f[xi]      f[x0,x1]   f[x0,x1,x2]  f[x0,x1,x2,x3]
 0      0.000          1.000       2.000       1.000         0.000
 1      1.000          3.000       4.000       1.000
 2      2.000          7.000       6.000
 3      3.000         13.000

Interpolated values:
  P(0.500) = 1.750
  P(2.500) = 9.750

Test case #2:
Given points (x, y):
 1.000   1.000
 2.000   8.000
 3.000   27.000
 4.000   64.000
 5.000   125.000

Divided Difference Table:
 i       x[i]          f[xi]     f[x0,x1]   f[x0,x1,x2] f[x0,x1,x2,x3]   f[x0,x1,x2,x3,x4]
 0      1.000          1.000       7.000       6.000       1.000              0.000
 1      2.000          8.000      19.000       9.000       1.000
 2      3.000         27.000      37.000      12.000
 3      4.000         64.000      61.000
 4      5.000        125.000

Interpolated values:
  P(3.500) = 42.875

Test case #3:
Given points (x, y):
10.000   5.000
20.000   9.000
30.000  15.000
40.000  23.000

Divided Difference Table:
 i       x[i]          f[xi]     f[x0,x1]   f[x0,x1,x2] f[x0,x1,x2,x3]
 0     10.000          5.000       0.400       0.010       0.000
 1     20.000          9.000       0.600       0.010
 2     30.000         15.000       0.800
 3     40.000         23.000

Interpolated values:
  P(15.000) = 6.750
  P(35.000) = 18.750

Test case #4:
Given points (x, y):
 2.000   4.000
 4.000  16.000
 6.000  36.000

Divided Difference Table:
 i       x[i]          f[xi]     f[x0,x1]    f[x0,x1,x2]
 0      2.000          4.000       6.000       1.000
 1      4.000         16.000      10.000
 2      6.000         36.000

Interpolated values:
  P(5.000) = 25.000

Test case #5:
Given points (x, y):
 1.000   2.000
 3.000   6.000
 5.000  14.000
 7.000  26.000

Divided Difference Table:
 i       x[i]          f[xi]      f[x0,x1]   f[x0,x1,x2]  f[x0,x1,x2,x3]
 0      1.000          2.000       2.000       0.500         0.000
 1      3.000          6.000       4.000       0.500
 2      5.000         14.000       6.000
 3      7.000         26.000

Interpolated values:
  P(4.000) = 9.500
  P(6.000) = 19.500

```

---

<a id="curve-fittingregression"></a>
# Curve Fitting/Regression

<a id="linear-regression"></a>

# Linear Regression &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Linear Regression Theory

Linear Regression is a numerical method to determine the best-fit straight line for a given set of data points. It establishes a linear relation between a dependent variable and an independent variable.

**Key Concepts:**

- Based on the Least Squares Method
- Minimizes the sum of squared errors between observed and predicted values
- Assumes a linear relationship of form y = a + bx
- Suitable when data follows an approximate straight-line trend

**Algorithm Steps:**

Assume the model

y = a + bx

Calculate summations of x, y, xy and x^2

Compute b using,

b = (n\*sum(xy) - sum(x)sum(y)) / (nsum(x^2) - (sum(x))^2)

Compute a using,

a = (sum(y) - b\*sum(x)) / n

Substitute values of a and b to obtain the regression equation

**Advantages:**

- Simple implementation and simple computation
- Widely used for straightforward linear relations

**Disadvantages:**

- Only applicable to linear data patterns
- Cannot represent non-linear relations

## Linear Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
    }

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX  += x[i];
        sumY  += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    fout << fixed << setprecision(6);
    fout << "a = " << a << endl;
    fout << "b = " << b << endl;
    fout << "Model: y = " << a << " + " << b << "x" << endl;

    fin.close();
    fout.close();

    return 0;
}
```

## Linear Regression Input

```
5
1 2
2 3
3 5
4 4
5 6
```

## Linear Regression Output

```
a = 1.300000
b = 0.900000
Model: y = 1.300000 + 0.900000x
```

<a id="polynomial-regression"></a>

# Polynomial Regression &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Polynomial Regression Theory

Polynomial regression is a curve fitting technique used when the relation is nonlinear. It uses a polynomial equation of higher degree for approximation.

**Key Concepts:**

- Based on Least Squares Method
- Fits data to a polynomial of degree m
- It is an extension of linear regression

**Algorithm Steps:**

- Assume a polynomial equation of required degree
- Form normal equations using sums of powers of x
- Convert equation into matrix
- Solve it using Gauss Elimination
- Determine polynomial coefficients
- Construct the fitted polynomial equation

**Advantages:**

- Model complex non-linear relation
- Provides accurate approximation within a given range

**Disadvantages:**

- Higher degree polynomial may cause overfitting
- Poor extrapolation outside data range with potential numerical instability

## Polynomial Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<double> solveGaussian(vector<vector<double>> A, vector<double> B) {
    int n = A.size();

    for (int i = 0; i < n; i++)
        A[i].push_back(B[i]);

    for (int i = 0; i < n; i++) {
        double pivot = A[i][i];
        for (int j = 0; j <= n; j++)
            A[i][j] /= pivot;

        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = A[k][i];
            for (int j = 0; j <= n; j++)
                A[k][j] -= factor * A[i][j];
        }
    }

    vector<double> x(n);
    for (int i = 0; i < n; i++)
        x[i] = A[i][n];

    return x;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
        fin >> x[i] >> y[i];

    vector<vector<double>> A(m + 1, vector<double>(m + 1, 0));
    vector<double> B(m + 1, 0);

    vector<double> S(2 * m + 1, 0);
    for (int i = 0; i < n; i++) {
        double xi = 1;
        for (int k = 0; k <= 2 * m; k++) {
            S[k] += xi;
            xi *= x[i];
        }
    }

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            A[i][j] = S[i + j];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++)
            B[i] += y[j] * pow(x[j], i);
    }

    vector<double> coeff = solveGaussian(A, B);

    fout << fixed << setprecision(6);
    fout << "Fitted Polynomial: y = ";
    for (int i = 0; i <= m; i++) {
        fout << coeff[i];
        if (i >= 1) fout << "x^" << i;
        if (i != m) fout << " + ";
    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}
```

## Polynomial Regression Input

```
5 2
1 1
2 4
3 9
4 16
5 25
```

## Polynomial Regression Output

```
Fitted Polynomial:y = 0.000000 + 0.000000x^1 + 1.000000x^2
```

<a id="transcendental-regression"></a>

# Transcendental Regression &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Transcendental Regression Theory

Transcendental regression is used when the relation follows an exponential pattern. It is generally applied in growth and decay processes.

**Key Concepts:**

- Used for exponential models of form y = ae^(bx)
- Nonlinear equation is converted into linear using logarithms
- Based on least squares after transformation

**Algorithm Steps:**

- Take logarithm on both sides of equation
- Convert equation to ln(y)= ln(a) + bx
- Treat ln(y) as dependent variable(Y) and x as independent variable
- Apply linear regression to find coefficients
- Calculate a by taking exponential of ln(a)
- Substitute a and b into original equation

**Advantages:**

- Effectively models exponential growth or decay
- Useful in studies and systems with exponential behavior

**Disadvantages:**

- Cannot handle zero or negative y values
- Logarithmic transformation may amplify errors
- unsuitable for non-exponential data

## Transcendental Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
    }

    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        double X = x[i];        // X = x
        double Y = log(y[i]);   // Y = ln(y)

        sumX += X;
        sumY += Y;
        sumXY += X * Y;
        sumX2 += X * X;
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double A = (sumY - b * sumX) / n;

    double a = exp(A);   // a = e^A

    fout << fixed << setprecision(6);
    fout << "a = " << a << endl;
    fout << "b = " << b << endl;
    fout << "Model: y = " << a << " * e^(" << b << "x)" << endl;

    fin.close();
    fout.close();

    return 0;
}
```

## Transcendental Regression Input

```
5
1 2.7183
2 7.3891
3 20.0855
4 54.5982
5 148.4132
```

## Transcendental Regression Output

````
a = 1.000008
b = 0.999998
Model: y = 1.000008 * e^(0.999998x)
```---

<a id="numerical-integration"></a>
# Numerical Integration

<a id="simpsons-13-rule"></a>
# Simpson's 1/3 Rule &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

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

````

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

<a id="simpsons-38-rule"></a>

# Simpson's 3/8 Rule &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Simpson's 3/8 Rule Theory

Simpson's 3/8 rule is another numerical integration method to approximate the area under a curve. It is similar to Simpson's 1/3 rule but divides the interval into segments that are multiples of 3 and uses cubic polynomials for approximation.

**Key Concepts:**

- Divides the interval into n segments (n must be a multiple of 3)
- Approximates the curve using cubic polynomials
- More accurate than trapezoidal rule
- Requires equally spaced points

**Formula:**

Integral = (3h/8) * [f(x0) + 3*f(x1) + 3*f(x2) + 2*f(x3) + 3\*f(x4) + ... + f(xn)]

h=(b-a)/n

**Algorithm Steps:**

1. Divide interval [a,b] into n sub-intervals, where n must be a multiple of 3
2. Calculate step size h=(b-a)/n
3. Calculate function values at all points xi= a + i\*h
4. Add f(a) + f(b)
5. Add 3 times the sum of function values where i is not a multiple of 3
6. Add 2 times the sum of function values where i is a multiple of 3(not limiting values of i)
7. Multiply total by 3h/8

**Advantages:**

- Good accuracy
- Can handle curves with higher variation
- Useful when number of intervals is multiple of 3

**Disadvantages:**

- Requires specific number of intervals(multiple of 3)
- Complex than trapezoidal rule

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

---

<a id="numerical-differentiation"></a>
# Numerical Differentiation

<a id="differentiation-using-forward-interpolation"></a>

# Differentiation Using Forward Interpolation &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Differentiation Using Forward Interpolation Theory

Forward interpolation differentiation is a numerical method used to approximate derivatives when function values are available at equally spaced points near the beginning of the data set.

**Key Concepts:**

- Uses forward difference table to calculate derivatives
- Suitable for points near the beginning of tabulated data
- Requires equally spaced data points
- Approximates derivatives without explicit function formula
- Based on finite difference approximation of derivatives

**Algorithm Steps:**

1. Verify data points are equally spaced with step size h
2. Construct forward difference table:
   - Calculate successive forward differences: Δ^k f
   - Build difference table up to required order
3. Apply differentiation formulas:
   - First derivative: f'(x0) = (Δf0 - Δ²f0/2 + Δ³f0/3 - ...) / h
   - Higher derivatives use corresponding formulas
4. Calculate derivative at desired point using appropriate formula
5. Use sufficient terms for required accuracy

**Advantages:**

- No explicit function formula needed and works well for equally spaced tabulated data
- Systematic approach using difference tables with wide applicability

**Disadvantages:**

- Limited to equally spaced data
- Accuracy decreases with higher order derivatives

## Differentiation Using Forward Interpolation Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout<<fixed<<setprecision(6);

    int t;
    fin>>t;

    for (int i=1; i<=t;i++)
    {
        fout << "Test case #" <<i<< ":\n";

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
            for (int i = 0; i < n - j; i++)
            {
                diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
            }
        }

        double h = x[1] - x[0];
        double first_derivative = 0.0;
        for (int i = 1; i < n; i++)
        {
            first_derivative += pow(-1, i - 1) * diff[0][i] / i;
        }
        first_derivative /= h;

        double second_derivative = 0.0;
        if (n >= 3)
        {
            second_derivative = diff[0][2];
            if (n >= 4) second_derivative -= diff[0][3];
            if (n >= 5) second_derivative += (11.0 / 12.0) * diff[0][4];
            second_derivative /= (h * h);
        }

        fout << "First derivative at x = " << x[0] << " : " << first_derivative << "\n";
        fout << "Second derivative at x = " << x[0] << " : " << second_derivative << "\n\n";
    }

    return 0;
}

```

## Differentiation Using Forward Interpolation Input

```
4
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

```

## Differentiation Using Forward Interpolation Output

```
Test case #1:
First derivative at x = 0.000000 : 1.000000
Second derivative at x = 0.000000 : 2.000000

Test case #2:
First derivative at x = 1.000000 : 3.000000
Second derivative at x = 1.000000 : 6.000000

Test case #3:
First derivative at x = 10.000000 : 0.300000
Second derivative at x = 10.000000 : 0.020000

Test case #4:
First derivative at x = 2.000000 : 4.000000
Second derivative at x = 2.000000 : 2.000000

```

<a id="differentiation-using-backward-interpolation"></a>

# Differentiation Using Backward Interpolation &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Differentiation Using Backward Interpolation Theory

Backward interpolation differentiation is a numerical method used to approximate derivatives when function values are available at equally spaced points near the end of the data set.

**Key Concepts:**

- Uses backward difference table to calculate derivatives
- Suitable for points near the end of tabulated data
- Requires equally spaced data points
- Based on finite difference approximation using backward differences

**Algorithm Steps:**

1. Verify data points are equally spaced with step size h
2. Construct backward difference table:
   - Calculate successive backward differences: ∇^k f
   - Build difference table up to required order
3. Apply backward differentiation formulas:
   - First derivative: f'(xn) = (∇fn + ∇²fn/2 + ∇³fn/3 + ...) / h
   - Higher derivatives use corresponding backward formulas
4. Calculate derivative at desired point using appropriate formula
5. Use sufficient terms for required accuracy

**Advantages:**

- Excellent for derivatives near end of data set
- Systematic approach

**Disadvantages:**

- Limited to equally spaced data
- Accuracy decreases with higher order derivatives
- Backward differences may amplify errors

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

    for (int i = 1; i <= t; i++)
    {
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
4
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

```

## Differentiation Using Backward Interpolation Output

```
Test case #1:
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

```

---

<a id="solution-of-ordinary-differential-equations"></a>
# Solution of Ordinary Differential Equations

<a id="runge-kutta-method"></a>

# Runge-Kutta Method &nbsp;&nbsp;<sub>[⬆ Back to TOC](#table-of-contents)</sub>

## Runge Kutta Theory

The Runge-Kutta Method is one of the most powerful and widely-used numerical techniques for solving ordinary differential equations (ODEs). The 4th order Runge-Kutta method provides computational efficiency.

**Key Concepts:**

- Used to solve first-order differential equations of the form dy/dx = f(x, y)
- Does not require calculation of higher-order derivatives
- More accurate than Euler's method

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

- High accuracy with reasonable computational cost
- No derivative calculations needed

**Disadvantages:**

- Requires four function evaluations per step increasing computational load
- Fixed step size may not be optimal for all problems

**When to Use:**

- When high accuracy is needed for ODEs
- When function derivatives are difficult to compute

## Runge Kutta Code

```cpp
#include<bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return x + y;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    double x0, y0, x, h;

    fin >> x0;
    fin >> y0;
    fin >> x;
    fin >> h;

    int n = (int)((x - x0) / h);
    double y = y0;

    fout << fixed << setprecision(6);

    for (int i = 1; i <= n; i++) {
        double k1 = h * f(x0, y);
        double k2 = h * f(x0 + h/2.0, y + k1/2.0);
        double k3 = h * f(x0 + h/2.0, y + k2/2.0);
        double k4 = h * f(x0 + h, y + k3);

        fout << i << "\t" << x0 << "\t" << y << "\t" << k1 << "\t" << k2 << "\t" << k3 << "\t" << k4 << endl;

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x0 = x0 + h;
    }

    fout << "\nRoot: " << y << endl;

    fin.close();
    fout.close();

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

---

## Contribution

**Contributed by Team Smashers:**

- **Khalid Ahammed** - 2207035
- **Majharul Sajid** - 2207060
- **Sadiq Bin Sahidullah** - 2207036

Department of Computer Science and Engineering,  
Khulna University of Engineering and Technology
