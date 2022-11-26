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

struct shop {
  ll g, p;
  bool operator<(const shop& s) const {
    if (s.p != p) return p < s.p;
    return g < s.g;
  }

  bool operator>(const shop& s) const {
    if (s.p != p) return p > s.p;
    return g > s.g;
  }
};

const ll INF = 1e18, MOD = 1e9 + 7;
const int MAXN = 1e5;

int N, M, R;
shop s[MAXN];
ll c[MAXN], r[MAXN];

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void solve() {
  sort(c, c + N, greater<ll>());
  sort(s, s + M, greater<shop>());
  sort(r, r + R, greater<ll>());

  int a = 0, b = 0, p1 = 0, p2 = N - 1, newpos = -1;

  ll ans = 0, milk = 0, amount = -1;

  while (p1 <= p2 && (a < R || b < M)) {
    if (b >= M) {
      ans += r[a];
      p2--;
      a++;
    }

    else {
      if (amount == -1 && newpos == -1) {
        milk += c[p1];
        newpos = b;
        amount = 0;

        forn(i, b, M) {
          ll d = min(milk, s[i].g);

          amount += d * s[i].p;
          s[i].g -= d;
          milk -= d;

          if (s[i].g == 0) newpos++;
          if (milk == 0) break;
        }
      }

      if (a >= R) {
        ans += amount;
        p1++;
        b = newpos;
        newpos = amount = -1;
      }

      else {
        if (amount < r[a]) {
          ans += r[a];
          p2--;
          a++;
        }

        else {
          ans += amount;
          p1++;
          b = newpos;
          newpos = amount = -1;
        }
      }
    }
  }

  cout << ans << "\n";
}

int main() {
  setIO("rental");
  cin >> N >> M >> R;

  forn(i, 0, N) cin >> c[i];
  forn(i, 0, M) cin >> s[i].g >> s[i].p;
  forn(i, 0, R) cin >> r[i];

  solve();

  return 0;
}
