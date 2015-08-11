#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define N 103
#define INF 0x3fffffff

using namespace std;
typedef pair<int, int> ii;

struct edge{
    int u, v, w;
    edge( int u, int v, int w ):
        u(u), v(v), w(w) {}

    bool operator < ( const edge& other ) const {
        return w < other.w;
    }
};

int parent[N], rank[N];

int fill( int n ){
    ++n;
    for( int i = 0; i < n; ++i ){
        parent[i] = i;
        rank[i] = 0;
    }
}

bool is_mst( int n ){
    int c = 0; ++n;
    for( int i = 1; i < n; ++i )
        if( i == parent[i] )
            ++c;
    return c == 1;
}

int find( int u ){
    if( u == parent[u] ) return u;
    return parent[u] = find( parent[u] );
}

int merge( edge e ){
    int u = find(e.u);
    int v = find(e.v);
    if( u != v ) {
        if( rank[u] > rank[v] )
            parent[u] = v;
        else if ( rank[v] > rank[u] )
            parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
        return e.w;
    }
    return 0;
}

vector<edge> edges;
vector<int> used;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m;
    cin >> t;
    while( t-- ){
        cin >> n >> m;
        int x, y, z, s1 = 0, s2 = INF, tmp = 0;
        edges.clear();
        used.clear();
        fill(n);
        for( int i = 0; i < m; ++i ){
            cin >> x >> y >> z;
            edges.pb( edge( x, y, z ) );
        }
        sort( edges.begin(), edges.end() );
        for( int i = 0; i < m; ++i ){
            tmp = s1;
            s1 += merge( edges[i] );
            if( s1 != tmp ) used.pb( i );
        }

        for( int k = 0; k < used.size(); ++k ){
            fill(n);
            tmp = 0;
            for( int i = 0; i < m; ++i ){
                if ( i == used[k] ) continue;
                tmp += merge( edges[i] );
            }
            if ( !is_mst( n ) ) continue;
            s2 = min( s2, tmp );
        }
        cout << s1 << ' ' << s2 << '\n';
    }
}
