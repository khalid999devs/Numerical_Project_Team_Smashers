#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int n;
    fin >> n;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
    }
    
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        double X = x[i];        // X = x
        double Y = log(y[i]);   // Y = ln(y)

        sumX += X;
        sumY += Y;
        sumXY += X * Y;
        sumX2 += X * X;
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double A = (sumY - b * sumX) / n;

    double a = exp(A);   // a = e^A

    fout << fixed << setprecision(6);
    fout << "a = " << a << endl;
    fout << "b = " << b << endl;
    fout << "Model: y = " << a << " * e^(" << b << "x)" << endl;

    fin.close();
    fout.close();

    return 0;
}
