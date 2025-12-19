#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout<<fixed<<setprecision(6);

    int t;
    fin>>t;

    for (int i=1; i<=t;i++) {
        fout << "Test case #" <<i<< ":\n";

        int n;
        fin >> n;
        vector<double> x(n), y(n);
        for (int i = 0; i < n; i++) fin >> x[i];
        for (int i = 0; i < n; i++) fin >> y[i];

        vector<vector<double>> diff(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++)
            diff[i][0] = y[i];

        for (int j = 1; j < n; j++)
            {
            for (int i = 0; i < n - j; i++)
            {
                diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
            }
        }

        double h = x[1] - x[0];
        double first_derivative = 0.0;
        for (int i = 1; i < n; i++)
        {
            first_derivative += pow(-1, i - 1) * diff[0][i] / i;
        }
        first_derivative /= h;

        double second_derivative = 0.0;
        if (n >= 3)
        {
            second_derivative = diff[0][2];
            if (n >= 4) second_derivative -= diff[0][3];
            if (n >= 5) second_derivative += (11.0 / 12.0) * diff[0][4];
            second_derivative /= (h * h);
        }

        fout << "First derivative at x = " << x[0] << " : " << first_derivative << "\n";
        fout << "Second derivative at x = " << x[0] << " : " << second_derivative << "\n\n";
    }

    return 0;
}
