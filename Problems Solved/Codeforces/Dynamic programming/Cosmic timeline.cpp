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

int n;
ll d[MAXN], v[MAXN], t[MAXN], cnt[MAXN], st[2 * MAXN];

pair<int, int> p[MAXN];

void compress() {
  vector<ll> b;
  rep(i, 0, n + 1) b.pb(d[i]), b.pb(d[i] - t[i]);
  sort(all(b));
  b.resize(distance(b.begin(), unique(all(b))));
  rep(i, 0, n + 1) {
    p[i].fst = (int)distance(b.begin(), lower_bound(all(b), d[i] - t[i]));
    p[i].snd = (int)distance(b.begin(), lower_bound(all(b), d[i]));
  }
}

void upd(int i, ll val) {
  for (st[i += MAXN] = val; i >>= 1;) st[i] = max(st[i << 1], st[(i << 1) | 1]);
}

ll query(int l, int r) {
  ll resl = 0, resr = 0;
  for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
    if (l & 1) resl = max(resl, st[l++]);
    if (r & 1) resr = max(st[--r], resr);
  }
  return max(resl, resr);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  rep(i, 0, n) cin >> d[i] >> v[i] >> t[i];
  rep(i, 0, n) t[i] = min(t[i], d[i]);
  d[n] = INF, v[n] = 0, t[n] = INF;
  compress();
  ll dp[n + 1];
  rep(i, 0, n + 1) dp[i] = v[i];

  upd(p[0].snd, v[0]);

  rep(i, 1, n + 1) {
    dp[i] = query(p[i].fst, p[i].snd + 1) + v[i];
    upd(p[i].snd, dp[i]);
  }
  cout << dp[n] << "\n";
  return 0;
}
