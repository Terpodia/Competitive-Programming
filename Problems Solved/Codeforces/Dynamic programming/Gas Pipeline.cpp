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
void scan(T &head, U &...tail) {
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

const ll INF = 1e18;
const int MAXN = 2e5 + 10;

int n;
ll a, b, dp[MAXN][3];
string s;

ll solve(int i, ll h) {
  ll &ret = dp[i][h];
  if (i == n - 1) {
    if (h == 1) return a + b;
    return a * 2 + b;
  }
  if (ret != -1) return ret;
  if (s[i + 1] == '1') {
    if (h == 2) return ret = solve(i + 1, 2) + b * 2 + a;
    return ret = solve(i + 1, 2) + b * 2 + a * 2;
  }
  ret = solve(i + 1, h) + b * h + a;
  if (s[i] == '0' && h == 2)
    ret = min(ret, solve(i + 1, 1) + b + a * 2);
  else if (s[i] == '0' && h == 1)
    ret = min(ret, solve(i + 1, 2) + b * 2 + a * 2);
  return ret;
}

int main() {
  set_IO();
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> a >> b >> s;
    memset(dp, -1, sizeof(dp));
    cout << b + solve(0, 1) << "\n";
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
