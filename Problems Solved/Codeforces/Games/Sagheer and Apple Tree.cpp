#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, a[MAXN], p[MAXN], h[MAXN];
vector<int> g[MAXN];

int flag;

map<int, ll> cnt;
vector<int> val;

void height(int u) {
  if (p[u] != -1) h[u] = h[p[u]] + 1;
  int leaf = 0;
  for (int v : g[u])
    if (v != p[u]) {
      leaf++;
      height(v);
    }
  if (leaf == 0) flag = h[u] % 2;
}
void dfs(int u) {
  if (h[u] % 2 == flag)
    val.push_back(a[u]);
  else
    cnt[a[u]]++;
  for (int v : g[u])
    if (v != p[u]) {
      dfs(v);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, n) cin >> a[i];
  p[0] = -1;
  fore(i, 1, n) {
    int u;
    cin >> u;
    u--;
    p[i] = u;
    g[i].pb(u);
    g[u].pb(i);
  }
  height(0);
  dfs(0);
  int sum = 0;
  for (int i : val) sum ^= i;

  ll ans = 0;
  if (sum == 0) {
    ll m = 0;
    for (auto &[x, y] : cnt) m += y;
    ans += (m * (m - 1LL)) / 2LL;
    ans += ((ll)len(val) * (ll)(len(val) - 1LL)) / 2LL;
    for (int i : val) {
      int x = (sum ^ i);
      ans += cnt[x];
    }
  } else {
    for (int i : val) {
      int x = (sum ^ i);
      ans += cnt[x];
    }
  }
  cout << ans << "\n";
  return 0;
}
