#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define N 760
#define M 1005

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

bool seen[N];
ii town[N];

ll dist( ii a, ii b ){
    return (b.first - a.first) * (b.first - a.first)
        + (b.second - a.second) * (b.second - a.second);
}

struct edge{
    int u, v;
    ll d;
    edge( int u, int v, ll d ): u(u), v(v), d(d) { }

    bool operator < ( const edge& other ) const {
        return d < other.d;
    }
};

vector<edge> out;
ll G[N][N];

void prim( int n, edge e ){
    priority_queue<edge> q;
    int c = n;
    q.push(e);
    while( !q.empty() && c-- ){
        edge a = q.top(); q.pop();
        if ( seen[a.v] ){
            ++c; continue;
        }
        seen[a.v] = 1;
        if( a.d != 0 )
            out.pb(a);
        for( int i = 0; i < n; ++i )
            if ( G[a.v][i] < 1 && !seen[i] )
                q.push( edge( a.v, i, G[a.v][i] ) );
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m;
    cin >> t;
    while ( t-- ){
        memset( seen, 0, sizeof seen );
        out.clear();
        int x, y, source = 0;
        cin >> n;
        for( int i = 0; i < n; ++i ){
            cin >> x >> y;
            town[i] = mp( x, y );
        }
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                G[i][j] = 1;

        cin >> m;
        for( int i = 0; i < m; ++i ){
            cin >> x >> y;
            x--, y--;
            G[x][y] = 0;
            G[y][x] = 0;
            source = y;
        }

        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                if( G[i][j] == 1 && i != j )
                    G[i][j] = -dist( town[i], town[j] );

        prim( n, edge( source, source, 0 ) );

        if ( out.size() < 1 )
            cout << "No new highways need" << '\n';
        else
            for( int i = 0; i < out.size(); ++i )
                cout << out[i].u + 1 << ' ' << out[i].v + 1 << '\n';
        if( t ) cout << '\n';
    }
}
