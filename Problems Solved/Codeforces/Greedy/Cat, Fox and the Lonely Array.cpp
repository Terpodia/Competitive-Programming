#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
using namespace std;

// MACROS
#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
// FOR
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
// DEBUG
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

int bit(int x, int b) { return (x & (1 << b)) > 0; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n];
    forn(i, n) cin >> a[i];
    int k = 1;
    forn(b, 21) {
      bool can = true;
      forn(i, n - 1) can &= (bit(a[i], b) == bit(a[i + 1], b));
      if (can) continue;

      vector<int> v;
      forn(i, n) if (bit(a[i], b) == 1) v.pb(i);

      k = max(k, v[0] + 1);
      forn(i, len(v) - 1) k = max(k, v[i + 1] - v[i]);
      k = max(k, n - v.back());
    }
    cout << k << "\n";
  }
  return 0;
}
