#include <cstdio>
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define forn(i,n) for(int i=0; i<(int)(n); i++)

const ll MOD=1e9+7;

vvll mult(vvll& a, vvll& b) {
    int n = (int)a.size();
    vvll ret(n, vll(n));
    forn(i,n) forn(j,n) forn(z,n) 
        ret[i][j] = (ret[i][j] + (a[i][z] * b[j][z]) % MOD) % MOD;

    return ret;
}

vvll exp(vvll a, ll k) {
    int n = (int)a.size();
    vvll ret(n, vll(n));
    forn(i,n) forn(j,n) ret[i][j] = (i==j);

    while(k) {
        if(k&1) ret = mult(ret, a);
        a = mult(a,a);
        k >>= 1;
    }

    return ret;
}

vvll calc(ll k, int c) {
    c++;
    vvll a(c, vll(c));
    forn(i,c) forn(j,c) a[i][j] = (abs(i-j)<=1);

    vvll m = exp(a, k);
    return m;
}

int main() {
    int n; ll k; scanf("%d%lld",&n,&k);
    tuple<ll,ll,int> s[n];
    forn(i,n) {
        auto& [a,b,c] = s[i];
        scanf("%lld%lld%d",&a,&b,&c);
    }

    vll x; x.push_back(1);
    
    forn(i,n-1) {
        auto& [a,b,c] = s[i];
        int m = min(c+1, get<2>(s[i+1])+1);
        vll y(m, 0);

        vvll r = calc(b-a, c);

        forn(j,x.size()) forn(z,m)
            y[z] = (y[z] + (x[j] * r[j][z]) % MOD) % MOD;
        
        x = y;
    }

    ll ans=0;

    forn(i,x.size()) {
        auto& [a,b,c] = s[n-1]; 
        vvll m = calc(k-a, c);
        ans = (ans + (x[i] * m[i][0] % MOD)) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}

