#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define N 3

using namespace std;
typedef pair<int, int> ii;

map<char, ii> ids;
int board[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void fill(){
    char a = 'a';
    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 3; ++j, ++a )
            ids[a] = mp(i, j);
}

void print(){
    for( int i = 0; i < 3; ++i ){
        for( int j = 0; j < 3; ++j ){
            cout << board[i][j];
            if (j < 2) cout << ' ';
        }
        cout << '\n';
    }
}

void move( ii cell ){
    board[cell.x][cell.y] = (board[cell.x][cell.y] + 1) % 10;
    for( int i = 0; i < 4; ++i ){
        int x = cell.x + dx[i];
        int y = cell.y + dy[i];
        if ( -1 < x && x < 3 && -1 < y && y < 3 )
            board[x][y] = (board[x][y] + 1) % 10;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    string s;
    fill();
    int c = 0;
    while( getline(cin, s) ){
        cout << "Case #" << ++c << ":\n";
        memset( board, 0, sizeof board );
        for( int i = 0; i < s.length(); ++i )
            move( ids[s[i]] );
        print();
    }
}
