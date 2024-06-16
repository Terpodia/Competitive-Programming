#pragma GCC optimize("O3,unroll-loops")

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include <bits/stdc++.h>
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    int ans = 0;
    forn(i, n - 1) if (a[n - 1] % a[i] != 0) ans = n;

    vector<ll> d;
    for (ll i = 1; i * i <= (ll)a[n - 1]; i++)
      if (a[n - 1] % i == 0) {
        d.pb(i);
        if (a[n - 1] / i != i) d.pb(a[n - 1] / i);
      }
    for (ll i : d) {
      auto it = lower_bound(all(a), i);
      if (it != a.end() && *it == i) continue;

      ll l = 1;
      int res = 0;

      forn(j, n) {
        if (i % a[j] == 0) {
          res++;
          l = (l / __gcd(l, a[j])) * a[j];
        }
        if (l == i) ans = max(ans, res);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
