#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

#define forn(i,n) for(int i=0; i<(int)n; (i)++)

const ll MOD = 1e9+7;

matrix mult(matrix& a, matrix& b) {
    int n = (int)a.size();
    matrix ret(n, vector<ll>(n, 0));

    forn(i,n) forn(j,n) forn(z,n)
        ret[i][j] = (ret[i][j] + (a[i][z] * b[z][j]) % MOD) % MOD;
    
    return ret;
}

matrix exp(matrix& a, ll k) {
    int n = (int)a.size();
    matrix ret(n, vector<ll>(n, 0));
    forn(i,n) forn(j,n) ret[i][j] = (i==j);

    while(k) {
        if(k&1) ret = mult(ret, a);
        a = mult(a, a);
        k>>=1;
    }

    return ret;
}

void solve() {
    int n; ll k;
    scanf("%d%lld",&n,&k);
    matrix a(n, vector<ll>(n));

    forn(i,n) forn(j,n) 
        scanf("%lld",&a[i][j]);

    matrix ans = exp(a, k);

    forn(i,n) forn(j,n) 
        printf("%lld%c",ans[i][j]," \n"[j==n-1]);
}

int main() {
    int t; scanf("%d",&t);

    while(t--) solve();

    return 0;
}

