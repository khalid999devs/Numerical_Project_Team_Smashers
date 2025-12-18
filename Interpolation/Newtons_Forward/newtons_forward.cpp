#include<bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout << setprecision(6);

    int t;
    fin >> t;
    for (int i = 1; i <= t; ++i) {
        fout << "Test case #" <<i<< ":\n";

        int n;fin >> n;
        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++)
            fin>>x[i];
        for (int i = 0; i < n; i++)
            fin>>y[i];

        double h = x[1] - x[0];
        bool equal_spaced = true;

        for (int i = 2; i < n; i++)
            {

            double expected = x[0] + i * h;
            if (fabs(x[i] - expected) > 1e-6) {
                equal_spaced = false;
                break;
            }
        }

        if (!equal_spaced) {
            fout << "x-values are not equally spaced.\n\n";
            continue;
        }

        vector<vector<double>> diff(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++) diff[i][0] = y[i];

        for (int j = 1; j < n; j++)
            {
            for (int i = 0; i + j < n; i++)
            {
                diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
            }
        }

        int q;
        fin >> q;
        fout << "Given points (x, y):\n";
        for (int i = 0;i<n; i++)
            fout << "  " << x[i] << "  " << y[i] << "\n";

        fout << "Step size h = " << h << "\n\n";

        fout << "Forward Difference Table:\n";
        fout << "i        x[i]         y";
        for (int j = 1; j < n; j++) fout << "         Δ^" << j << "y";
        fout << "\n";

        for (int i = 0; i < n; i++) {
            fout << setw(2) << i << "   ";
            fout << setw(10) << x[i] << "   ";
            for (int j = 0; j < n - i; j++)
                fout << setw(12) << diff[i][j];
            fout << "\n";
        }

        fout << "\nInterpolated values:\n";

        for (int i=0; i<q;i++) {
            double xq;
            fin >> xq;

            double s = (xq - x[0]) / h;
            double result = diff[0][0];

            double numer = 1.0;
            double denom_fact = 1.0;

            for (int k = 1; k < n; k++) {
                numer *= (s - (k - 1));
                denom_fact *= k;
                result += (numer / denom_fact) * diff[0][k];
            }

            fout << "  P(" << xq << ") = " << result << "\n";
        }

        fout << "\n";
    }

    return 0;
}
