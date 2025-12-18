#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void bisection(double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        cout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return;
    }
    
    cout << fixed << setprecision(6);
    
    double c;
    int iteration = 0;
    
    while ((b - a) >= tolerance) {
        iteration++;
        c = (a + b) / 2.0;
        
        cout << iteration << "\t" << a << "\t" << b << "\t" 
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
    
    cout << "\nRoot found at x = " << c << endl;
    cout << "Function value at root: f(" << c << ") = " << f(c) << endl;
}

int main() {
    double a, b, tolerance;
    
    cout << "\nEnter the first point (a): ";
    cin >> a;
    cout << "Enter the second point (b): ";
    cin >> b;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    
    bisection(a, b, tolerance);
    
    return 0;
}
