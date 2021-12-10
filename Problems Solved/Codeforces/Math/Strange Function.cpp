#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b/gcd(a, b);
}

int main() {
    int t; scanf("%d",&t);

    while(t--) {
        ll n; scanf("%lld",&n);
        ll ans=0, k=n, val=2, m=1;

        while(k > 0) {
            m = lcm(val, m);
            ll cnt = n/m;

            ans = (ans + (val * (k-cnt)) % MOD) % MOD;

            k = k - (k-cnt);
            val++;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
