#include <iostream>
#include <map>

using namespace std;
typedef map<string, string> mss;
typedef map<string, int> msi;

mss parent;
msi rank;

string find( string node ){
    if( node ==  parent[node]) return node;
    return parent[node] = find( parent[node] );
}

void merge( string u, string v ){
    u = find(u);
    v = find(v);

    if( u != v ){
        parent[v] = u;
        int &r = rank[v];
        if( r == 0 ) rank[u]++;
        else rank[u] += r + 1;
    }
}

int main(){
    int nTest;
    cin >> nTest;

    while( nTest-- ){
        int f;
        string f1, f2;
        cin >> f;
        parent.clear();
        rank.clear();

        for( int i = 0; i < f; ++i ){
            cin >> f1 >> f2;
            if( parent[f1] == "" )
                parent[f1] = f1;
            if( parent[f2] == "" )
                parent[f2] = f2;
            merge( f1, f2 );
            cout << rank[find(f1)] + 1 << "\n";
        }
    }
}
