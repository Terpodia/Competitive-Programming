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
  int u, v, r;
  bool operator<(const edge& e) const { return r < e.r; }
  bool operator>(const edge& e) const { return r > e.r; }
};

struct DSU {
  vi size, p;
  void init(int n) {
    size = vi(n, 1);
    p = vi(n);
    forn(i, 0, n) p[i] = i;
  }

  int get(int x) {
    if (p[x] != x) return p[x] = get(p[x]);
    return x;
  }

  void merge(int x, int y) {
    int rx = get(x), ry = get(y);
    if (size[rx] < size[ry]) {
      p[rx] = ry;
      size[ry] += size[rx];
    } else {
      p[ry] = rx;
      size[rx] += size[ry];
    }
  }
};

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void tc() {
  int t, ca = 1;
  cin >> t;
  while (t--) {
    ca++;
  }
}

int main() {
  setIO("mootube");
  int n, m;
  cin >> n >> m;
  edge edges[n - 1];
  pair<pi, int> queries[m];
  int ans[m];
  DSU dsu;
  dsu.init(n);

  forn(i, 0, n - 1) { cin >> edges[i].u >> edges[i].v >> edges[i].r; }

  forn(i, 0, m) {
    cin >> queries[i].f.f >> queries[i].f.s;
    queries[i].s = i;
  }

  sort(edges, edges + (n - 1), greater<edge>());
  sort(queries, queries + m);

  int p = 0;

  rforn(i, m - 1, 0) {
    forn(j, p, n - 1) {
      if (edges[j].r >= queries[i].f.f) {
        dsu.merge(edges[j].u - 1, edges[j].v - 1);
        p = j + 1;
      } else
        break;
    }
    ans[queries[i].s] = dsu.size[dsu.get(queries[i].f.s - 1)] - 1;
  }

  forn(i, 0, m) cout << ans[i] << endl;

  return 0;
}
