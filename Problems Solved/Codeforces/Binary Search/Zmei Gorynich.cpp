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

typedef __uint128_t u128;
typedef long long ll;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll a[100], x;

ll bs(ll hi) {
  ll l = 0, r = (ll)1e9, ret = (ll)1e9;
  while (r > l) {
    ll mid = l + (r - l) / 2;
    if (x - a[0] * mid <= hi)
      r = mid, ret = (x - a[0] * mid == 0) ? mid : mid + 1;
    else
      l = mid + 1;
  }
  return ret;
}

int main() {
  int tc;
  scan(tc);
  while (tc--) {
    scan(n, x);
    ll hi = (ll)-1e9;
    for (int i = 0; i < n; i++) {
      ll d, h;
      scan(d, h);
      a[i] = d - h;
      hi = max(hi, d);
    }
    sort(a, a + n, greater<ll>());
    if (hi >= x)
      printf("1\n");
    else if (a[0] <= 0)
      puts("-1");
    else
      printf("%lld\n", bs(hi));
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
