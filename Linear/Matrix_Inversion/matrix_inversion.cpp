#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++)
        {
        int n;
        fin >> n;

        vector<vector<double>> a(n, vector<double>(n));
        vector<vector<double>> inv(n, vector<double>(n, 0.0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fin >> a[i][j];
            }
            inv[i][i] = 1.0;
        }

        bool singular = false;

        for (int i = 0; i < n; i++)
            {
            if (fabs(a[i][i]) < 1e-9)
            {
                singular = true;
                break;
            }

            double pivot = a[i][i];
            for (int j = 0; j < n; j++)
            {
                a[i][j] /= pivot;
                inv[i][j] /= pivot;
            }

            for (int j = 0; j < n; j++)
                {
                if (j != i) {
                    double ratio = a[j][i];
                    for (int k = 0; k < n; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                        inv[j][k] -= ratio * inv[i][k];
                    }
                }
            }
        }

        fout << "Test Case " << i << ":\n";
        if (singular) {
            fout << "Matrix is singular and cannot be inverted.\n";
        } else {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    fout << fixed << setprecision(6) << inv[i][j] << " ";
                }
                fout << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}
