#include<bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return x + y;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    double x0, y0, x, h;
    
    fin >> x0;
    fin >> y0;
    fin >> x;
    fin >> h;
    
    int n = (int)((x - x0) / h);
    double y = y0;
    
    fout << fixed << setprecision(6);
    
    for (int i = 1; i <= n; i++) {
        double k1 = h * f(x0, y);
        double k2 = h * f(x0 + h/2.0, y + k1/2.0);
        double k3 = h * f(x0 + h/2.0, y + k2/2.0);
        double k4 = h * f(x0 + h, y + k3);
        
        fout << i << "\t" << x0 << "\t" << y << "\t" << k1 << "\t" << k2 << "\t" << k3 << "\t" << k4 << endl;
        
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x0 = x0 + h;
    }
    
    fout << "\nRoot: " << y << endl;
    
    fin.close();
    fout.close();
    
    return 0;
}
