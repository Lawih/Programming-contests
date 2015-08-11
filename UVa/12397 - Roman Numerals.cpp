#include <bits/stdc++.h>
#define N 8

using namespace std;

map<int, int> matches;
int rom[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

void fill(){
    matches[1] = 1;
    matches[4] = 3;
    matches[5] = 2;
    matches[9] = 3;
    matches[10] = 2;
    matches[40] = 4;
    matches[50] = 2;
    matches[90] = 4;
    matches[100] = 2;
    matches[400] = 5;
    matches[500] = 3;
    matches[900] = 6;
    matches[1000] = 4;
}

int main(){
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int n;
    fill();
    while( cin >> n ){
        int ans = 0;
        for( int i = 12; i >= 0; --i )
            while ( n/rom[i] >= 1 ){
                ans += matches[rom[i]];
                n -= rom[i];
            }
        cout << ans << '\n';
    }
}
