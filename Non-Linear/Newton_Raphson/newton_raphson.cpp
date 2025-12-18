#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

double df(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(double x0, double tolerance, int maxIter) {
    cout << fixed << setprecision(6);
    
    double x1, fx, dfx;
    
    for (int i = 1; i <= maxIter; i++) {
        fx = f(x0);
        dfx = df(x0);
        
        if (fabs(dfx) < 1e-10) {
            cout << "\nError: Derivative is zero. Cannot continue." << endl;
            return;
        }
        
        x1 = x0 - fx / dfx;
        
        cout << i << "\t" << x0 << "\t" << fx << "\t" 
             << dfx << "\t" << x1 << endl;
        
        if (fabs(x1 - x0) < tolerance) {
            cout << "\nConvergence achieved!" << endl;
            x0 = x1;
            break;
        }
        
        if (fabs(fx) < tolerance) {
            cout << "\nRoot found (f(x) ~ 0)!" << endl;
            break;
        }
        
        x0 = x1;
    }
    
    cout << "\nRoot found at x = " << x0 << endl;
    cout << "Function value at root: f(" << x0 << ") = " << f(x0) << endl;
}

int main() {
    double x0, tolerance;
    int maxIter;
    
    cout << "\nEnter initial guess (x0): ";
    cin >> x0;
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;
    
    newtonRaphson(x0, tolerance, maxIter);
    
    return 0;
}
