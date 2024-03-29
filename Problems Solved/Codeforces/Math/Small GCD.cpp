#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
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
const int MAXA = 1e5 + 10;
const ll INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    ll a[n];
    forn(i, n) cin >> a[i];
    sort(a, a + n);
    map<ll, ll> cnt;

    ll ans[MAXA];
    memset(ans, 0, sizeof(ans));

    forn(i, n) {
      for (ll d = 1; d * d <= a[i]; d++)
        if (a[i] % d == 0) {
          ll d2 = a[i] / d;
          if (d == d2) {
            ans[d] += cnt[d] * (ll)(n - i - 1);
            cnt[d]++;
          } else {
            ans[d] += cnt[d] * (ll)(n - i - 1);
            cnt[d]++;
            ans[d2] += cnt[d2] * (ll)(n - i - 1);
            cnt[d2]++;
          }
        }
    }

    for (int i = MAXA - 1; i > 0; i--) {
      for (int j = 2 * i; j < MAXA; j += i) ans[i] -= ans[j];
    }
    ll res = 0;
    forn(i, MAXA) res += ans[i] * i;
    cout << res << "\n";
  }
  return 0;
}
