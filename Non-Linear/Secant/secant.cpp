#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void secantMethod(double x0, double x1, double tolerance, int maxIter) {
    cout << fixed << setprecision(6);
    
    double x2, f0, f1;
    
    for (int i = 1; i <= maxIter; i++) {
        f0 = f(x0);
        f1 = f(x1);
        
        if (fabs(f1 - f0) < 1e-10) {
            cout << "\nError: Division by zero encountered!" << endl;
            return;
        }
        
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        
        cout << i << "\t" << x0 << "\t" << x1 << "\t" 
             << x2 << "\t" << f(x2) << endl;
        
        if (fabs(x2 - x1) < tolerance) {
            cout << "\nConvergence achieved!" << endl;
            break;
        }
        
        x0 = x1;
        x1 = x2;
    }
    
    cout << "\nRoot found at x = " << x2 << endl;
    cout << "Function value at root: f(" << x2 << ") = " << f(x2) << endl;
}

int main() {
    double x0, x1, tolerance;
    int maxIter;
    
    cout << "\nEnter first initial guess (x0): ";
    cin >> x0;
    cout << "Enter second initial guess (x1): ";
    cin >> x1;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;
    
    secantMethod(x0, x1, tolerance, maxIter);
    
    return 0;
}
