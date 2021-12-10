#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9+7;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();  
    int n; cin >> n;
    string s; cin >> s;
    int a[n]; for(int i=0; i<n; i++) cin >> a[i];

    int ans = INF;

    for(int i=0; i<n-1; i++) {
        if(s[i] == 'R' && s[i+1] == 'L') 
            ans = min(ans, (a[i+1] - a[i])/2);
    }

    (ans == INF)? cout << "-1\n" : cout << ans << "\n";

    return 0;
}
