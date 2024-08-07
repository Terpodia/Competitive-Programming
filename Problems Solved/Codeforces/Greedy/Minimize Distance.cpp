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

int n, k;

ll calc(vector<ll> &x) {
  if (!len(x)) return 0;

  sort(all(x));
  int r = len(x) % k;
  ll ret = 0;

  if (r > 0) ret += x[r - 1] * 2LL;

  for (int i = r + k - 1; i < len(x); i += k) {
    ret += 2LL * x[i];
  }
  ret -= x.back();
  return ret;
}

void solve() {
  cin >> n >> k;
  vector<ll> v1, v2;
  forn(i, n) {
    int x;
    cin >> x;
    if (x >= 0)
      v1.push_back(x);
    else
      v2.push_back(-x);
  }
  ll ans = calc(v1) + calc(v2);
  if (len(v1) > 0 && len(v2) > 0) ans += min(v1.back(), v2.back());
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
