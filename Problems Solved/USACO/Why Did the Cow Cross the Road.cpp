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

struct node {
  pi pos;
  ll cost;
  int cnt;

  bool operator<(const node& n) const { return cost < n.cost; }
  bool operator>(const node& n) const { return cost > n.cost; }
};

const ll INF = 1e18;
const int MAXN = 100, xd[] = {1, -1, 0, 0}, yd[] = {0, 0, 1, -1};
int N;
ll T, a[MAXN][MAXN];

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

bool inside(int i, int j) { return (i >= 0 && j >= 0 && i < N && j < N); }

void solve() {
  priority_queue<node, vector<node>, greater<node>> pq;

  using vvl = vector<vl>;
  vector<vvl> dist(N, vvl(N, vl(3, INF)));

  dist[0][0][0] = 0;
  pq.push({mp(0, 0), 0, 0});

  while (!pq.empty()) {
    node n = pq.top();
    pq.pop();
    pi pos = n.pos;
    ll cost = n.cost;

    if (cost != dist[pos.f][pos.s][n.cnt]) continue;

    forn(i, 0, 4) {
      int x = pos.f + xd[i], y = pos.s + yd[i];
      if (!inside(x, y)) continue;

      ll w = cost + T;
      if ((n.cnt + 1) % 3 == 0) w += a[x][y];

      if (w < dist[x][y][(n.cnt + 1) % 3]) {
        dist[x][y][(n.cnt + 1) % 3] = w;
        pq.push({mp(x, y), w, (n.cnt + 1) % 3});
      }
    }
  }

  ll ans = min(dist[N - 1][N - 1][0],
               min(dist[N - 1][N - 1][1], dist[N - 1][N - 1][2]));
  cout << ans << endl;
}

int main() {
  setIO("visitfj");
  cin >> N >> T;

  forn(i, 0, N) forn(j, 0, N) cin >> a[i][j];

  solve();

  return 0;
}
