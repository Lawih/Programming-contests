#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define N 103
#define M 5000
#define endl '\n'
using namespace std;
typedef pair<int, int> ii;
typedef vector<vector<int> > graph;

bool seen[N];

int dfs( int node, graph &G ){
    stack<int> s;
    int cnt = 0;
    s.push(node);
    seen[node] = 1;

    while( !s.empty() ){
        int u = s.top(); s.pop();
        for( int i = 0; i < G[u].size(); ++i ){
            int v = G[u][i];
            if( !seen[v] ){
                s.push(v);
                seen[v] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while ( cin >> n && n ){
        int t, a, mx = -1, mx_i;
        graph G(n);
        memset( seen, 0, sizeof seen );
        for( int i = 0; i < n; ++i ){
            cin >> t;
            for( int j = 0; j < t; ++j ){
                cin >> a;
                --a;
                G[i].pb(a);
            }
        }

        for( int i = 0; i < n; ++i ){
            memset( seen, 0, sizeof seen );
            int ans = dfs(i, G);
            if( ans > mx ){
                mx = ans;
                mx_i = i+1;
            }
        }

        cout << mx_i << endl;
    }
}

/*
6
0
2 1 3
0
1 6
1 4
0
0

*/
