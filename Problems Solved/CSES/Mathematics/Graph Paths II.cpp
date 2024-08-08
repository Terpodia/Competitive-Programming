#include "bits/stdc++.h"
using namespace std;

#define len(x) (int)x.size()

typedef long long ll;

const ll INF = 1e18 + 100LL;

typedef vector<ll> vll;

vector<vll> mult(vector<vll> a, vector<vll> b) {
  int n = len(a), m = len(b[0]);
  vector<vll> ret(n, vll(m, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < len(b); k++) {
        ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return ret;
}
vector<vll> binpow(vector<vll> a, ll n) {
  vector<vll> ret = a;
  n--;
  while (n) {
    if (n & 1) ret = mult(ret, a);
    a = mult(a, a);
    n >>= 1;
  }
  return ret;
}

int main() {
  int n, m;
  ll k;
  scanf("%d%d%lld", &n, &m, &k);
  vector<vll> adj(n, vll(n, INF));
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    scanf("%d%d%lld", &u, &v, &w);
    u--, v--;
    adj[u][v] = min(adj[u][v], w);
  }
  ll ans = binpow(adj, k)[0][n - 1];
  if (ans >= INF)
    puts("-1");
  else
    printf("%lld\n", ans);
  return 0;
}
