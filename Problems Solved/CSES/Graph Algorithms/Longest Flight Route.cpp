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

const int MAXN = 1e5 + 7, INF = 1e9;
int n, m, dp[MAXN], nextNode[MAXN];
vi G[MAXN];

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int solve(int u) {
  if (u == n - 1) return dp[u] = 1;
  if (dp[u] != -1) return dp[u];

  int mxPath = -INF, mxNode = -1;

  for (int v : G[u]) {
    int p = solve(v) + 1;
    if (p > mxPath) {
      mxPath = p;
      mxNode = v;
    }
  }

  nextNode[u] = mxNode;
  return dp[u] = mxPath;
}

void tc() {
  int t, ca = 1;
  cin >> t;
  while (t--) {
    ca++;
  }
}

int main() {
  setIO();
  memset(dp, -1, sizeof(dp));
  memset(nextNode, -1, sizeof(nextNode));

  cin >> n >> m;
  forn(i, 0, m) {
    int u, v;
    cin >> u >> v;
    G[u - 1].pb(v - 1);
  }

  solve(0);
  if (dp[0] < 1)
    cout << "IMPOSSIBLE\n";
  else {
    cout << dp[0] << endl;
    int i = 0;
    while (i >= 0) {
      cout << i + 1 << " ";
      i = nextNode[i];
    }
    cout << endl;
  }

  return 0;
}
