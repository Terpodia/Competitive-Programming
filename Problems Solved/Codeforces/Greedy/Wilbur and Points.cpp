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
#define dfor(i, n) for (auto i = n; i >= 0; i--)
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
typedef pair<int, int> ii;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, vector<ii>> m1;
  map<int, vector<int>> m2;
  forn(i, n) {
    int x, y;
    cin >> x >> y;
    m1[y - x].pb({x, y});
  }
  forn(i, n) {
    int w;
    cin >> w;
    m2[w].pb(i);
  }
  ii ans[n];
  forn(i, n) ans[i] = {-1, -1};
  for (auto [w, v] : m2) {
    if (len(v) != len(m1[w])) {
      cout << "NO\n";
      return 0;
    }
    sort(all(m1[w]));
    dfor(i, len(m1[w]) - 1) { ans[v[i]] = {m1[w][i].fst, m1[w][i].snd}; }
  }
  bool can = true;
  map<pair<int, int>, int> val, hi;
  forn(i, n) val[ans[i]] = hi[ans[i]] = i;

  int x = 0, y = 0;
  while (hi.find({x, y}) != hi.end()) {
    x = 1;
    while (hi.find({x, y}) != hi.end()) {
      hi[make_pair(x, y)] = max(hi[make_pair(x, y)], hi[make_pair(x - 1, y)]);
      x++;
    }
    x = 0, y++;
  }
  x = 0, y = 0;
  while (hi.find({x, y}) != hi.end()) {
    y = 1;
    while (hi.find({x, y}) != hi.end()) {
      hi[make_pair(x, y)] = max(hi[make_pair(x, y)], hi[make_pair(x, y - 1)]);
      y++;
    }
    x++, y = 0;
  }

  for (auto &[a, b] : hi) {
    if (b > val[a]) can = false;
  }
  if (!can)
    cout << "NO\n";
  else {
    cout << "YES\n";
    forn(i, n) cout << ans[i].fst $ ans[i].snd << "\n";
  }
  return 0;
}
