#define FASTCOMP
#ifdef FASTCOMP
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
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

string a[7];

bool check(int flag) {
  fore(i, 1, 6) for (int j = ((i % 2) != flag); j < 6; j += 2) {
    if (j == 0) continue;

    if (a[i][j] != 'B') continue;
    if (a[i - 1][j - 1] != 'B') continue;
    if (a[i - 1][j + 1] != 'B') continue;
    if (a[i + 1][j - 1] != 'B') continue;
    if (a[i + 1][j + 1] != 'B') continue;
    return false;
  }
  return true;
}

int calc(vector<pair<int, int>>& v, int flag) {
  if (check(flag)) return 0;
  forn(i, SZ(v)) {
    a[v[i].fst][v[i].snd] = 'W';
    if (check(flag)) return 1;
    a[v[i].fst][v[i].snd] = 'B';
  }
  fore(i, 0, SZ(v)) fore(j, 1, SZ(v)) {
    a[v[i].fst][v[i].snd] = 'W';
    a[v[j].fst][v[j].snd] = 'W';
    if (check(flag)) return 2;
    a[v[i].fst][v[i].snd] = 'B';
    a[v[j].fst][v[j].snd] = 'B';
  }
  fore(i, 0, SZ(v)) fore(j, 1, SZ(v)) fore(k, 2, SZ(v)) {
    a[v[i].fst][v[i].snd] = 'W';
    a[v[j].fst][v[j].snd] = 'W';
    a[v[k].fst][v[k].snd] = 'W';
    if (check(flag)) return 3;
    a[v[i].fst][v[i].snd] = 'B';
    a[v[j].fst][v[j].snd] = 'B';
    a[v[k].fst][v[k].snd] = 'B';
  }
  fore(i, 0, SZ(v)) fore(j, 1, SZ(v)) fore(k, 2, SZ(v)) fore(w, 3, SZ(v)) {
    a[v[i].fst][v[i].snd] = 'W';
    a[v[j].fst][v[j].snd] = 'W';
    a[v[k].fst][v[k].snd] = 'W';
    a[v[w].fst][v[w].snd] = 'W';
    if (check(flag)) return 4;
    a[v[i].fst][v[i].snd] = 'B';
    a[v[j].fst][v[j].snd] = 'B';
    a[v[k].fst][v[k].snd] = 'B';
    a[v[w].fst][v[w].snd] = 'B';
  }
  return 5;
}

void solve() {
  vector<pair<int, int>> odd, even;
  fore(i, 1, 6) for (int j = i % 2; j < 6; j += 2) {
    if (j == 0) continue;
    if (a[i][j] == 'B') even.pb(mp(i, j));
  }
  fore(i, 1, 6) for (int j = 1 - i % 2; j < 6; j += 2) {
    if (j == 0) continue;
    if (a[i][j] == 'B') odd.pb(mp(i, j));
  }
  int res1, res2;
  res1 = calc(even, 0), res2 = calc(odd, 1);

  cout << res1 + res2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    forn(i, 7) cin >> a[i];
    solve();
  }
  return 0;
}
