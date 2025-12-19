# Transcendental Regression

## Transcendental Regression Theory

Transcendental regression is used when the relationship between variables follows an exponential pattern. It is commonly applied in growth and decay processes.

### Key Concepts:

- Used for exponential models of the form y = a e^(bx)
- Nonlinear equation is converted into linear form using logarithms
- Based on least squares after transformation
- Requires all y values to be positive

### Algorithm Steps:

- Take natural logarithm on both sides of the equation
- Convert equation to ln(y) = ln(a) + bx
- Treat ln(y) as dependent variable and x as independent variable
- Apply linear regression to find coefficients
- Calculate a by taking exponential of ln(a)
- Substitute a and b into the original exponential equation

### Advantages:

- Effectively models exponential growth or decay
- Converts nonlinear problems into linear form
- Useful in population studies and engineering systems

### Disadvantages:

- Cannot handle zero or negative y values
- Logarithmic transformation may amplify errors
- Not suitable for non-exponential data

## Transcendental Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<double>x(n),y(n);

    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
      }
    double sumX=0,sumY=0,sumXY=0,sumX2=0;

    for(int i=0;i<n;i++){
        double X=x[i];        // X = x
        double Y=log(y[i]);   // Y = ln(y)

        sumX +=X;
        sumY +=Y;
        sumXY += X*Y;
        sumX2 += X*X;
    }

    double b =(n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double A =(sumY - b*sumX)/n;

    double a =exp(A);   // a = e^A

    cout<<fixed<<setprecision(6);
    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;
    cout<<"Model:y = "<<a<<"* e^("<<b<<"x)"<<endl;

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

```
a= 1.000008
b= 0.999998
Model:y = 1.000008* e^(0.999998x)
```
