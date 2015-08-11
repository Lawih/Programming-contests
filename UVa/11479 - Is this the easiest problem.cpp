#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 0x7fffffff

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, p = 0;
    ll a, b, c;
    cin >> t;
    while( t-- ){
        cin >> a >> b >> c;
        cout << "Case " << ++p << ": ";
        if( !(a + b > c && a + c > b && b + c > a) ){
            cout << "Invalid" << '\n';
            continue;
        }

        if( a == b && b == c ){
            cout << "Equilateral" << '\n';
            continue;
        }

        if( a == b || a == c || b == c ){
            cout << "Isosceles" << '\n';
            continue;
        }

        cout << "Scalene" << '\n';
    }
}
