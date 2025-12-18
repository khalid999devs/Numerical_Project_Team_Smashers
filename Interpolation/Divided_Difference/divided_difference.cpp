#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fout << setprecision(3) << fixed;

    int t;
    fin >> t;

    for (int tc = 1; tc <= t; tc++) {
        fout << "Test case #" << tc << ":\n";

        int n;
        fin >> n;

        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) fin >> x[i];
        for (int i = 0; i < n; i++) fin >> y[i];

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
            }
        }

        int q;
        fin >> q;

        fout << "Given points (x, y):\n";
        for (int i = 0; i < n; i++)
            fout << setw(6) << x[i] << "  " << setw(6) << y[i] << "\n";

        fout << "\nDivided Difference Table:\n";

        // Header
        fout << setw(2) << "i" << "   " << setw(8) << "x[i]" << "   " << setw(8) << "f[xi]";
        for (int j = 1; j < n; j++) {
            fout << "   " << setw(12) << "f[x0";
            for (int k = 1; k <= j; k++) fout << ",x" << k;
            fout << "]";
        }
        fout << "\n";

        // Table values
        for (int i = 0; i < n; i++) {
            fout << setw(2) << i << "   ";
            fout << setw(8) << x[i] << "   ";
            for (int j = 0; j < n - i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";
        for (int qi = 0; qi < q; qi++) {
            double xq;
            fin >> xq;

            double result = diff[0][0];
            for (int i = 1; i < n; i++) {
                double term = 1.0;
                for (int j = 0; j < i; j++)
                    term *= (xq - x[j]);
                result += term * diff[0][i];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}
