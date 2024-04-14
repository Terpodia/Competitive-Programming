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

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    int cur = 0;
    if (__builtin_popcountll(n) % 2 == 0)
      cout << "first" << endl;
    else {
      cout << "second" << endl;
      cur = 1;
    }

    while (true) {
      if (cur == 1) {
        ll p1, p2;
        cin >> p1 >> p2;
        if (p1 == 0 && p2 == 0) break;
        if (p1 == -1 && p2 == -1) break;
        if (__builtin_popcountll(p1) % 2 == 0)
          n = p1;
        else
          n = p2;
      } else {
        if (__builtin_popcountll(n) <= 1) {
          cout << "0 0" << endl;
          break;
        }
        ll p1 = 0, p2 = n;
        for (ll i = 62; i >= 0; i--)
          if (n & (1LL << i)) {
            p1 |= (1LL << i);
            p2 ^= (1LL << i);
            break;
          }
        cout << p1 << " " << p2 << endl;
      }
      cur = 1 - cur;
    }
  }
  return 0;
}
