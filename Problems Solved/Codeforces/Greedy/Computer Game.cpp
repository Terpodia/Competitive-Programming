#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        string s[2]; cin >> s[0] >> s[1];

        bool can = true;

        for(int i=0; i<n; i++) {
            can &= !(s[0][i] == '1' && s[1][i] == '1');
        }

        (can)? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}

