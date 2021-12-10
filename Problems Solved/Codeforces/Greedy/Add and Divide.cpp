#include <iostream>
using namespace std;

typedef long long ll;

int calc(ll x, ll y){
    int cnt=0;
    while(x != 0){
        x /= y;
        cnt++;
    }
    return cnt;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main(){
    fastIO();
    int t; cin >> t;

    while(t--){
        ll a, b; cin >> a >> b;
        ll ans = 1e9;
        for(ll i = 0; i < 100; i++){
            if(b + i == 1) continue;
            ans = min(ans, calc(a, b+i) + i);
        }
        cout << ans << "\n";
    }
    return 0;
}
