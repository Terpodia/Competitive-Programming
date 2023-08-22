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

const ll INF = 1e18;
const int MAXN = 500;

int n, m;
vector<vl> G(MAXN, vl(MAXN, INF)), dist(MAXN, vl(MAXN, INF));

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void Floyd_Warshall() {
  forn(i, 0, n) forn(j, 0, n) {
    if (i == j)
      dist[i][j] = 0;
    else if (G[i][j] != INF)
      dist[i][j] = G[i][j];
  }

  forn(k, 0, n) forn(i, 0, n) forn(j, 0, n) dist[i][j] =
      min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
  setIO();
  int q;
  cin >> n >> m >> q;
  forn(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u][v] = G[v][u] = min(G[u][v], w);
  }

  Floyd_Warshall();

  while (q--) {
    int u, v;
    cin >> u >> v;
    if (dist[u - 1][v - 1] == INF)
      cout << "-1\n";
    else
      cout << dist[u - 1][v - 1] << endl;
  }

  return 0;
}
