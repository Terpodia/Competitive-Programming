#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

ll binpow(ll a, ll b) {
    if(b==0) return 1;
    if(a==0) return 0;
    
    ll p = binpow(a, b/2);
    p = (p%MOD * p%MOD) % MOD; 
    
    if(b%2==0) return p;
    else return (p%MOD * a%MOD) % MOD;
}

ll subs(ll a, ll b) {
    return (((a - b)%MOD)+MOD)%MOD;
}

int main() {
    fastIO();
    ll a, k; cin >> a >> k; 

    if(a%MOD == 1) cout << (k+1) % MOD << "\n";

    else if(a%MOD == 0) cout << 1 << "\n";

    else {
        ll ans = subs(binpow(a%MOD, k+1), 1);
        cout << (ans * binpow(subs(a%MOD,1), MOD-2)) % MOD << "\n";
    }

    return 0;
}
