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

const int MAXN = 1e5;
vi G[MAXN], ok;
stack<int> ans;
int n, m, last = -1;

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

void findCycle(int u, bool& flag) {
  ok[u] = 1;
  for (int v : G[u]) {
    if (ok[v] == 0) findCycle(v, flag);
    if (ok[v] == 1) {
      last = v;
      flag = true;
    }

    if (flag) {
      ans.push(v);
      break;
    }
  }

  ok[u] = 2;
}

int main() {
  setIO();
  cin >> n >> m;
  ok = vi(n, 0);

  forn(i, 0, m) {
    int u, v;
    cin >> u >> v;
    G[u - 1].pb(v - 1);
  }

  bool can = false;

  forn(i, 0, n) {
    if (ok[i] == 0) findCycle(i, can);
    if (can) {
      ans.push(i);
      break;
    }
  }

  if (!can)
    cout << "IMPOSSIBLE\n";
  else {
    while (ans.top() != last) ans.pop();

    cout << sz(ans) << endl;
    while (!ans.empty()) {
      cout << ans.top() + 1 << " ";
      ans.pop();
    }
    cout << endl;
  }

  return 0;
}
