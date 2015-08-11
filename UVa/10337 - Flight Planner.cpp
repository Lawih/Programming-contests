#include <bits/stdc++.h>
#define pb      push_back
#define mp      make_pair
#define MAX     1021
#define INF     0x3fffffff


using namespace std;
typedef long long ll;

int dp[10][MAX];
int wind[10][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, x;
    cin >> T;
    while ( T-- ) {
        cin >> x;
        x /= 100;

        for ( int i = 9; i >= 0; --i )
            for ( int j = 0; j < x; ++j )
                cin >> wind[i][j];

        for ( int i = 1; i < 10; ++i ) dp[i][0] = INF;
        dp[0][0] = 0;

        for ( int j = 1; j <= x; ++j )
            for ( int i = 0; i < 10; ++i ) {
                dp[i][j] = dp[i][j - 1] - wind[i][j - 1] + 30;
                if ( i + 1 < 10 ) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] - wind[i + 1][j - 1] + 20);
                if ( i - 1 >= 0 ) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] - wind[i - 1][j - 1] + 60);
            }

        cout << dp[0][x] << '\n' << '\n';
    }
}
