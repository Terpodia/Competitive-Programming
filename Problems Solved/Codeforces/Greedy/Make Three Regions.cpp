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
  string s[2];
  cin >> s[0] >> s[1];
  int ans = 0;
  fore(i, 1, n - 1) if (s[0][i] == '.' && s[0][i - 1] == '.' &&
                        s[0][i + 1] == '.' && s[1][i] == '.') {
    int cnt = 0;
    if (s[1][i - 1] == 'x') cnt++;
    if (s[1][i + 1] == 'x') cnt++;
    if (cnt == 2) ans++;
  }
  fore(i, 1, n - 1) if (s[1][i] == '.' && s[1][i - 1] == '.' &&
                        s[1][i + 1] == '.' && s[0][i] == '.') {
    int cnt = 0;
    if (s[0][i - 1] == 'x') cnt++;
    if (s[0][i + 1] == 'x') cnt++;
    if (cnt == 2) ans++;
  }
  cout << ans << "\n";
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
