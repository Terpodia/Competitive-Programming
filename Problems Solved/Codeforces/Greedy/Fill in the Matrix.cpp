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

const int MOD = 1e9 + 7;
const ll INF = 1e9;

int val(vector<vint>& v) {
  int n = SZ(v), m = SZ(v[0]);

  int res = 0;

  set<int> x;

  forn(i, m) {
    set<int> s;
    int cur = 0;

    forn(j, n) {
      s.insert(v[j][i]);
      while (s.find(cur) != s.end()) cur++;
    }

    x.insert(cur);
    while (x.find(res) != x.end()) res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    if (m == 1) {
      cout << "0\n";
      forn(i, n) cout << "0\n";
    } else {
      vector<int> a, b;
      vector<vint> ans(n);

      forn(i, m - 1) a.pb(i);
      b.pb(m - 1);
      forn(i, m - 1) b.pb(i);

      forn(i, m - 2) {
        if (i >= n) break;
        ans[i].pb(m - 1);
        forn(j, SZ(a)) {
          int idx = j - i;
          idx += SZ(a);
          idx %= SZ(a);
          ans[i].pb(a[idx]);
        }
      }
      fore(i, m - 2, n) {
        forn(j, SZ(b)) {
          int idx = j - (m - 2);
          idx += SZ(b);
          idx %= SZ(b);
          ans[i].pb(b[idx]);
        }
      }
      cout << val(ans) << "\n";
      forn(i, n) {
        for (int j : ans[i]) cout << j << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
