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
#### b = (n*sum(xy) - sum(x)sum(y)) / (nsum(x^2) - (sum(x))^2)

Compute a using,
#### a = (sum(y) - b*sum(x)) / n

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
# Add your code here
```

## Linear Regression Input

```
[Add your input format here]
```

## Linear Regression Output

```
[Add your output format here]
```
