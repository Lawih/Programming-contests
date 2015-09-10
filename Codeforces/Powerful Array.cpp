#include <bits/stdc++.h>
#define N       200004
#define MAX     1000006

using namespace std;

int sq, num[N], cont[MAX];
long long total = 0, ans[N];

struct query{
    int l, r, idx, b;
    query(){}
    query( int l, int r, int idx ): l(l), r(r), idx(idx) {
        b = l/sq;
    }

    bool operator < ( const query &other ) const {
        if ( other.b == b )
            return r < other.r;
        return b < other.b;
    }
}queries[N];

void add( int index ){
    total += 2 * cont[ num[index] ] * num[index] + num[index];
	++cont[ num[index] ];
}

void remove( int index ){
    --cont[ num[index] ];
	total -= 2 * cont[ num[index] ] * num[index] + num[index];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t, l, r;
    cin >> n >> t;
    sq = sqrt(n);
    for( int i = 0; i < n; ++i )
        cin >> num[i];

    for( int i = 0; i < t; ++i ){
        cin >> l >> r;
        queries[i] = query( l-1, r-1, i );
    }

    sort( queries, queries + t );

    l = r = 0;
    total = num[0];
    ++cont[num[0]];
    for( int i = 0; i < t; ++i ){
        query q = queries[i];
        if( q.l == q.r ){
            ans[q.idx] = num[q.l];
            continue;
        }

        while( l < q.l ){
            remove(l);
            ++l;
        }

        while( r > q.r ){
            remove(r);
            --r;
        }

        while( l > q.l ){
            --l;
            add(l);
        }

        while( r < q.r ){
            ++r;
            add(r);
        }

        ans[q.idx] = total;
    }

    for( int i = 0; i < t; ++i )
        cout << ans[i] << '\n';
}

