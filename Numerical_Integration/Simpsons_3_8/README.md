# Simpson's 3/8 Rule

## Simpson's 3/8 Rule Theory

[Add your theory content here]

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
