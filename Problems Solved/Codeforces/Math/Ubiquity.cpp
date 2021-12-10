#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

ll binpow(ll a, ll b) {
    if(b==0) return 1;
    if(b==1) return a; 

    ll p = binpow(a, b/2);

    if(b%2==0) return (p*p) % MOD;
    return (((a*p)% MOD) *p) % MOD;
}

ll subs(ll a, ll b) { return (((a - b) % MOD) + MOD) % MOD; }

ll sum(ll a, ll b) { return (a+b) % MOD; } 

int main() {
    fastIO();
    ll N; cin >> N; 
    ll ans = subs(binpow(10, N), subs(sum(binpow(9, N), binpow(9, N)), binpow(8, N)));
    cout << ans << "\n";

    return 0;
}
