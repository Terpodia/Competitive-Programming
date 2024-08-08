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

const int MAXN = 1e4 + 10;

int n, m;
vector<int> g[MAXN];
vector<int> color;
bool ok;

void check(int u) {
  for (int v : g[u]) {
    if (color[v] == color[u]) ok = true;
    if (color[v] == -1) {
      color[v] = (color[u] == 0) ? 1 : 0;
      check(v);
    }
  }
}

void solve() {
  cin >> n >> m;
  forn(i, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  color = vector<int>(n, -1);
  ok = false;
  color[0] = 0;
  check(0);
  if (ok) {
    cout << "Alice" << endl;
    forn(i, n) {
      cout << "1 2" << endl;
      int idx, c;
      cin >> idx >> c;
    }
  } else {
    cout << "Bob" << endl;
    vector<int> v1, v2;
    forn(i, n) {
      if (color[i] == 0)
        v1.pb(i);
      else
        v2.pb(i);
    }
    forn(i, n) {
      int a, b;
      cin >> a >> b;
      if ((a == 1 || b == 1) && len(v1)) {
        cout << v1.back() + 1 << " " << 1 << endl;
        v1.pop_back();
      } else if ((a == 2 || b == 2) && len(v2)) {
        cout << v2.back() + 1 << " " << 2 << endl;
        v2.pop_back();
      } else if (len(v1)) {
        cout << v1.back() + 1 << " " << 3 << endl;
        v1.pop_back();
      } else {
        cout << v2.back() + 1 << " " << 3 << endl;
        v2.pop_back();
      }
    }
  }
  forn(i, n) g[i].clear();
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
