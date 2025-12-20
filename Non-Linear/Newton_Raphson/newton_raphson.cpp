#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

double df(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(ofstream &fout, double x0, double tolerance, int maxIter) {
    fout << fixed << setprecision(6);
    
    double x1, fx, dfx;
    
    for (int i = 1; i <= maxIter; i++) {
        fx = f(x0);
        dfx = df(x0);
        
        if (fabs(dfx) < 1e-10) {
            fout << "\nError: Derivative is zero. Cannot continue." << endl;
            return;
        }
        
        x1 = x0 - fx / dfx;
        
        fout << i << "\t" << x0 << "\t" << fx << "\t" 
             << dfx << "\t" << x1 << endl;
        
        if (fabs(x1 - x0) < tolerance) {
            fout << "\nConvergence achieved!" << endl;
            x0 = x1;
            break;
        }
        
        if (fabs(fx) < tolerance) {
            fout << "\nRoot found (f(x) ~ 0)!" << endl;
            break;
        }
        
        x0 = x1;
    }
    
    fout << "\nRoot found at x = " << x0 << endl;
    fout << "Function value at root: f(" << x0 << ") = " << f(x0) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    double x0, tolerance;
    int maxIter;
    
    fin >> x0;
    fin >> tolerance;
    fin >> maxIter;
    
    newtonRaphson(fout, x0, tolerance, maxIter);
    
    fin.close();
    fout.close();
    
    return 0;
}
