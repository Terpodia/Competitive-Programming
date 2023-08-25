// Si puedes imaginarlo puedes programarlo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define pb push_back
#define make_pair mp
#define dbg(x) cerr << #x << "=" << x << " "
#define line cerr << "\n========================================\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const ll INF = 1e18;
const int MAXN = 3e5 + 10;

int n, k;
ll a[MAXN], st[11][2 * MAXN], cnt[11][MAXN];

pair<int, int> p[MAXN];

void upd(int j, int i, ll val) {
  for (st[j][i += MAXN] = val; i >>= 1;)
    st[j][i] = st[j][i << 1] + st[j][(i << 1) | 1];
}

ll query(int j, int l, int r) {
  ll resl = 0, resr = 0;
  for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
    if (l & 1) resl = resl + st[j][l++];
    if (r & 1) resr = st[j][--r] + resr;
  }
  return resl + resr;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  rep(i, 0, n) cin >> a[i];
  a[n] = n + 1;
  k++;

  ll dp[k + 1][n + 1];
  memset(dp, 0, sizeof(dp));

  rep(i, 0, n) dp[0][i] = 1;

  rep(j, 1, k + 1) rep(i, 0, n + 1) {
    upd(j - 1, a[i], dp[j - 1][i]);
    dp[j][i] = query(j - 1, 0, a[i]);
  }
  cout << dp[k][n] << "\n";
  return 0;
}
