#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> graph;

#define pb      push_back

const int N = 103;
bool seen[N];
graph adjList;
vi topoSort;

void dfs( int u ){
    seen[u] = 1;
    for( int i = 0; i < adjList[u].size(); ++i )
        if( !seen[adjList[u][i]] )
            dfs( adjList[u][i] );
    topoSort.pb( u );
}

int main(){
    int m, n;
    while( cin >> n >> m && !( m == 0 && n == 0 ) ){
        int i;
        topoSort.clear();
        adjList = graph( n + 1 );
        memset( seen, 0, sizeof seen );

        for( i = 0; i < m; ++i ){
            int u, v;
            cin >> u >> v;
            adjList[u].pb(v);
        }

        for( i = 1; i <= n; ++i )
            if( !seen[i] )
                dfs( i );

        for( i = topoSort.size()-1; i > 0; --i )
            cout << topoSort[i] << ' ';
        cout << topoSort[0] << '\n';
    }
}
