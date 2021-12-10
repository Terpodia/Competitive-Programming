#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e5;

int n, m;
string a[MAXN], b[MAXN];

string solve() { 
    string ret="";
    int cnt[m][26];
    memset(cnt, 0, sizeof(cnt));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cnt[j][a[i][j]-'a']++;

    for(int i=0; i<n-1; i++)
        for(int j=0; j<m; j++)
            cnt[j][b[i][j]-'a']++;

    for(int i=0; i<m; i++) {
        for(int j=0; j<26; j++) {
            if(cnt[i][j] % 2) ret.push_back((char)(j+'a'));
        }
    }

    return ret;
}

int main() {
    int t; cin >> t;

    while(t--) { 
        cin >> n >> m; 
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n-1; i++) cin >> b[i];

        cout << solve() << "\n";
    }

    return 0;
}
