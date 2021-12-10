#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        string s[2]; cin >> s[0] >> s[1];

        int ans=0;
        
        for(int i=0; i<n; i++) {
            if(s[1][i] == '0') continue;

            if(s[0][i] == '0') ans++;

            else {
                if(i == 0) { if(s[0][i+1] == '1') ans++, s[0][i+1] = '2'; }
                else if(i == n-1) { if(s[0][i-1] == '1') ans++, s[0][i-1] = '2';  }
                else { 
                     if(s[0][i-1] == '1') ans++, s[0][i-1] = '2';
                     else if(s[0][i+1] == '1') ans++, s[0][i+1] = '2';
                }
            }
        }

        cout << ans << "\n";
    }


    return 0;
}
