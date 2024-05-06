#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
const ll INF = 1e9;

const int MAX = 3e6 + 100;

struct SuffixArray {
  vint sa, lcp;
  SuffixArray(basic_string<ll>& s, int lim = 256) {  // or basic_string<int>
    int n = sz(s) + 1, k = 0, a, b;
    vint x(all(s) + 1), y(n), ws(max(n, lim)), rank(n);
    sa = lcp = y, iota(all(sa), 0);
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
      p = j, iota(all(y), n - j);
      fore(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
      fill(all(ws), 0);
      fore(i, 0, n) ws[x[i]]++;
      fore(i, 1, lim) ws[i] += ws[i - 1];
      for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[sa[0]] = 0;
      fore(i, 1, n) a = sa[i - 1], b = sa[i],
                    x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
    }
    fore(i, 1, n) rank[sa[i]] = i;
    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
      for (k &&k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++)
        ;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  basic_string<ll> a;
  vector<ll> v;
  forn(i, n) {
    ll x;
    cin >> x;
    a.pb(x);
    v.pb(x);
  }
  sort(all(v));
  v.resize(distance(v.begin(), unique(all(v))));

  forn(i, n) {
    ll d = (ll)distance(v.begin(), lower_bound(all(v), a[i]));
    d++;
    if (a[i] % 2 == 0)
      a[i] = 2 * d;
    else
      a[i] = 2 * d + 1;
  }

  SuffixArray s(a, MAX);

  ll suff[n];
  fore(i, 1, n + 1) { suff[s.sa[i]] = s.sa[i] + s.lcp[i]; }

  vector<ll> odd(n + 1, 0), even(n + 1, 0);
  ll cur = 0, res = 0;

  for (int i = n - 1; i >= 0; i--) {
    even[i] = even[i + 1];
    odd[i] = odd[i + 1];
    cur += a[i];

    if (abs(cur) % 2 == 1) {
      res += odd[suff[i] + 1];
    } else {
      res += even[suff[i] + 1] + 1;
    }

    if (abs(cur) % 2 == 0)
      even[i]++;
    else
      odd[i]++;
  }

  cout << res << "\n";
  return 0;
}
