#include <bits/stdc++.h>
#define N   10004
#define pb  push_back
#define mp  make_pair
#define INF 0x7fffffff

using namespace std;

struct number{
    int n, mod;
    bool odd;
    number( int n, int &m ): n(n){
        odd = n & 1;
        int tmp = n;
        if( n < 0 )
            tmp * -1;
        mod = tmp % m;
    }
    number(){}

    bool operator < ( const number& o ) const{
        if( mod == o.mod )
            if( odd && !o.odd )
                return 1;
            else if ( odd && o.odd )
                return n > o.n;
            else if ( !odd && !o.odd )
                return n < o.n;
        return mod < o.mod;
    }
}num[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while( cin >> n >> m ){
        if( n + m == 0 ) break;
        int r;
        for( int i = 0; i < n; ++i ){
            cin >> r;
            num[i] = number( r, m );
        }
        sort( num, num + n );
        cout << n << ' ' << m << '\n';
        for( int i = 0; i < n; ++i )
            cout << num[i].n << '\n';
    }
    cout << 0 << ' ' << 0 << '\n';
}
