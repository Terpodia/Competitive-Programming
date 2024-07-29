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
  int n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s = "L" + s;

  int i = 0, cur = 0;
  while (i <= n) {
    if (s[i] == 'W') {
      if (cur == k) {
        cout << "NO\n";
        return;
      }
      i++, cur++;
    } else if (s[i] == 'C') {
      cout << "NO\n";
      return;
    } else {
      if (i + m > n) break;
      int cnt = m;
      fore(j, 1, m + 1) {
        if (s[i + j] == 'L') {
          cnt = j;
          break;
        }
      }
      i += cnt;
    }
  }
  cout << "YES\n";
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
