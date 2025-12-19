# Linear Regression

## Linear Regression Theory

Linear Regression is a numerical method used to determine the best-fit straight line for a given set of data points. It establishes a linear relationship between an independent variable and a dependent variable using the least squares principle.

### Key Concepts:

- Based on the Least Squares Method
- Minimizes the sum of squared errors between observed and predicted values
- Assumes a linear relationship of the form y = a + bx
- Suitable when data follows an approximately straight-line trend

### Algorithm Steps:

Assume the model

### y = a + bx

Calculate summations of x, y, xy and x^2

Compute b using,

#### b = (n\*sum(xy) - sum(x)sum(y)) / (nsum(x^2) - (sum(x))^2)

Compute a using,

#### a = (sum(y) - b\*sum(x)) / n

Substitute values of a and b to obtain the regression equation

### Advantages:

- Simple and easy to implement
- Requires less computation
- Widely used in engineering and data analysis

### Disadvantages:

- Applicable only to linear data
- Sensitive to outliers
- Cannot represent complex nonlinear relationships

## Linear Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<double>x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    double sumX=0,sumY=0,sumXY=0,sumX2=0;

    for(int i=0;i<n;i++){
        sumX  +=x[i];
        sumY  +=y[i];
        sumXY +=x[i]*y[i];
        sumX2 +=x[i]*x[i];
    }

    double b =(n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double a = (sumY - b*sumX) / n;

    cout<<fixed<<setprecision(6);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"Model: y = "<<a<<" + "<<b<<"x"<<endl;

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
