#include <iostream>
using namespace std;

int n;
string s;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

void solve() {
    bool flag=false;
    for(char c : s) 
        if(c == '0') flag = true;

    if(!flag) {
        cout << "1 " << n/2 << " 2 " << 1+n/2 << "\n";
        return;
    }

    for(int i=1; i<=(n+1)/2; i++) {
        if(s[i-1] == '0') {
            cout << i << " " << i+n/2 << " " << i+1 << " " << i+n/2 << "\n";
            return;
        } 
    }

    for(int i=n; i>(n+1)/2; i--) {
        if(s[i-1] == '0') {
            cout << i-n/2 << " " << i << " " << i-n/2 << " " << i-1 << "\n";
            return;
        } 
    }
}

int main() {
    fastIO();
    int t; cin >> t;

    while(t--) {
        cin >> n >> s;   
        solve();
    }

    return 0;
}

