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
#include <tuple>
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

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

void tc() {
  int t, _ = 1;
  cin >> t;
  while (t--) {
    _++;
  }
}

int main() {
  setIO();
  int a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];

  bool f1 = false, f2 = false;

  forn(i, 0, 4) forn(j, i + 1, 4) forn(z, j + 1, 4) {
    if (a[i] + a[j] > a[z] && a[z] + a[j] > a[i] && a[i] + a[z] > a[j])
      f1 = true;
    if (a[i] + a[j] >= a[z] && a[z] + a[j] >= a[i] && a[i] + a[z] >= a[j])
      f2 = true;
  }

  if (!f1 && !f2)
    cout << "IMPOSSIBLE\n";
  else if (!f1)
    cout << "SEGMENT\n";
  else
    cout << "TRIANGLE\n";

  return 0;
}
