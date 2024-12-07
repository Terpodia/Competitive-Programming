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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n], b[n];
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    if (n <= 2)
      cout << "Bob\n";
    else {
      if (a[0] != b[0] && a[0] != b[n - 1])
        cout << "Alice\n";
      else if (a[n - 1] != b[0] && a[n - 1] != b[n - 1])
        cout << "Alice\n";
      else {
        bool can = false;
        if (a[0] == b[0]) {
          forn(i, n) can |= a[i] != b[i];
        } else {
          forn(i, n) can |= a[i] != b[n - 1 - i];
        }
        if (can)
          cout << "Alice\n";
        else
          cout << "Bob\n";
      }
    }
  }
  return 0;
}
