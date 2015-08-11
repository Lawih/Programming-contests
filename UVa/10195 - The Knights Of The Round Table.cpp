#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double a, b, c;
    while( cin >> a >> b >> c ){
        double s = (a + b + c)/2;
        double A = sqrt( s*(s-a)*(s-b)*(s-c) );
        if( !s ) s = 1.0;
        double r = A/s;
        cout << "The radius of the round table is: ";
        cout << fixed << setprecision(3) << r << '\n';
    }
}
