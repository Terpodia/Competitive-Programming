#include "bits/stdc++.h"
using namespace std;

#define len(x) (int)x.size()

typedef long long ll;

const ll MOD = 1e9 + 7;

typedef vector<ll> vll;

vector<vll> mult(vector<vll> a, vector<vll> b) {
  int n = len(a), m = len(b[0]);
  vector<vll> ret(n, vll(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < len(b); k++) {
        ret[i][j] += (a[i][k] * b[k][j]) % MOD;
        ret[i][j] %= MOD;
      }
    }
  }
  return ret;
}
vector<vll> binpow(vector<vll> a, ll n) {
  vector<vll> ret = a;
  for (int i = 0; i < len(a); i++)
    for (int j = 0; j < len(a[i]); j++) ret[i][j] = 0;
  for (int i = 0; i < len(a); i++) ret[i][i] = 1;

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
  vector<vll> adj(n, vll(n, 0));
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u][v]++;
  }
  printf("%lld\n", binpow(adj, k)[0][n - 1]);
  return 0;
}
