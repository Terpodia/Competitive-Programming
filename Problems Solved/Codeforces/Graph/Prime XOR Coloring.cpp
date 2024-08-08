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
  if (n == 1) {
    cout << "1\n1\n";
    return;
  }
  if (n == 2) {
    cout << "2\n1 2\n";
    return;
  }
  if (n == 3) {
    cout << "2\n1 2 2\n";
    return;
  }
  if (n == 4) {
    cout << "3\n1 2 2 3\n";
    return;
  }
  if (n == 5) {
    cout << "3\n1 2 2 3 3\n";
    return;
  }

  vector<int> ans(n + 1, 0);

  fore(i, 1, n + 1) {
    int x = i ^ 2;
    if (i % 2 == 0) {
      if (x >= 1 && x <= n) {
        if (ans[x] == 0)
          ans[i] = 1;
        else
          ans[i] = 2;
      } else
        ans[i] = 1;
    } else {
      if (x >= 1 && x <= n) {
        if (ans[x] == 0)
          ans[i] = 3;
        else
          ans[i] = 4;
      } else
        ans[i] = 3;
    }
  }
  cout << "4\n";
  fore(i, 1, n + 1) cout << ans[i] << " ";
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
