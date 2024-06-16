#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
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
    ll n, m;
    cin >> n >> m;
    ll acc = 0, ans = n;

    int k = 0;
    for (int i = 0; i <= 30; i++)
      if (n & (1LL << i)) k = i;

    for (int i = 0; i <= 30; i++) {
      if (n & (1LL << i))
        acc += (1LL << i);
      else {
        ll d = (1LL << i) - acc;
        if (i < k) d = min(d, acc + 1);
        if (d <= m) ans += (1LL << i);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
