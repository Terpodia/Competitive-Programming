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
  int a[n], b[n];
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];

  int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

  forn(i, n) {
    if (a[i] == 1 && b[i] == 1)
      cnt3++;
    else if (a[i] == -1 && b[i] == -1)
      cnt4++;

    else if (a[i] == 1 && b[i] != 1)
      cnt1++;
    else if (a[i] != 1 && b[i] == 1)
      cnt2++;
  }
  int ans = -INF;
  forn(i, cnt3 + 1) {
    int cur1 = cnt1 + i, cur2 = cnt2 + cnt3 - i;
    int r = cnt4;

    if (cur1 > cur2) {
      int w = min(cur1 - cur2, r);
      cur1 -= w, r -= w;
    } else {
      int w = min(cur2 - cur1, r);
      cur2 -= w, r -= w;
    }
    if (cur1 > cur2) swap(cur1, cur2);
    ans = max(ans, cur1 - (r + 1) / 2);
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
