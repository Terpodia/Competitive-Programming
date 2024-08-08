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
  int b[n];
  b[0] = a[0];
  priority_queue<int> q;
  fore(i, 1, n) {
    if (a[i] < b[i - 1]) q.push(a[i] - b[i - 1]);
    b[i] = max(b[i - 1], a[i]);
  }
  ll ans = 0;
  int cur = 0;
  while (!q.empty()) {
    int x = -q.top();
    ans += (ll)(len(q) + 1) * (ll)(x - cur);
    cur = x;
    q.pop();
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
