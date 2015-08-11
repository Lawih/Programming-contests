#include <bits/stdc++.h>
#define N   20004
#define pb  push_back
#define mp  make_pair
#define INF 0x7fffffff

using namespace std;

int dragon[N], knight[N];
bool ok = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while( cin >> n >> m ){
        if( n + m == 0 ) break;
        long long ans = 0;
        for( int i = 0; i < n; ++i )
            cin >> dragon[i];
        for( int i = 0; i < m; ++i )
            cin >> knight[i];

        sort( dragon, dragon + n );
        sort( knight, knight + m );

        int c = 0;
        for( int i = 0; i < n; ++i ){
            ok = 0;
            for( int j = c; j < m; ++j )
                if( dragon[i] <= knight[j] ){
                    ans += knight[j];
                    c = j + 1;
                    ok = 1;
                    break;
                }
            if( !ok ) break;
        }

        if ( ok ) cout << ans;
        else cout << "Loowater is doomed!";
        cout << '\n';
    }
}
