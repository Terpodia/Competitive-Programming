/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
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

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> ii;

struct node {
  ii pos;
  ii father;
  char dir;
};

#define endl "\n"
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, (b), sizeof(a))
#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
#define rforn(i, x, n) for (int i = (x); i >= (int)(n); i--)
#define forsn(i, x, n, a) for (int i = (x); i < (int)(n); i += a)
#define rforsn(i, x, n, a) for (int i = (x); i >= (int)(n); i -= a)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back

const ll INF = 1e18, MOD = 1e9 + 7;
const int MAXN = 1000, xd[4] = {1, -1, 0, 0}, yd[4] = {0, 0, 1, -1};

int N, M;
char a[MAXN][MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void tc() {
  int t, ca = 1;
  cin >> t;
  while (t--) {
    ca++;
  }
}

bool inside(int i, int j) {
  return (i > -1 && j > -1 && i < N && j < M && a[i][j] != '#');
}

void solve(ii start, ii end) {
  bool vis[N][M];
  mem(vis, false);
  queue<node> Q;
  Q.push({start, {-1, -1}, '!'});
  pair<ii, char> ans[N][M];
  ans[0][0] = {make_pair(-1, -1), '!'};

  vis[start.first][start.second] = true;

  while (!Q.empty()) {
    node n = Q.front();
    Q.pop();
    ii p = n.pos;
    ans[p.first][p.second].first = n.father;
    ans[p.first][p.second].second = n.dir;

    if (p == end) break;

    forn(i, 0, 4) {
      char c;
      if (i == 0)
        c = 'D';
      else if (i == 1)
        c = 'U';
      else if (i == 2)
        c = 'R';
      else
        c = 'L';

      int x2 = p.first + xd[i], y2 = p.second + yd[i];
      if (inside(x2, y2) && !vis[x2][y2]) {
        Q.push({make_pair(x2, y2), p, c});
        vis[x2][y2] = true;
      }
    }
  }

  if (!vis[end.first][end.second]) {
    cout << "NO\n";
    return;
  }

  ii p = end;
  string s;
  while (p != start) {
    s += ans[p.first][p.second].second;
    p = ans[p.first][p.second].first;
  }

  cout << "YES\n" << sz(s) << endl;
  rforn(i, sz(s) - 1, 0) cout << s[i];
  cout << endl;
}

int main() {
  fastIO();
  cin >> N >> M;

  ii start, end;

  forn(i, 0, N) forn(j, 0, M) {
    cin >> a[i][j];
    if (a[i][j] == 'A')
      start = make_pair(i, j);
    else if (a[i][j] == 'B')
      end = make_pair(i, j);
  }

  solve(start, end);

  return 0;
}
