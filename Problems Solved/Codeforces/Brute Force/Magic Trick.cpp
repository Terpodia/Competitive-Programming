#include <iostream>
using namespace std;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
    fastIO();

    int n; cin >> n;
    pair<string, int> a[n];
    for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;

    int ans=0;
    for(int k=1; k<=100; k++) {
        int x = k;

        for(int i=0; i<n; i++) {
            if(a[i].first == "ADD") x += a[i].second;
            else if(a[i].first == "MULTIPLY") x *= a[i].second;
            else if(a[i].first == "SUBTRACT") {
                x -= a[i].second;
                if(x < 0) { ans++; break; }
            }
            else {
                if(x%a[i].second != 0) { ans++; break; }
                x /= a[i].second;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
