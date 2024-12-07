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

int query(int u, int v) {
  cout << "? " << u << " " << v << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    fore(i, 1, n) {
      int u = 1, v = query(i + 1, u);
      while (v != i + 1) {
        if (v == -1) return 0;
        u = v;
        v = query(i + 1, u);
      }
      ans.pb({u, i + 1});
    }
    cout << "! ";
    for (auto [u, v] : ans) cout << u << " " << v << " ";
    cout << endl;
  }
  return 0;
}
