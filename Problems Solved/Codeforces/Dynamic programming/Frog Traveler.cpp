#define FASTCOMP
#ifdef FASTCOMP
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
#include <cstring>
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
const int INF = 1e9 + 100;

const int MAXN = 3e5 + 10;
int n;
int a[MAXN], b[MAXN], dp[MAXN];

struct STree {
  vector<pint> st;
  int n;
  STree(int _n) : n(_n) {
    st = vector<pint>(n * 2);
    forn(i, n * 2) st[i] = mp(INF, -1);
  }
  pint op(pint x, pint y) {
    if (x.fst < y.fst) return x;
    return y;
  }
  void upd(int p, int v) {
    for (st[p += n] = mp(v, p); p >>= 1;)
      st[p] = op(st[p << 1], st[(p << 1) | 1]);
  }
  pint query(int l, int r) {
    pint resl = mp(INF, -1), resr = mp(INF, -1);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, st[l++]);
      if (r & 1) resr = op(st[--r], resr);
    }
    return op(resl, resr);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  fore(i, 1, n + 1) cin >> a[i];
  fore(i, 1, n + 1) cin >> b[i];

  STree st(n + 10);

  vector<int> jump(n + 10, -1);

  fore(x, 1, n + 1) {
    dp[x] = INF;
    if (x - a[x + b[x]] + b[x] <= 0)
      dp[x] = 1, jump[x] = 0;
    else if (b[x] < a[x + b[x]]) {
      pint res = st.query(x - a[x + b[x]] + b[x], x);
      dp[x] = res.fst + 1;
      jump[x] = res.snd;
    }
    st.upd(x, dp[x]);
  }
  if (dp[n] >= INF)
    cout << "-1\n";
  else {
    cout << dp[n] << "\n";
    int x = n;
    while (x > 0) {
      x = jump[x];
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
