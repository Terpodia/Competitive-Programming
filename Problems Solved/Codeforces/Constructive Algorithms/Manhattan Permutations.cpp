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
  ll k;
  cin >> n >> k;
  if (k % 2 == 1) {
    cout << "NO\n";
    return;
  }
  vector<ll> p(n);
  forn(i, n) p[i] = i + 1;

  int l = 0, r = n - 1;
  while (r > l && k > 0) {
    if (2LL * (p[r] - p[l]) <= k) {
      k -= 2LL * (p[r] - p[l]);
      swap(p[l], p[r]);
      l++, r--;
      continue;
    }
    fore(i, l, r + 1) {
      if (2LL * (p[i] - p[l]) == k) {
        swap(p[l], p[i]);
        break;
      }
    }
    k = 0;
  }

  if (k > 0) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for (auto i : p) cout << i << " ";
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
