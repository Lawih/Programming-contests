#include <bits/stdc++.h>
#define N   100004
#define pb  push_back

using namespace std;

int dp[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    string line;
    getline(cin, line);
    while( t-- ){
        vector<string> dict;
        vector<string> d_sorted;
        vector<string> words;
        vector<string> w_sorted;
        vector<string> ans;
        map<string, string> all;

        getline(cin, line);
        istringstream iss(line);
        while( iss >> line ){
            dict.pb( line );
            sort( line.begin(), line.end() );
            d_sorted.pb( line );
        }

        getline(cin, line);
        istringstream ss(line);
        while( ss >> line ){
            words.pb( line );
            sort( line.begin(), line.end() );
            w_sorted.pb( line );
        }

        for( int i = 0; i < words.size(); ++i ){
            if( all.count(words[i]) < 1 )
                for( int j = 0; j < dict.size(); ++j )
                    if( words[i].size() == dict[j].size() ){
                        int ln = words[i].size() - 1;
                        if( words[i][0] == dict[j][0] && words[i][ln] == dict[j][ln] )
                            if( w_sorted[i] == d_sorted[j] ){
                                all[words[i]] = dict[j];
                                break;
                            }
                    }
            if( all.count(words[i]) < 1 )
                all[words[i]] = words[i];
            ans.pb( all[words[i]] );
        }

        for( int i = 0; i < ans.size(); ++i ){
            cout << ans[i];
            if( i < ans.size() - 1 ) cout << ' ';
        }
        cout << '\n';
    }
}
