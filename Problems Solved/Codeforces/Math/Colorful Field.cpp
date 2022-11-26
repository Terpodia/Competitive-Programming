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

int main() {
  setIO();
  ll n, m;
  int k, t;
  cin >> n >> m >> k >> t;
  int a[k][2];

  forn(i, 0, k) {
    int x, y;
    cin >> x >> y;
    a[i][0] = x - 1, a[i][1] = y - 1;
  }

  while (t--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int ans = ((x * m) + y) % 3;

    bool flag = false;

    forn(i, 0, k) {
      if (a[i][0] == x && a[i][1] == y)
        flag = true;

      else if (a[i][0] < x)
        ans = ((ans - 1) + 3) % 3;
      else if (a[i][0] == x && a[i][1] < y)
        ans = ((ans - 1) + 3) % 3;
    }

    if (flag)
      cout << "Waste\n";
    else if (ans == 0)
      cout << "Carrots\n";
    else if (ans == 1)
      cout << "Kiwis\n";
    else
      cout << "Grapes\n";
  }

  return 0;
}
