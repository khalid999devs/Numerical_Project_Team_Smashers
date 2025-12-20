#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void secantMethod(ofstream &fout, double x0, double x1, double tolerance, int maxIter) {
    fout << fixed << setprecision(6);
    
    double x2, f0, f1;
    
    for (int i = 1; i <= maxIter; i++) {
        f0 = f(x0);
        f1 = f(x1);
        
        if (fabs(f1 - f0) < 1e-10) {
            fout << "\nError: Division by zero encountered!" << endl;
            return;
        }
        
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        
        fout << i << "\t" << x0 << "\t" << x1 << "\t" 
             << x2 << "\t" << f(x2) << endl;
        
        if (fabs(x2 - x1) < tolerance) {
            fout << "\nConvergence achieved!" << endl;
            break;
        }
        
        x0 = x1;
        x1 = x2;
    }
    
    fout << "\nRoot found at x = " << x2 << endl;
    fout << "Function value at root: f(" << x2 << ") = " << f(x2) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    double x0, x1, tolerance;
    int maxIter;
    
    fin >> x0;
    fin >> x1;
    fin >> tolerance;
    fin >> maxIter;
    
    secantMethod(fout, x0, x1, tolerance, maxIter);
    
    fin.close();
    fout.close();
    
    return 0;
}
