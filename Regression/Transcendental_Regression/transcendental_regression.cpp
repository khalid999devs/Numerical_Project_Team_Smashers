#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<double>x(n),y(n);

    for(int i=0;i<n;i++){
        cin >> x[i] >> y[i];
      }
    double sumX=0,sumY=0,sumXY=0,sumX2=0;

    for(int i=0;i<n;i++){
        double X=x[i];        // X = x
        double Y=log(y[i]);   // Y = ln(y)

        sumX +=X;
        sumY +=Y;
        sumXY += X*Y;
        sumX2 += X*X;
    }

    double b =(n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX);
    double A =(sumY - b*sumX)/n;

    double a =exp(A);   // a = e^A

    cout<<fixed<<setprecision(6);
    cout<<"a= "<<a<<endl;
    cout<<"b= "<<b<<endl;
    cout<<"Model:y = "<<a<<"* e^("<<b<<"x)"<<endl;

    return 0;
}
