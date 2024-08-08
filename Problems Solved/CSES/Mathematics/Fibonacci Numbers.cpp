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
  ll n;
  scanf("%lld", &n);
  vector<vll> v(2, vll(2));
  v[0][0] = 0, v[0][1] = 1, v[1][0] = 1, v[1][1] = 1;

  vector<vll> m(2, vll(1));
  m[0][0] = 0, m[1][0] = 1;

  printf("%lld\n", mult(binpow(v, n), m)[0][0]);
  return 0;
}
