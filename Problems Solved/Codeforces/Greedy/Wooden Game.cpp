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
  int k;
  cin >> k;
  int a[k];
  forn(i, k) {
    cin >> a[i];
    forn(j, a[i] - 1) {
      int p;
      cin >> p;
    }
  }
  sort(a, a + k);
  int ans = a[k - 1];
  dfor(i, k - 1) {
    int msk = a[i];
    bool flag = false;
    dfor(b, 30) {
      if (flag)
        msk |= (1 << b);
      else {
        int b1 = (ans & (1 << b));
        int b2 = (a[i] & (1 << b));
        if (b1 && b2) flag = true, msk ^= (1 << b);
      }
    }
    ans |= msk;
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
