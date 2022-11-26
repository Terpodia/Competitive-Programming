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
using vi = vector<int>;

#define endl "\n"
#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
#define deb(x) cout << #x << " " << x << endl;
#define pb push_back

const int MAXN = 1e5;

int N, M, C;
int S[MAXN];
vi G[MAXN], W[MAXN], in(MAXN, 0);

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void toposort() {
  queue<int> Q;
  forn(i, 0, N) if (in[i] == 0) Q.push(i);

  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    forn(i, 0, sz(G[u])) {
      int v = G[u][i], w = W[u][i];
      S[v] = max(S[v], S[u] + w);
      in[v]--;
      if (in[v] == 0) Q.push(v);
    }
  }
}

int main() {
  setIO("timeline");
  cin >> N >> M >> C;

  forn(i, 0, N) cin >> S[i];

  forn(i, 0, C) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u - 1].pb(v - 1);
    W[u - 1].pb(w);
    in[v - 1]++;
  }

  toposort();

  forn(i, 0, N) cout << S[i] << endl;

  return 0;
}
