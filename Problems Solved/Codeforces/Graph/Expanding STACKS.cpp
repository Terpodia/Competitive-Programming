#define FASTCOMP
#ifdef FASTCOMP
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
// #include<cstring>
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

const int MOD = 1e9 + 7, MAXN = 1010;
const ll INF = 1e9;

vector<int> g[MAXN];
int color[MAXN];
bool can = true;

void dfs(int u, int prev = 0) {
  color[u] = (1 - prev) + 1;
  for (int v : g[u]) {
    if (color[u] == color[v]) can = false;
    if (color[v] == 0) dfs(v, 1 - prev);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  pair<int, int> x[2 * n];
  forn(i, 2 * n) {
    char c;
    int a;
    cin >> c >> a;
    if (c == '+')
      x[i] = mp(0, a);
    else
      x[i] = mp(1, a);
  }
  pair<int, int> pos[n + 1];
  forn(i, 2 * n) {
    if (x[i].fst == 1)
      pos[x[i].snd].snd = i;
    else
      pos[x[i].snd].fst = i;
  }
  forn(i, 2 * n) {
    if (x[i].fst == 1) continue;
    fore(j, i + 1, pos[x[i].snd].snd) {
      if (pos[x[j].snd].snd > pos[x[i].snd].snd) {
        g[x[i].snd].pb(x[j].snd);
        g[x[j].snd].pb(x[i].snd);
      }
    }
  }
  fore(i, 1, n + 1) if (color[i] == 0) { dfs(i); }
  if (!can)
    cout << "*\n";
  else {
    fore(i, 1, n + 1) {
      if (color[i] == 1)
        cout << "G";
      else
        cout << "S";
    }
    cout << "\n";
  }
  return 0;
}
