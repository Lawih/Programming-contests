#include <bits/stdc++.h>
#define pb       push_back
#define MAX      10
#define INF      100000000

using namespace std;

int n, x[MAX], y[MAX];
double d[MAX][MAX];

double sqr ( int x ) { return x * x; }
double dist ( int i, int j ) {
    return sqrt( sqr(x[i] - x[j]) + sqr(y[i] - y[j]) );
}

double dp[MAX][1 << MAX];
double next[MAX][1 << MAX];

int all;
double tsp ( int c, int state ) {
    if ( state == all ) return 0;
    double &r = dp[c][state];
    if ( r == -1 ) {
        r = INF;
        for ( int i = 0; i < n; ++i )
            if ( !(state & (1 << i)) ) {
                double s = tsp(i, state | (1 << i)) + d[c][i];
                if ( s < r ) {
                    r = s;
                    next[c][state] = i;
                }
            }
    }

    return r;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.precision(2);

    int t = 0;
    while ( cin >> n && n ) {
        for ( int i = 0; i < n; ++i ) {
            cin >> x[i] >> y[i];
            for ( int j = 0; j <= i; ++j )
                d[i][j] = d[j][i] = dist(i, j);
        }

        all = (1 << n) - 1;
        for ( int i = 0; i < n; ++i )
            for ( int j = 0; j < all; ++j)
                dp[i][j] = -1;

        dp[8][0] = -1;
        double ans = tsp(8, 0);
        cout << "**********************************************************\n";
        cout << "Network #" << ++t << '\n';

        int p = next[8][0], state = 0, q;
        for ( int i = 1; i < n; ++i ) {
            state |= 1 << p;
            q = next[p][state];
            cout << "Cable requirement to connect (" << x[p] << "," << y[p] << ") to (" << x[q] << "," << y[q] << ") is " << d[p][q] + 16 << " feet.\n";
            p = q;
        }

        cout << "Number of feet of cable required is " << ans + 16 * (n - 1) << ".\n";
    }
}
