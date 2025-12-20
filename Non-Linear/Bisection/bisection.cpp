#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void bisection(ofstream &fout, double a, double b, double tolerance) {
    if (f(a) * f(b) >= 0) {
        fout << "Error: f(a) and f(b) must have opposite signs!" << endl;
        return;
    }
    
    fout << fixed << setprecision(6);
    
    double c;
    int iteration = 0;
    
    while ((b - a) >= tolerance) {
        iteration++;
        c = (a + b) / 2.0;
        
        fout << iteration << "\t" << a << "\t" << b << "\t" 
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
    
    fout << "\nRoot found at x = " << c << endl;
    fout << "Function value at root: f(" << c << ") = " << f(c) << endl;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    double a, b, tolerance;
    
    fin >> a;
    fin >> b;
    fin >> tolerance;
    
    bisection(fout, a, b, tolerance);
    
    fin.close();
    fout.close();
    
    return 0;
}
