#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)name.size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ROF(i, x, n) for (int i = (x); i > (int)(n); i--)

const ll INF = 1e18;

typedef long long ll;

int n, l, k;
ll d[501], a[501];

ll dp[501][501];

ll solve(int pos, int j) {
  if (pos == n) return 0;
  ll &ret = dp[pos][j];
  if (ret != -1) return ret;

  ret = INF;
  FOR(i, 0, min(j, n - 1 - pos) + 1) {
    ret = min(ret,
              a[pos] * (d[pos + 1 + i] - d[pos]) + solve(pos + 1 + i, j - i));
  }
  return ret;
}

int main() {
  scan(n, l, k);
  FOR(i, 0, n) scan(d[i]);
  d[n] = l;
  FOR(i, 0, n) scan(a[i]);

  memset(dp, -1, sizeof(dp));
  printf("%lld\n", solve(0, k));

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
