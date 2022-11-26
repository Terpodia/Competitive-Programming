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

#define endl "\n"
#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
#define rforn(i, x, n) for (int i = (x); i >= (int)(n); i--)
#define forsn(i, x, n, a) for (int i = (x); i < (int)(n); i += a)
#define rforsn(i, x, n, a) for (int i = (x); i >= (int)(n); i -= a)
#define all(cont) cont.begin(), cont.end()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define deb(x) cout << #x << " " << x << endl;
#define pb push_back
#define f first
#define s second
#define mp make_pair

struct edge {
  int u, v;
  ll w;
  bool operator<(const edge& e) const { return w < e.w; }
};

struct DSU {
  vi p, size;
  int total;

  DSU(int n) {
    p = vi(n), size = vi(n, 1);
    total = n;
    forn(i, 0, n) p[i] = i;
  }

  int get(int x) {
    if (x != p[x]) return p[x] = get(p[x]);
    return x;
  }

  void merge(int x, int y) {
    int rx = get(x), ry = get(y);
    total--;

    if (size[rx] < size[ry]) {
      p[rx] = ry;
      size[ry] += size[rx];
    } else {
      p[ry] = rx;
      size[rx] += size[ry];
    }
  }
};

const int MAXN = 1e5;
int n, m;
edge edges[MAXN * 2];

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();
  cin >> n >> m;
  DSU dsu(n);
  forn(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges[i] = {u - 1, v - 1, w};
  }

  sort(edges, edges + m);
  ll ans = 0;

  forn(i, 0, m) {
    int ru = dsu.get(edges[i].u), rv = dsu.get(edges[i].v);
    if (ru != rv) {
      ans += edges[i].w;
      dsu.merge(edges[i].u, edges[i].v);
    }
  }

  if (dsu.total > 1)
    cout << "IMPOSSIBLE\n";
  else
    cout << ans << endl;

  return 0;
}
