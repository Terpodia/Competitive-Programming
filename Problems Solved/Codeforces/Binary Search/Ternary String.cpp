#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

#define SZ(x) (int)x.size()
#define FOR(i,x,n) for(int i = (x); i < (int)(n); i++)

const int INF = 1e9;

string s;
vi pref[3];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

vi build_psum(char x) {
    vi a(SZ(s),0);
    FOR(i,0,SZ(a)) if(x == s[i])
        a[i]=1;

    vi ret(SZ(a)+1,0);
    FOR(i,1,SZ(a)+1) ret[i] = ret[i-1] + a[i-1];
    return ret;
}

int bs(int i, int id1, int id2) {
    int l=i, r=SZ(s)-1;

    if(pref[id1][r+1] - pref[id1][i] == 0 || pref[id2][r+1] - pref[id2][i] == 0) 
        return INF;

    while(r > l) {
        int mid = l + (r-l)/2;
        if(pref[id1][mid+1] - pref[id1][i] > 0 && pref[id2][mid+1] - pref[id2][i] > 0)
            r = mid;
        else
            l = mid+1;
    }
    return r-i+1;
}

int main() {
    fastIO();
    int t; cin >> t;

    while(t--) {
        cin >> s; 
        pref[0] = build_psum('1');
        pref[1] = build_psum('2');
        pref[2] = build_psum('3');

        int ans=INF;

        FOR(i,0,SZ(s)) {
            if(s[i] == '1') ans = min(ans, bs(i,1,2));
            else if(s[i] == '2') ans = min(ans, bs(i,0,2));
            else ans = min(ans, bs(i,0,1));
        }

        (ans == INF)? cout << "0\n" : cout << ans << "\n";
    }

    return 0;
}

