#include <bits/stdc++.h>
#define N   104
#define M   1005

using namespace std;
typedef long long ll;

string word[N];
string rule[M];
int n, m;

void password( string s, string &r, int pos ){
    if( r.size() == pos ){
        cout << s << '\n';
        return;
    }
    if( r[pos] == '#' ){
        for( int i = 0; i < n; ++i )
            password( s + word[i], r, pos + 1 );
        return;
    }

    for( int i = 0; i < 10; ++i ){
        char a = i + 48;
        password( s + a, r, pos + 1 );
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while( cin >> n ){
        for( int i = 0; i < n; ++i )
            cin >> word[i];
        cin >> m;
        for( int i = 0; i < m; ++i )
            cin >> rule[i];

        for( int i = 0; i < m; ++i ){
            cout << "--\n";
            password( "", rule[i], 0 );
        }
    }
}

