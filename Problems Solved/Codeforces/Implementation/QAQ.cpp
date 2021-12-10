#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();
    string s; cin >> s;
    vi suff(sz(s), 0); 
    suff[sz(s)-1] = (s[sz(s)-1] == 'Q')? 1 : 0;
    
    for(int i = sz(s)-2; i>=0; i--) {
        suff[i] = suff[i+1];
        if(s[i] == 'Q') suff[i]++;
    }

    int cnt=0, ans=0;

    for(int i=0; i<sz(s); i++) {
        if(s[i] == 'Q') cnt++;
        else if(s[i] == 'A') ans += cnt * suff[i];
    }

    cout << ans << "\n";

    return 0;
}
