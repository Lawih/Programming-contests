#include <bits/stdc++.h>
#define N   104
#define MOD 1000000

using namespace std;
typedef long long ll;

ll dp[N][N];

int sum( int n, int k ){
    if( n < 0 ) return 0;
    if( k == 1 ) return 1;

    ll &a = dp[n][k];
    if( a != -1) return a;
    ll ans = 0;
    for( int i = 0; i <= n; ++i ){
        a = sum( n - i, k - 1 );
        ans = ( a + ans ) % MOD;
    }
    return a = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    while( cin >> n >> k ){
        if( n + k == 0 ) break;
        memset( dp, -1, sizeof dp );
        cout << sum( n, k ) << '\n';
    }
}
