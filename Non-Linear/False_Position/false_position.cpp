#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void falsePosition(double a, double b, double tolerance, int maxIter) {
    if (f(a) * f(b) >= 0) {
        cout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return;
    }
    
    cout << fixed << setprecision(6);
    
    double c, prev_c = 0;
    
    for (int i = 1; i <= maxIter; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        
        cout << i << "\t" << a << "\t" << b << "\t" 
             << c << "\t" << f(c) << endl;
        
        if (f(c) == 0.0) {
            cout << "\nExact root found!" << endl;
            break;
        }
        
        if (i > 1 && fabs(c - prev_c) < tolerance) {
            cout << "\nDesired accuracy achieved!" << endl;
            break;
        }
        
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        prev_c = c;
    }
    
    cout << "\nRoot found at x = " << c << endl;
    cout << "Function value at root: f(" << c << ") = " << f(c) << endl;
}

int main() {
    double a, b, tolerance;
    int maxIter;
    
    cout << "\nEnter the first point (a): ";
    cin >> a;
    cout << "Enter the second point (b): ";
    cin >> b;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;
    
    falsePosition(a, b, tolerance, maxIter);
    
    return 0;
}
