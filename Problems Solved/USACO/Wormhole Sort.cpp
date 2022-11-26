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

struct DSU {
  vi p, size;

  void init(int n) {
    p = vi(n);
    size = vi(n, 1);
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

struct edge {
  int u, v, w;
  bool operator<(const edge& e) const { return w < e.w; }
  bool operator>(const edge& e) const { return w > e.w; }
};

const int INF = 1e9 + 7;

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
  setIO("wormsort");
  int N, M;
  cin >> N >> M;
  DSU dsu;
  dsu.init(N);
  vector<int> pos(N), sites(N);
  vector<edge> edges(M);
  vector<bool> ok(N, false);

  forn(i, 0, N) {
    cin >> pos[i];
    pos[i]--;
  }
  forn(i, 0, N) sites[pos[i]] = i;
  forn(i, 0, M) cin >> edges[i].u >> edges[i].v >> edges[i].w;

  sort(all(edges), greater<edge>());
  int cnt = 0;
  forn(i, 0, N) if (pos[i] == i) {
    cnt++;
    ok[i] = true;
  }

  int ans = INF;

  forn(i, 0, M) {
    if (cnt == N) break;

    int u = edges[i].u - 1, v = edges[i].v - 1, w = edges[i].w;
    if (dsu.get(u) != dsu.get(v)) {
      dsu.merge(u, v);
      ans = min(ans, w);
      if (!ok[sites[u]] && dsu.get(u) == dsu.get(sites[u])) {
        cnt++;
        ok[sites[u]] = true;
      }
      if (!ok[u] && dsu.get(pos[u]) == dsu.get(u)) {
        cnt++;
        ok[u] = true;
      }

      if (!ok[sites[v]] && dsu.get(v) == dsu.get(sites[v])) {
        cnt++;
        ok[sites[v]] = true;
      }
      if (!ok[v] && dsu.get(pos[v]) == dsu.get(v)) {
        cnt++;
        ok[v] = true;
      }
    }
  }

  if (ans == INF) ans = -1;
  cout << ans << endl;

  return 0;
}
