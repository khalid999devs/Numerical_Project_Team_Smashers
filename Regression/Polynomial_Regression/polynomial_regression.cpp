#include <bits/stdc++.h>
using namespace std;


vector<double>solveGaussian(vector<vector<double>>A,vector<double>B){
    int n=A.size();

    for(int i=0;i<n;i++)
        A[i].push_back(B[i]);

    for(int i=0;i<n;i++){
        double pivot=A[i][i];
        for(int j=0;j<=n;j++) A[i][j] /= pivot;


        for(int k = 0; k < n; k++){
            if(k == i) continue;
            double factor= A[k][i];
            for(int j=0;j<=n;j++)
                A[k][j] -= factor*A[i][j];
        }
    }


    vector<double>x(n);
    for(int i=0;i<n;i++)
        x[i]=A[i][n];

    return x;
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<double>x(n),y(n);
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];


    vector<vector<double>> A(m+1,vector<double>(m+1,0));
    vector<double> B(m+1,0);


    vector<double> S(2*m+1,0);
    for(int i=0;i<n;i++){
        double xi=1;
        for(int k=0;k<=2*m;k++){
            S[k] += xi;
            xi *= x[i];
        }
    }


    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            A[i][j] = S[i+j];


    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++)
            B[i] += y[j]*pow(x[j], i);
    }


    vector<double> coeff=solveGaussian(A,B);


    cout<<fixed<<setprecision(6);
    cout<<"Fitted Polynomial:y = ";
    for(int i=0;i<=m;i++){
        cout<<coeff[i];
        if(i>=1) cout<<"x^"<<i;
        if(i!=m) cout<<" + ";
    }
    cout<<endl;

    return 0;
}
