/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rforsn(i, x, n, a) for (int i = (x); i >= (int)(n); i -= a)
#define forsn(i, x, n, a) for (int i = (x); i < (int)(n); i += a)
#define rforn(i, x, n) for (int i = (x); i >= (int)(n); i--)
#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
#define deb(x) cout << #x << " " << x << endl;
#define all(cont) cont.begin(), cont.end()
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define endl "\n"
#define s second
#define f first

struct edge {
  int u, v;
  ll w;
  bool operator<(const edge& e) const { return w < e.w; }
  bool operator>(const edge& e) const { return w > e.w; }
};

struct DSU {
  vi p, size;

  DSU(int n) {
    p = vi(n), size = vi(n, 1);
    forn(i, 0, n) p[i] = i;
  }

  int get(int x) {
    if (p[x] != x) return p[x] = get(p[x]);
    return x;
  }

  void merge(int x, int y) {
    int rx = get(x), ry = get(y);
    if (size[rx] > size[ry]) {
      p[ry] = rx;
      size[rx] += size[ry];
    } else {
      p[rx] = ry;
      size[ry] += size[rx];
    }
  }
};

const int MAXN = 2000;
int N, ids[MAXN];

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO("superbull");
  cin >> N;
  forn(i, 0, N) cin >> ids[i];

  vector<edge> e;
  DSU dsu(N);

  forn(i, 0, N) forn(j, i + 1, N) {
    ll w = ids[i] ^ ids[j];
    e.pb({i, j, w});
    e.pb({j, i, w});
  }

  sort(all(e), greater<edge>());

  ll ans = 0;

  forn(i, 0, sz(e)) {
    int ru = dsu.get(e[i].u), rv = dsu.get(e[i].v);
    if (ru != rv) {
      ans += e[i].w;
      dsu.merge(ru, rv);
    }
  }

  cout << ans << endl;

  return 0;
}
