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

void solve() {
  int n;
  cin >> n;
  string s = to_string(n);
  vector<pair<int, int>> ans;
  fore(a, 1, 10001) {
    int m = min(7, len(s) * a);
    string cur = "";
    forn(i, m) {
      cur += s[i % len(s)];
      int b = len(s) * a - (i + 1);
      if (b >= 1 && b <= 10000) {
        int x = n * a - b;
        int y = stoi(cur);
        if (x == y) {
          ans.pb(make_pair(a, b));
        }
      }
    }
  }
  cout << len(ans) << "\n";
  for (auto [x, y] : ans) cout << x << " " << y << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
