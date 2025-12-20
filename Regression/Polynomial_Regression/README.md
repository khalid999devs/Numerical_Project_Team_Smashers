# Polynomial Regression

## Polynomial Regression Theory

Polynomial regression is a curve fitting technique used when the relationship between variables is nonlinear. It approximates the data using a polynomial equation of higher degree.

### Key Concepts:

- Extension of linear regression
- Fits data to a polynomial of degree m
- Uses the Least Squares Method
- Coefficients are determined using normal equations

### Algorithm Steps:

- Assume a polynomial equation of required degree
- Form normal equations using sums of powers of x
- Convert equations into matrix form
- Solve the system using Gaussian Elimination
- Determine polynomial coefficients
- Construct the fitted polynomial equation

### Advantages:

- Can model complex nonlinear trends with more flexibility than linear regression
- Provides accurate approximation within the given data range

### Disadvantages:

- Higher degree polynomials may cause overfitting and are computationally expensive
- Poor extrapolation outside data range with potential numerical instability

## Polynomial Regression Code

```cpp
#include <bits/stdc++.h>
using namespace std;


vector<double>solveGaussian(vector<vector<double>>A,vector<double>B){
    int n=A.size();

    for(int i=0;i<n;i++)
        A[i].push_back(B[i]);

    for(int i=0;i<n;i++){
        double pivot=A[i][i];
        for(int j=0;j<=n;j++) A[i][j] /= pivot;


        for(int k = 0; k < n; k++){
            if(k == i) continue;
            double factor= A[k][i];
            for(int j=0;j<=n;j++)
                A[k][j] -= factor*A[i][j];
        }
    }


    vector<double>x(n);
    for(int i=0;i<n;i++)
        x[i]=A[i][n];

    return x;
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];


    vector<vector<double>> A(m+1,vector<double>(m+1,0));
    vector<double> B(m+1,0);


    vector<double> S(2*m+1,0);
    for(int i=0;i<n;i++){
        double xi=1;
        for(int k=0;k<=2*m;k++){
            S[k] += xi;
            xi *= x[i];
        }
    }


    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            A[i][j] = S[i+j];


    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++)
            B[i] += y[j]*pow(x[j], i);
    }


    vector<double> coeff=solveGaussian(A,B);


    cout<<fixed<<setprecision(6);
    cout<<"Fitted Polynomial:y = ";
    for(int i=0;i<=m;i++){
        cout<<coeff[i];
        if(i>=1) cout<<"x^"<<i;
        if(i!=m) cout<<" + ";
    }
    cout<<endl;

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
