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

        double a[n][n + 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                fin >> a[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            double pivot = a[i][i];

            for (int j = 0; j <= n; j++)
            {
                a[i][j] /= pivot;
            }

            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    double ratio = a[j][i];
                    for (int k = 0; k <= n; k++)
                    {
                        a[j][k] -= ratio * a[i][k];
                    }
                }
            }
        }

        fout << "Test Case " << i << ":\n";
        for (int i = 0; i < n; i++)
        {
            fout << "Value of x" << i + 1 << " = " << a[i][n] << endl;
        }
    }

    fin.close();
    fout.close();

    return 0;
}
