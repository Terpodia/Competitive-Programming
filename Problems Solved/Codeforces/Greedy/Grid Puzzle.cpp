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
  int a[n];
  forn(i, n) cin >> a[i];
  vector<bool> f(n, false);
  int ans = 0;
  forn(i, n) {
    if (a[i] == 0) continue;
    if (a[i] > 2)
      ans++;
    else {
      ans++;
      a[i] = 0;
      if (i + 1 >= n) continue;

      if (!f[i]) {
        a[i + 1] = max(0, a[i + 1] - 2);
        f[i + 1] = true;
      } else {
        if (a[i + 1] == 3)
          a[i + 1]--;
        else if (a[i + 1] == 4)
          a[i + 1] -= 2;
      }
    }
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
