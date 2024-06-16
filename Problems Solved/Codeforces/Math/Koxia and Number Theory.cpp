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

const int MAXN = 1e5;
int cr[MAXN];
vector<ll> p;
void init_sieve() {
  for (int i = 2; i < MAXN; i += 2) cr[i] = 2;
  p.pb(2);
  for (int i = 3; i < MAXN; i += 2)
    if (!cr[i]) {
      p.pb(i), cr[i] = i;
      for (ll j = 1LL * i * i; j < MAXN; j += i) cr[j] = i;
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init_sieve();

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    ll a[n];
    forn(i, n) cin >> a[i];

    set<ll> s;
    forn(i, n) s.insert(a[i]);
    if (SZ(s) < n) {
      cout << "NO\n";
      continue;
    }
    bool can = true;
    for (ll pr : p) {
      if (pr > n) break;
      vector<int> cnt(200, 0);
      forn(i, n) cnt[a[i] % pr]++;
      int sum = 0;
      forn(i, 200) if (cnt[i] > 1) sum++;

      if (sum == pr) can = false;
    }
    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
