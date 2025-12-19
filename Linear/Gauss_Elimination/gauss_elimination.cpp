#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        fin >> n;

        double a[n][n + 1], x[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                double ratio = a[j][i] / a[i][i];
                for (int k = 0; k <= n; k++)
                {
                    a[j][k] -= ratio * a[i][k];
                }
            }
        }

        x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            x[i] = a[i][n];
            for (int j = i + 1; j < n; j++)
            {
                x[i] -= a[i][j] * x[j];
            }
            x[i] /= a[i][i];
        }


        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++)
            {
            fout << "Value of x" << i + 1 << " = " << x[i] << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
