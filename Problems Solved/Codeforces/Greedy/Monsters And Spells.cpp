#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int aux;
void _scan(int &x) { aux = scanf("%d", &x); }
void _scan(long long &x) { aux = scanf("%lld", &x); }
void _scan(double &x) { aux = scanf("%lf", &x); }
void _scan(long double &x) { aux = scanf("%Lf", &x); }
void _scan(char &x) { aux = scanf(" %c", &x); }
void _scan(char *x) { aux = scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &... tail) {
  _scan(head);
  scan(tail...);
}
void set_IO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

typedef long long ll;
typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<ll> k, h;

ll solve() {
  map<ll, ll> mp;
  FOR(i, 0, n) mp[k[i] - h[i]] = i;
  ll ret = 0;
  pair<ll, ll> curr = make_pair(0, 0);
  for (auto [i, j] : mp) {
    ll p = k[j], v = h[j];
    if (p <= curr.first) continue;

    ll pos = p - v + 1;
    if (pos > curr.first) {
      curr.first = p;
      curr.second = v;
      ret += (v * (1 + v)) / 2;
    } else {
      ll m = p - curr.first;
      ret += (m * (curr.second + 1 + curr.second + m)) / 2;
      curr.second += p - curr.first;
      curr.first = p;
    }
  }
  return ret;
}

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    scan(n);
    k = vector<ll>(n), h = vector<ll>(n);
    scan(k, h);
    printf("%lld\n", solve());
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada