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
        sumX  += x[i];
        sumY  += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;

    fout << fixed << setprecision(6);
    fout << "a = " << a << endl;
    fout << "b = " << b << endl;
    fout << "Model: y = " << a << " + " << b << "x" << endl;

    fin.close();
    fout.close();

    return 0;
}

