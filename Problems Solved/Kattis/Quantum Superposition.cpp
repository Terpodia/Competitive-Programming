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

#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
#define deb(x) cout << #x << " " << x << endl;
#define sz(x) (int)x.size()
#define pb push_back

const int MAXN = 1000, MAXQ = 2021;
int N1, M1, N2, M2;
int dp1[MAXN][MAXQ], dp2[MAXN][MAXQ];
vi G1[MAXN], G2[MAXN];

vector<bool> ans(MAXQ * 2 + 7, false);

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void calc1(int u, int k) {
  int &ret = dp1[u][k];

  if (ret != -1) return;

  ret = 1;
  if (u == N1 - 1) return;

  for (int v : G1[u]) calc1(v, k + 1);
}

void calc2(int u, int k) {
  int &ret = dp2[u][k];

  if (ret != -1) return;

  ret = 1;
  if (u == N2 - 1) return;

  for (int v : G2[u]) calc2(v, k + 1);
}

void query() {
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    if (ans[k])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}

int main() {
  setIO();
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  cin >> N1 >> N2 >> M1 >> M2;

  forn(i, 0, M1) {
    int u, v;
    cin >> u >> v;
    G1[u - 1].pb(v - 1);
  }

  forn(i, 0, M2) {
    int u, v;
    cin >> u >> v;
    G2[u - 1].pb(v - 1);
  }

  calc1(0, 0);
  calc2(0, 0);

  forn(i, 0, MAXQ) {
    forn(j, 0, MAXQ) {
      if (dp1[N1 - 1][i] == 1 && dp2[N2 - 1][j] == 1) ans[i + j] = true;
    }
  }

  query();

  return 0;
}
