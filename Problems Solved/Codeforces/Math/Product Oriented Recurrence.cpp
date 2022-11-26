#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(long double &x) { scanf("%Lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
void set_IO() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... U>
void _dbg(istream_iterator<string> it, T &head, U &...tail) {
  cout << *it << "=" << head << " ";
  _dbg(++it, tail...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define line cout << "\n-----------------------------\n";
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    _dbg(_it, args);                         \
  }

typedef long long ll;
typedef vector<ll> v64;
typedef vector<v64> vv64;

const ll MOD = 1e9 + 7;

vv64 matrix_mult(vv64 &a, vv64 &b) {
  vv64 ret(sz(a), v64(sz(b[0]), 0));

  rep(i, 0, sz(a)) rep(j, 0, sz(b[0])) rep(k, 0, sz(b)) {
    ret[i][j] += (a[i][k] * b[k][j]) % (MOD - 1);
    ret[i][j] %= (MOD - 1);
  }

  return ret;
}

vv64 matrix_binpow(vv64 a, ll k) {
  int m = sz(a);
  vv64 ret(m, v64(m, 0));
  rep(i, 0, m) ret[i][i] = 1;

  while (k) {
    if (k & 1LL) ret = matrix_mult(ret, a);
    k >>= 1LL;
    a = matrix_mult(a, a);
  }

  return ret;
}

ll n, f1, f2, f3, c;

ll binpow(ll a, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1LL) ret = (ret * a) % MOD;
    k >>= 1LL;
    a = (a * a) % MOD;
  }
  return ret;
}

ll f(ll q1, ll q2, ll q3) {
  vv64 a(3, v64(3, 0)), b(3, v64(1));

  a[0][0] = a[0][1] = a[0][2] = 1;
  a[1][0] = a[2][1] = 1;

  b[0][0] = q3;
  b[1][0] = q2;
  b[2][0] = q1;

  a = matrix_binpow(a, n);
  return matrix_mult(a, b)[2][0];
}

ll m(ll y) { return (y + MOD - 1) % (MOD - 1); }

ll x() {
  vv64 a(5, v64(5, 0));
  a[0][0] = 3, a[0][1] = m(-2), a[0][2] = 0, a[0][3] = m(-1), a[0][4] = 1;

  rep(i, 1, 5) a[i][i - 1] = 1;

  vv64 b(5, v64(1));
  b[4][0] = b[3][0] = b[2][0] = 0;
  b[1][0] = 2;
  b[0][0] = 6;

  a = matrix_binpow(a, n);
  return matrix_mult(a, b)[4][0];
}

void solve() {
  ll ret = 1;

  ret *= binpow(f1, f(1, 0, 0));
  ret %= MOD;

  ret *= binpow(f2, f(0, 1, 0));
  ret %= MOD;

  ret *= binpow(f3, f(0, 0, 1));
  ret %= MOD;

  ret *= binpow(c, x());
  ret %= MOD;

  printf("%lld\n", ret);
}

int main() {
  scan(n, f1, f2, f3, c);
  n--;
  solve();
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
