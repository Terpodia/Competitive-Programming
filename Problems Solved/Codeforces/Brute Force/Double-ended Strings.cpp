#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

const int INF = 1e9;

void fastIO() { cin.tie(0)->sync_with_stdio(false); }

int main(){
    fastIO();
    int t; cin >> t;

    while(t--){
        string a, b; cin >> a >> b;

        int ans = INF;

        for(int l1 = 0; l1 <= sz(a); l1++){
            for(int r1 = 0; r1 <= sz(a) - l1; r1++){
                for(int l2 = 0; l2 <= sz(b); l2++){
                    for(int r2 = 0; r2 <= sz(b) - l2; r2++){
                        if(l1 + r1 == sz(a) && l2 + r2 < sz(b)) continue;
                        if(l2 + r2 == sz(b) && l1 + r1 < sz(a)) continue;
                        
                        if(l1 + r1 == sz(a)) ans = min(ans, sz(a) + sz(b));
                        string substr_a, substr_b;

                        for(int i = l1; i < sz(a) - r1; i++)
                            substr_a.push_back(a[i]);

                        for(int i = l2; i < sz(b) - r2; i++)
                            substr_b.push_back(b[i]);

                        if(substr_a == substr_b) ans = min(ans, l1 + r1 + l2 + r2);
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
