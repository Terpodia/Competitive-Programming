#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  ll a[3][n];
  forn(i, 3) forn(j, n) cin >> a[i][j];
  ll sum = 0;
  forn(i, n) sum += a[0][i];

  vector<int> v = {0, 1, 2};
  do {
    ll cur = 0, j = 0;
    bool can = false;

    vector<pair<int, int>> ans(3);
    forn(i, 3) ans[i] = {-1, -1};

    ans[v[0]].fst = 1;
    forn(i, n) {
      cur += a[v[j]][i];
      if (cur >= (sum + 2) / 3) {
        if (j < 2) {
          ans[v[j++]].snd = i + 1, cur = 0;
          ans[v[j]].fst = i + 2;
        } else
          can = true, ans[v[j]].snd = i + 1;
      }
    }
    if (can) {
      forn(i, 3) cout << ans[i].fst << " " << ans[i].snd << " ";
      cout << "\n";
      return;
    }

  } while (next_permutation(all(v)));
  cout << "-1\n";
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
