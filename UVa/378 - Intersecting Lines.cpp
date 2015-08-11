#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;
typedef pair<int, int> ii;

struct line{
    ii start, ending;
    int A, B, C;

    line( ii a, ii b ): start(a), ending(b){
        A = ending.y - start.y;
        B = start.x - ending.x;
        C = A * start.x + B * start.y;
    }

    line(){}

    void intersects( line &other ){
        int det = A * other.B - other.A * B;
        if( !det ) {
            int D = other.start.y - start.y;
            int E = start.x - other.start.x;
            det = A * E - D * B;
            if( det == 0 )
                cout << "LINE\n";
            else cout << "NONE\n";
            return;
        }
        double x = (double) (other.B * C - B * other.C) / det;
        double y = (double) (A * other.C - other.A * C) / det;
        cout << "POINT " << fixed << setprecision(2) << x << ' ' << y << '\n';
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT\n";

    for( int i = 0; i < n; ++i ){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        line line_a = line( mp(a, b), mp(c,d) );

        cin >> a >> b >> c >> d;
        line line_b = line( mp(a, b), mp(c,d) );

        line_a.intersects( line_b );
    }

    cout << "END OF OUTPUT\n";
}
