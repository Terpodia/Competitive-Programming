#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
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
    sort(a, a + n);
    map<int, bool> m;
    forn(i, n) m[a[i]] = false;

    forn(i, n) if (a[i] % a[0] == 0) m[a[i]] = true;

    int j = 1;
    fore(i, 1, n) if (a[i] % a[0] != 0) {
      j = i;
      break;
    }

    forn(i, n) if (a[i] % a[j] == 0) m[a[i]] = true;

    bool can = true;
    for (auto &[x, y] : m) can &= y;

    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
