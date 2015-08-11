#include <bits/stdc++.h>
#define N   103

using namespace std;

int area[N][N];
int r, c;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int go( int x, int y, int w ){
    int cnt  = 0;
    int ans = 0;
    for( int i = 0; i < 4; ++i ){
        int a = dx[i] + x;
        int b = dy[i] + y;
        if( a >= 0 && a < c && b >= 0 && b < r && area[y][x] > area[b][a] ){
            ans = max( go( a, b, w + 1 ), ans );
            ++cnt;
        }
    }
    if( !cnt )
        return w;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while( t-- ){
        string name;
        cin >> name;
        cin >> r >> c;
        for( int i = 0; i < r; ++i )
            for( int j = 0; j < c; ++j )
                cin >> area[i][j];

        int ans = 0;
        for( int i = 0; i < r; ++i )
            for( int j = 0; j < c; ++j )
                ans = max(ans, go( j, i, 1 ) );

        cout << name << ':' << ' ' << ans << '\n';
    }
}

