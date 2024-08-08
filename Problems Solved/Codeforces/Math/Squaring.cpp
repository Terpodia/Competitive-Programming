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
typedef long double ld;

void solve() {
  int n;
  cin >> n;
  ll a[n];
  forn(i, n) cin >> a[i];

  ll op[n];
  op[0] = 0;
  ll ans = 0;

  fore(i, 1, n) {
    if (a[i] == 1 && a[i - 1] > 1) {
      cout << "-1\n";
      return;
    }
    if (a[i] == 1) {
      op[i] = 0;
      continue;
    }

    ld x = logl(a[i - 1]) / logl(a[i]);
    if (x >= 1) {
      ll y = ceill(x);
      forn(b, 21) {
        if ((1LL << b) >= y) {
          op[i] = op[i - 1] + b;
          break;
        }
      }
    } else {
      fore(b, -20, 1) {
        if (powl(2, b) >= x && op[i - 1] >= -b) {
          op[i] = op[i - 1] + b;
          break;
        }
      }
    }
    ans += op[i];
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
