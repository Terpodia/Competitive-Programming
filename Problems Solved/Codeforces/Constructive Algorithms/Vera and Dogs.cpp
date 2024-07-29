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

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  if (x >= n) {
    cout << "-1\n";
    return 0;
  }
  vector<int> ans[n];
  forn(i, n) {
    forn(j, x) ans[i].pb(i * x + j + 1);
    forn(j, x) ans[i].pb(i * x + j + 1);
  }
  fore(j, x, 2 * x) {
    vector<int> v;
    forn(i, n) { v.pb(ans[(i + j - x + 1) % n][j]); }
    forn(i, n) ans[i][j] = v[i];
  }

  forn(i, n) {
    for (int j : ans[i]) cout << j << " ";
    cout << "\n";
  }
  return 0;
}
