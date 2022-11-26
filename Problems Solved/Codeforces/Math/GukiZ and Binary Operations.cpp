#include <cstdio>
#include <vector>
using namespace std;

typedef unsigned long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

ll n, k, l, m;

vvll mult(vvll a, vvll b) {
  int r = (int)a.size(), c = (int)b[0].size(), d = (int)a[0].size();

  vvll ret(r, vll(c, 0));

  forn(i, r) forn(j, c) forn(z, d) ret[i][j] =
      (ret[i][j] + (a[i][z] * b[z][j]) % m) % m;

  return ret;
}

ll fib() {
  vvll mat(2, vll(2, 0));
  mat[0][0] = mat[0][1] = mat[1][0] = 1;

  ll b = n;
  vvll e(2, vll(2, 0));
  e[0][0] = e[1][1] = 1;

  while (b) {
    if (b & 1) e = mult(e, mat);
    mat = mult(mat, mat);
    b >>= 1;
  }

  return mult(e, vvll(2, vll(1, 1)))[0][0];
}

int main() {
  scanf("%lld%lld%lld%lld", &n, &k, &l, &m);

  ll mx = 0;
  forn(i, l) mx |= ((ll)1 << (ll)i);

  if (k > mx) {
    puts("0");
    return 0;
  }

  ll ans = 1, f = fib();

  ll t = 1, b = n, p = 2;

  while (b) {
    if (b & 1) t = (t * p) % m;
    p = (p * p) % m;
    b >>= 1;
  }

  for (ll i = 0; i < l; i++) {
    if (k & ((ll)1 << i))
      ans = (ans * (t - f + m) % m) % m;
    else
      ans = (ans * f) % m;
  }

  printf("%lld\n", ans % m);

  return 0;
}
