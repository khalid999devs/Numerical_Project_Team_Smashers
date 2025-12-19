#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<double>x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    double sumX=0,sumY=0,sumXY=0,sumX2=0;

    for(int i=0;i<n;i++){
        sumX  +=x[i];
        sumY  +=y[i];
        sumXY +=x[i]*y[i];
        sumX2 +=x[i]*x[i];
    }

    double b =(n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double a = (sumY - b*sumX) / n;

    cout<<fixed<<setprecision(6);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"Model: y = "<<a<<" + "<<b<<"x"<<endl;

    return 0;
}

