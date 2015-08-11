#include <bits/stdc++.h>
#define INF     0xfffffff

using namespace std;

const int MAX = 105;

int d[MAX][MAX], cost[MAX], costliest[MAX][MAX], p[MAX][MAX];

void floyd_warshall ( int n ) {
    for ( int k = 0; k < n; ++k )
        for ( int i = 0; i < n; ++i )
            for ( int j = 0; j < n; ++j ) {
                int i_k_j = d[i][k] + d[k][j] - costliest[i][k] - costliest[k][j] + max(costliest[i][k], costliest[k][j]);
                if ( i_k_j < d[i][j] ) {
                    d[i][j] = i_k_j;
                    costliest[i][j] = max(costliest[i][k], costliest[k][j]);
                    p[i][j] = p[k][j];
                }
            }
}

int main ( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, r, q, cases = 0, u, v, w;

    bool blank = false;

    while ( cin >> c >> r >> q ) {
        if ( c + r + q == 0 ) break;

        if ( blank ) cout << '\n';
        else blank = true;

        for ( int i = 0; i < c; ++i )
            cin >> cost[i];

        for ( int i = 0; i < c; ++i )
            for ( int j = 0; j < c; ++j ) {
                costliest[i][j] = 0;
                d[i][j] = INF;
                p[i][j] = -1;
            }

        for ( int i = 0; i < r; ++i ) {
            cin >> u >> v >> w;
            --u, --v;
            costliest[u][v] = max(cost[u], cost[v]);
            costliest[v][u] = max(cost[u], cost[v]);
            costliest[u][u] = cost[u];
            costliest[v][v] = cost[v];
            d[u][v] = w + costliest[u][v];
            d[v][u] = w + costliest[v][u];
            d[u][u] = cost[u];
            d[v][v] = cost[v];
            p[u][v] = u;
            p[v][u] = v;
        }

        floyd_warshall(c);
        floyd_warshall(c);

        cout << "Case #" << ++cases << '\n';
        while ( q-- ) {
            cin >> u >> v;
            --u, --v;
            cout << ( p[u][v] != -1 ? d[u][v] : -1 ) << '\n';
        }
    }
}
