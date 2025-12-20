# Linear Regression

## Linear Regression Theory

Linear Regression is a numerical method to determine the best-fit straight line for a given set of data points. It establishes a linear relation between a dependent variable and an independent variable.

### Key Concepts:

- Based on the Least Squares Method
- Minimizes the sum of squared errors between observed and predicted values
- Assumes a linear relationship of form y = a + bx
- Suitable when data follows an approximate straight-line trend

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

- Simple implementation and simple computation 
- Widely used for straightforward linear relations

### Disadvantages:

- Only applicable to linear data patterns 
- Cannot represent non-linear relations

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
