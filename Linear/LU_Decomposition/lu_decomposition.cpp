#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++) 
        {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<vector<double>> L(n, vector<double>(n, 0.0));
        vector<vector<double>> U(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                fin >> a[i][j];
            }
        }

        vector<double> b(n);
        for (int i = 0; i < n; i++) 
        {
            fin >> b[i];
        }

        for (int i = 0; i < n; i++) 
            {
            for (int k = i; k < n; k++) 
            {
                double sum = 0;
                for (int j = 0; j < i; j++) sum += L[i][j] * U[j][k];
                U[i][k] = a[i][k] - sum;
            }
            for (int k = i; k < n; k++) 
            {
                if (i == k) L[i][i] = 1;
                else {
                    double sum = 0;
                    for (int j = 0; j < i; j++) sum += L[k][j] * U[j][i];
                    L[k][i] = (a[k][i] - sum) / U[i][i];
                }
            }
        }

        vector<double> y(n);
        for (int i = 0; i < n; i++) 
        {
            double sum = 0;
            for (int j = 0; j < i; j++) sum += L[i][j] * y[j];
            y[i] = b[i] - sum;
        }

        vector<double> x(n);
        for (int i = n - 1; i >= 0; i--) 
        {
            double sum = 0;
            for (int j = i + 1; j < n; j++) sum += U[i][j] * x[j];
            x[i] = (y[i] - sum) / U[i][i];
        }

        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++) {
            fout << "Value of x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}
