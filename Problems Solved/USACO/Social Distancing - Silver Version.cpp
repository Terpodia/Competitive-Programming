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

const ll INF = 1e18, MOD = 1e9 + 7;
const int MAXM = 1e5;

int N, M;
pll intervals[MAXM];

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

bool p(ll D) {
  int cnt = N - 1, pos = intervals[0].f, index = 0;

  while (cnt > 0 && index < M) {
    while (index < M) {
      if (intervals[index].f <= pos + D && pos + D <= intervals[index].s) {
        cnt--;
        pos = pos + D;
        break;
      }

      else if (intervals[index].f > pos + D) {
        pos = intervals[index].f;
        cnt--;
        break;
      }

      index++;
    }
  }

  return cnt == 0;
}

ll bs() {
  ll ans = 0, l = 1, r = INF, mid;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (p(mid)) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }

  return ans;
}

int main() {
  setIO("socdist");
  cin >> N >> M;

  forn(i, 0, M) cin >> intervals[i].f >> intervals[i].s;
  sort(intervals, intervals + M);

  cout << bs() << endl;

  return 0;
}
