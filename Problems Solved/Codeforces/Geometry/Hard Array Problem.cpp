#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <cmath>
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
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const ll INF = 2e18 + 10;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  ll a[n], b[n];
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];

  vector<pll> pt;
  ll s1 = 0, s2 = 0;
  pt.pb(mp(s1, s2));
  forn(i, n) {
    s1 += a[i], s2 += b[i];
    pt.pb(mp(s1, s2));
  }
  sort(all(pt));
  ll d = INF;
  multiset<pair<ll, ll>> ms;
  int j = 0;
  forn(i, SZ(pt)) {
    ll r = ceil(sqrt(d));
    while (pt[i].fst - pt[j].fst > r) {
      ms.erase(ms.find(mp(pt[j].snd, pt[j].fst)));
      j++;
    }
    auto it1 = ms.lower_bound(mp(pt[i].snd - r, -INF));
    auto it2 = ms.upper_bound(mp(pt[i].snd + r, -INF));

    for (auto it = it1; it != it2; it++) {
      ll dx = pt[i].fst - it->snd;
      ll dy = pt[i].snd - it->fst;
      d = min(d, dx * dx + dy * dy);
    }
    ms.insert(mp(pt[i].snd, pt[i].fst));
  }
  cout << d << "\n";

  return 0;
}
