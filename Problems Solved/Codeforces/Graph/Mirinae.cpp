#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#endif
using namespace std;
#ifndef FASTCOMP
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
#endif

// MACROS
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define sz(x) SZ(x)
#define len(x) SZ(x)
#define all(x) x.begin(), x.end()
#define esta(x, c) ((c).find(x) != (c).end())
// FOR
#define fore(i, a, b) for (auto i = a, to = b; i < to; ++i)
#define form(i, n, m) fore(i, n, m)
#define forn(i, n) form(i, 0, n)
#define dfor(i, n) for (int i = n; i-- > 0;)
#define forall(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
// DEBUG
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<
#define printv(v)                      \
  if (1) {                             \
    for (auto _ : v) cerr << _ << " "; \
    cerr << endl;                      \
  }

typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const ll INF = 1e9;

const int MAXN = 1e6 + 10;

vector<int> g[2][MAXN];
int vis[MAXN];
int t[MAXN], in[MAXN];
int n, ans;

pair<int, int> dfs(int u) {
  for (int w : g[1][u])
    if (t[w] == 1) return mp(0, 0);
  vis[u] = 1;

  pair<int, int> ret = mp(1, 0);
  for (int w : g[1][u])
    if (in[w] > 0) {
      if (!vis[w]) {
        pair<int, int> res = dfs(w);
        ret.fst += res.fst, ret.snd += res.snd;
      } else if (vis[w] == 1)
        ret.snd++;
    }
  vis[u] = 2;
  int v = g[0][u][0];
  pair<int, int> res = mp(0, 0);
  if (!vis[v]) res = dfs(v);
  ret.fst += res.fst, ret.snd += res.snd;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, n) {
    int a;
    cin >> a;
    g[0][i].pb(a - 1);
    g[1][a - 1].pb(i);
    in[a - 1]++;
  }
  forn(i, n) t[i] = 0;

  queue<int> q;
  forn(i, n) if (in[i] == 0) t[i] = 1, ans++, q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v = g[0][u][0];
    in[v]--;
    if (in[v] == 0) {
      q.push(v);
      bool can = true;
      for (int w : g[1][v]) can &= t[w] == 0;
      if (can) ans++, t[v] = 1;
    }
  }
  forn(i, n) vis[i] = false;
  forn(i, n) {
    bool can = true;
    for (int w : g[1][i]) can &= t[w] == 0;

    if (in[i] > 0 && !vis[i] && can) {
      pint res = dfs(i);
      if (res.snd == 0)
        ans += (res.fst + 1) / 2;
      else
        ans += res.fst / 2;
    }
  }
  cout << ans << "\n";
  return 0;
}
