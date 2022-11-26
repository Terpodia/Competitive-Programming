/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <algorithm>
#include <bitset>
#include <cassert>
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
using ld = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rforsn(i, x, n, a) for (int i = (x); i >= (int)(n); i -= a)
#define forsn(i, x, n, a) for (int i = (x); i < (int)(n); i += a)
#define rforn(i, x, n) for (int i = (x); i >= (int)(n); i--)
#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
#define dbg(x) cerr << #x << "=" << x << "\n";
#define line cerr << ".....................................\n"
#define all(cont) cont.begin(), cont.end()
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define s second
#define f first

const int xd[] = {1, -1, 0, 0}, yd[] = {0, 0, 1, -1};

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

int main() {
  setIO();
  int n;
  cin >> n;
  char a[n][n];
  forn(i, 0, n) forn(j, 0, n) cin >> a[i][j];

  bool check = true;

  forn(i, 0, n) forn(j, 0, n) {
    int cnt = 0;
    forn(_, 0, 4) {
      int x = xd[_] + i, y = yd[_] + j;
      if (x < 0 || y < 0 || x >= n || y >= n) continue;
      if (a[x][y] == 'o') cnt++;
    }
    check &= (cnt % 2 == 0);
  }

  (check) ? cout << "YES\n" : cout << "NO\n";

  return 0;
}
