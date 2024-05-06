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

/*
int f(int i, int k){
  if(i == n) return 0;
  int& ret = dp[i][k];
  if(ret != -1) return ret;
  ret=0;
  if(s[i]=='1' && k==0) return ret;
  if(s[i]=='1') return ret=1+f(i+1,k-1);
  return ret=1+f(i+1,k);
}
*/

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<vint> pref(n + 1, vint(k + 1, 0));
  vector<vint> suff(n + 1, vint(k + 1, 0));

  fore(i, 0, k + 1) pref[0][i] = 0;
  fore(i, 0, k + 1) suff[n][i] = 0;

  fore(i, 1, n + 1) fore(j, 0, k + 1) {
    if (s[i - 1] == '1' && j == 0) continue;
    if (s[i - 1] == '1')
      pref[i][j] = pref[i - 1][j - 1] + 1;
    else
      pref[i][j] = pref[i - 1][j] + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    fore(j, 0, k + 1) {
      if (s[i] == '1' && j == 0) continue;
      if (s[i] == '1')
        suff[i][j] = suff[i + 1][j - 1] + 1;
      else
        suff[i][j] = suff[i + 1][j] + 1;
    }
  }

  fore(i, 1, n + 1) fore(j, 0, k + 1) {
    pref[i][j] = max(pref[i][j], pref[i - 1][j]);
  }
  for (int i = n - 1; i >= 0; i--) {
    fore(j, 0, k + 1) suff[i][j] = max(suff[i][j], suff[i + 1][j]);
  }

  vector<int> best(n + 1, -1);

  forn(l, n) {
    int cnt = 0;
    fore(r, l, n) {
      if (s[r] == '0') cnt++;
      if (cnt > k) break;
      best[r - l + 1] =
          max(best[r - l + 1], max(pref[l][k - cnt], suff[r + 1][k - cnt]));
    }
  }

  fore(a, 1, n + 1) {
    ll ans = (ll)pref[n][k] * (ll)a;
    fore(i, 1, n + 1) {
      if (best[i] == -1) continue;
      ans = max(ans, (ll)i + (ll)a * (ll)best[i]);
    }
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
