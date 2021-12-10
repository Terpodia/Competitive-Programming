#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2 * 1e5;
int n;
ll a[MAXN];

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(){
    sort(a, a+n, greater<ll>());
    
    ll ans = 0;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(a[i]%2 == 0) ans += a[i];
        }
        else{
            if(a[i]%2 != 0) ans -= a[i];
        }
    }

    if(ans == 0) cout << "Tie\n";
    else if(ans > 0) cout << "Alice\n";
    else cout << "Bob\n";
}

int main(){
    fastIO();

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        solve();
    }

    return 0;
}
