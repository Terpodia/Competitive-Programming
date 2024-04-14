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

struct CHT {
  vector<ll> hm, hb;
  int hsz = 0;
  CHT() {}
  void add_line(ll m, ll b) {
    while (hsz > 1) {
      if ((hb[hsz - 1] - b) * (hm[hsz - 1] - hm[hsz - 2]) <=
          (hb[hsz - 2] - hb[hsz - 1]) * (m - hm[hsz - 1])) {
        hsz--;
        hm.pop_back();
        hb.pop_back();
      } else
        break;
    }
    hm.pb(m);
    hb.pb(b);
    hsz++;
  }
  ld query(ld x) {
    int l = 0, r = hsz - 1;
    while (r > l) {
      int mid = l + (r - l + 1) / 2;
      if ((ld)(hm[mid] - hm[mid - 1]) * x > (ld)(hb[mid - 1] - hb[mid]))
        l = mid;
      else
        r = mid - 1;
    }
    return (ld)hm[l] * x + (ld)hb[l];
  }
};

int n;

CHT max_chull(vector<pair<ll, ll>>& a) {
  CHT ret;
  map<ll, ll> m;
  forn(i, SZ(a)) {
    if (m.find(a[i].snd) != m.end())
      m[a[i].snd] = max(m[a[i].snd], a[i].fst);
    else
      m[a[i].snd] = a[i].fst;
  }
  for (auto& [w, q] : m) ret.add_line(w, q);
  return ret;
}
CHT min_chull(vector<pair<ll, ll>> a) {
  CHT ret;
  map<ll, ll> m;
  forn(i, SZ(a)) {
    if (m.find(-a[i].snd) != m.end())
      m[-a[i].snd] = max(m[-a[i].snd], -a[i].fst);
    else
      m[-a[i].snd] = -a[i].fst;
  }
  for (auto& [w, q] : m) ret.add_line(w, q);
  return ret;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  vector<pair<ll, ll>> x(n), y(n);
  forn(i, n) { cin >> x[i].fst >> y[i].fst >> x[i].snd >> y[i].snd; }

  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  CHT c1 = max_chull(x), c2 = min_chull(x), c3 = max_chull(y),
      c4 = min_chull(y);

  ld ans = (c1.query(0) + c2.query(0)) * (c3.query(0) + c4.query(0));

  forn(i, c1.hsz - 1) {
    ld m1 = c1.hm[i], m2 = c1.hm[i + 1];
    ld b1 = c1.hb[i], b2 = c1.hb[i + 1];
    ld t = (b2 - b1) / (m1 - m2);
    if (t < 0) continue;
    ans = min(ans, (c1.query(t) + c2.query(t)) * (c3.query(t) + c4.query(t)));
  }
  forn(i, c2.hsz - 1) {
    ld m1 = c2.hm[i], m2 = c2.hm[i + 1];
    ld b1 = c2.hb[i], b2 = c2.hb[i + 1];
    ld t = (b2 - b1) / (m1 - m2);
    if (t < 0) continue;
    ans = min(ans, (c1.query(t) + c2.query(t)) * (c3.query(t) + c4.query(t)));
  }
  forn(i, c3.hsz - 1) {
    ld m1 = c3.hm[i], m2 = c3.hm[i + 1];
    ld b1 = c3.hb[i], b2 = c3.hb[i + 1];
    ld t = (b2 - b1) / (m1 - m2);
    if (t < 0) continue;
    ans = min(ans, (c1.query(t) + c2.query(t)) * (c3.query(t) + c4.query(t)));
  }
  forn(i, c4.hsz - 1) {
    ld m1 = c4.hm[i], m2 = c4.hm[i + 1];
    ld b1 = c4.hb[i], b2 = c4.hb[i + 1];
    ld t = (b2 - b1) / (m1 - m2);
    if (t < 0) continue;
    ans = min(ans, (c1.query(t) + c2.query(t)) * (c3.query(t) + c4.query(t)));
  }

  cout << ans << "\n";
  return 0;
}
