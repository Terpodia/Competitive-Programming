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
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;

const int MOD = 1e9 + 7;
const ll INF = 1e9;

bool isPalindrome(string &s) {
  string t = s;
  reverse(all(t));
  return s == t;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if (!isPalindrome(s)) {
      cout << "YES\n1\n" << s << "\n";
      continue;
    }
    int j = -1;
    forn(i, SZ(s)) if (s[i] != s[0]) {
      j = i;
      break;
    }
    if (j == -1) {
      cout << "NO\n";
      continue;
    }
    string a, b;
    forn(i, j + 1) a.pb(s[i]);
    fore(i, j + 1, SZ(s)) b.pb(s[i]);
    if (!isPalindrome(b)) {
      cout << "YES\n2\n" << a $ b << "\n";
      continue;
    }
    if (j == 1 || j == (SZ(s) + 1) / 2 - 1)
      cout << "NO\n";
    else {
      cout << "YES\n2\n" << a << b[0] << " ";
      fore(i, 1, SZ(b)) cout << b[i];
      cout << "\n";
    }
  }
  return 0;
}
