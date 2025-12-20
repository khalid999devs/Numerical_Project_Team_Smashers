#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void falsePosition(ofstream &fout, double a, double b, double tolerance, int maxIter) {
    if (f(a) * f(b) >= 0) {
        fout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return;
    }
    
    fout << fixed << setprecision(6);
    
    double c, prev_c = 0;
    
    for (int i = 1; i <= maxIter; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        
        fout << i << "\t" << a << "\t" << b << "\t" 
             << c << "\t" << f(c) << endl;
        
        if (f(c) == 0.0) {
            fout << "\nExact root found!" << endl;
            break;
        }
        
        if (i > 1 && fabs(c - prev_c) < tolerance) {
            fout << "\nDesired accuracy achieved!" << endl;
            break;
        }
        
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        prev_c = c;
    }
    
    fout << "\nRoot found at x = " << c << endl;
    fout << "Function value at root: f(" << c << ") = " << f(c) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    double a, b, tolerance;
    int maxIter;
    
    fin >> a;
    fin >> b;
    fin >> tolerance;
    fin >> maxIter;
    
    falsePosition(fout, a, b, tolerance, maxIter);
    
    fin.close();
    fout.close();
    
    return 0;
}
