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

const ll INF = 1e18, MOD = 1e9 + 7;

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();
  int x, n;
  cin >> x >> n;

  vi ans(n), p(n);

  set<int> s;

  forn(i, 0, n) {
    cin >> p[i];
    s.insert(p[i]);
  }

  s.insert(0);
  s.insert(x);

  int ret = 0;

  for (auto it = s.begin(); it != s.end(); it++) {
    auto next = it;
    next++;
    if (next == s.end()) break;
    ret = max(ret, *next - *it);
  }

  ans[n - 1] = ret;
  for (int i = n - 1; i > 0; i--) {
    auto prev = s.find(p[i]);
    auto next = prev;
    next++;
    prev--;

    ret = max(ret, *next - *prev);
    s.erase(p[i]);
    ans[i - 1] = ret;
  }

  forn(i, 0, n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}
