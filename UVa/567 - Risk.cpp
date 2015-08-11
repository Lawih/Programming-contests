#include <bits/stdc++.h>
#define pb      push_back
#define N       22
#define eol     '\n'

using namespace std;
typedef vector<int> vi;
typedef vector<vi> graph;

graph G;
int value[N];
bool done = 0;

void bfs( int f, int b ){
    //cout << f;
    queue<int> Q;
    Q.push(f);
    value[f] = 0;

    while( !Q.empty() && !done ){
        int u = Q.front();
        Q.pop();
        for( int i = 0; i < G[u].size(); ++i ){
            int v = G[u][i];
            if( !value[v] ){
                value[v] += value[u] + 1;
                Q.push(v);
                done = b == v;
            }
        }
    }
    done = 0;
}

void read( int u, int n ){
    int v;
    for( int i = 0; i < n; ++i ){
        cin >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

int main(){
    int n, c = 0;
    while( cin >> n ){
        int m;
        G = graph( 21 );
        for( int i = 1; i < 19; ++i )
            read( i, n ), cin >> n;
        read( 19, n );

        cout << "Test Set #" << ++c << eol;
        cin >> m;
        for( int i = 0; i < m; ++i ){
            int a, b;
            memset( value, 0, sizeof value );
            cin >> a >> b;
            bfs( a, b );
            printf( "%2d to %2d: %d\n", a, b, value[b] );
        }
        cout << eol;
    }
}

