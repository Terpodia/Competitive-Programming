#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 * 3 + 9;
typedef long long ll;
int n, m;

ll k[MAXN];
ll c[MAXN];

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(){
    sort(k, k+n, greater<ll>());
    int j = 0;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(j >= m) ans += c[k[i]-1];
        else{
            ll m = min(c[j], c[k[i]-1]);
            if(m == c[j]) j++;
            ans += m;
        }
    }

    cout << ans << "\n";
}

int main(){
    fastIO();
    
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> k[i];
        for(int i = 0; i < m; i++) cin >> c[i];
        solve();
    }

    return 0;
}
