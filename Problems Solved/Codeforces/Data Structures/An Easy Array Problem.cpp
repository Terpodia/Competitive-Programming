#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
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
typedef pair<ll, ll> pint;

const ll INF = 1e18;

struct STreeMin {
  vector<pint> st;
  int n;
  pint NEUT = mp(INF, INF);

  pint op(pint a, pint b) {
    pint res = NEUT;
    if (a.fst <= b.fst) {
      res.fst = a.fst;
      res.snd = min(a.snd, b.fst);
    } else {
      res.fst = b.fst;
      res.snd = min(a.fst, b.snd);
    }
    return res;
  }

  STreeMin(int _n) : st(_n * 2), n(_n) { forn(i, 2 * n) st[i] = NEUT; }

  STreeMin(int _n, vector<ll>& a) : st(_n * 2), n(_n) {
    forn(i, 2 * n) st[i] = NEUT;
    fore(i, 0, n) st[n + i].fst = a[i];
    build();
  }
  void build() {
    for (int i = n - 1; i > 0; i--) st[i] = op(st[i << 1], st[(i << 1) | 1]);
  }
  void upd(int p, int v) {
    for (st[p += n].fst = v; p >>= 1;) st[p] = op(st[p << 1], st[(p << 1) | 1]);
  }
  pint query(int l, int r) {
    pint resl = NEUT, resr = NEUT;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, st[l++]);
      if (r & 1) resr = op(st[--r], resr);
    }
    return op(resl, resr);
  }
};

struct STreeMax {
  vector<pint> st;
  int n;
  pint NEUT = mp(-INF, -INF);

  pint op(pint a, pint b) {
    pint res = NEUT;
    if (a.fst >= b.fst) {
      res.fst = a.fst;
      res.snd = max(a.snd, b.fst);
    } else {
      res.fst = b.fst;
      res.snd = max(a.fst, b.snd);
    }
    return res;
  }

  STreeMax(int _n) : st(_n * 2), n(_n) { forn(i, 2 * n) st[i] = NEUT; }

  STreeMax(int _n, vector<ll>& a) : st(_n * 2), n(_n) {
    forn(i, 2 * n) st[i] = NEUT;
    fore(i, 0, n) st[n + i].fst = a[i];
    build();
  }
  void build() {
    for (int i = n - 1; i > 0; i--) st[i] = op(st[i << 1], st[(i << 1) | 1]);
  }
  void upd(int p, int v) {
    for (st[p += n].fst = v; p >>= 1;) st[p] = op(st[p << 1], st[(p << 1) | 1]);
  }
  pint query(int l, int r) {
    pint resl = NEUT, resr = NEUT;
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
  int n, q;
  cin >> n >> q;
  basic_string<ll> a(n);
  forn(i, n) cin >> a[i];

  STreeMin s1(n, a);
  STreeMax s2(n, a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    ll ans = -INF;
    r--;
    pint b = s1.query(l, r), c = s2.query(l, r);

    /*
    dbg(b.fst);
    dbg(b.snd);
    dbg(c.fst);
    dbg(c.snd);
    raya;
    */

    ans = max(ans, a[l - 1] * b.fst * b.snd * a[r]);
    ans = max(ans, a[l - 1] * c.fst * c.snd * a[r]);
    ans = max(ans, a[l - 1] * b.fst * c.fst * a[r]);
    cout << ans << "\n";
  }
  return 0;
}
