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

struct node {
  pair<int, int> pos;
  pair<int, int> father;
  char dir;
  int d;
};

typedef vector<int> vi;
typedef vector<vi> vvi;

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

const int MAXN = 1000, xd[4] = {1, -1, 0, 0}, yd[4] = {0, 0, 1, -1}, INF = 1e9;
int n, m;
char a[MAXN][MAXN];
queue<node> Q;
vvi dist(MAXN, vi(MAXN, INF));
node parents[MAXN][MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

bool inside(int i, int j) {
  return (i > -1 && j > -1 && i < n && j < m && a[i][j] != '#');
}

void BFS(bool monster, pair<int, int>& end) {
  while (!Q.empty()) {
    node c = Q.front();
    Q.pop();

    if (!monster) {
      parents[c.pos.first][c.pos.second] = c;
      if (c.pos.first == 0 || c.pos.first == n - 1 || c.pos.second == 0 ||
          c.pos.second == m - 1) {
        end = c.pos;
        return;
      }
    }

    forn(i, 0, 4) {
      int x = xd[i] + c.pos.first, y = yd[i] + c.pos.second;
      char dir;
      (i == 0)   ? dir = 'D'
      : (i == 1) ? dir = 'U'
      : (i == 2) ? dir = 'R'
                 : dir = 'L';

      if (inside(x, y) && c.d + 1 < dist[x][y]) {
        dist[x][y] = c.d + 1;
        Q.push({make_pair(x, y), c.pos, dir, dist[x][y]});
      }
    }
  }
}

int main() {
  fastIO();
  cin >> n >> m;
  pair<int, int> startpos, end = make_pair(-1, -1);

  forn(i, 0, n) forn(j, 0, m) {
    cin >> a[i][j];
    if (a[i][j] == 'A')
      startpos = {i, j};
    else if (a[i][j] == 'M')
      Q.push({make_pair(i, j), make_pair(-1, -1), '!', 0});
  }

  BFS(true, end);
  Q.push({startpos, make_pair(-1, -1), '!', 0});
  BFS(false, end);

  if (end != make_pair(-1, -1)) {
    cout << "YES\n";
    node c = parents[end.first][end.second];
    string ans;
    while (c.pos != startpos) {
      ans += c.dir;
      c = parents[c.father.first][c.father.second];
    }
    cout << sz(ans) << endl;
    rforn(i, sz(ans) - 1, 0) cout << ans[i];
    cout << endl;
  }

  else
    cout << "NO\n";

  return 0;
}
