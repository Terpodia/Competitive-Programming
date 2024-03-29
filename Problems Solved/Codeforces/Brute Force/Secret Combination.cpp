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

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

string S;

string shift(string a) {
  string ret = a;
  forn(i, 0, sz(a)) ret[(i + 1) % sz(a)] = a[i];
  return ret;
}

string calc() {
  string a = S;
  string ret(sz(a), '9');
  forn(i, 0, sz(a)) {
    ret = min(ret, a);
    a = shift(a);
  }
  return ret;
}

string solve() {
  string ret(sz(S), '9');

  forn(i, 0, 11) {
    forn(j, 0, sz(S)) S[j] = (((S[j] - '0') + 1) % 10) + '0';
    ret = min(ret, calc());
  }

  return ret;
}

int main() {
  setIO();
  int n;
  cin >> n;
  cin >> S;
  cout << solve() << "\n";

  return 0;
}
