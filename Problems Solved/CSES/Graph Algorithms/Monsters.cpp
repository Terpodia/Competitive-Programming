#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int INF = 1e9;

int n, m;
string s[1010];

const int rm[] = {1, -1, 0, 0}, cm[] = {0, 0, 1, -1};

struct Vertex {
  int i, j;
  int type;
};

void solve() {
  queue<Vertex> q;
  int d[n][m];
  pair<int, int> p[n][m];
  forn(i, n) forn(j, m) d[i][j] = INF;
  forn(i, n) forn(j, m) p[i][j] = {-1, -1};
  forn(i, n) forn(j, m) {
    if (s[i][j] == 'M') {
      d[i][j] = 0;
      q.push((Vertex){i, j, 1});
    }
  }
  forn(i, n) forn(j, m) {
    if (s[i][j] == 'A') {
      d[i][j] = 0;
      q.push((Vertex){i, j, 0});
    }
  }
  pair<int, int> lst = {-1, -1};
  while (!q.empty()) {
    Vertex u = q.front();
    q.pop();
    if (u.type == 0) {
      if (u.i == 0 || u.i == n - 1 || u.j == 0 || u.j == m - 1) {
        lst = {u.i, u.j};
        break;
      }
    }
    forn(_, 4) {
      int r = u.i + rm[_], c = u.j + cm[_];
      if (r < 0 || c < 0 || r >= n || c >= m) continue;
      if (d[r][c] < INF) continue;
      if (s[r][c] == '#') continue;
      d[r][c] = d[u.i][u.j] + 1;
      if (u.type == 0) p[r][c] = {u.i, u.j};
      q.push((Vertex){r, c, u.type});
    }
  }
  if (lst.fst == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  string ans = "";
  while (p[lst.fst][lst.snd].fst != -1) {
    pair<int, int> u = p[lst.fst][lst.snd];
    if (u.fst < lst.fst)
      ans += "D";
    else if (u.fst > lst.fst)
      ans += "U";
    else if (u.snd < lst.snd)
      ans += "R";
    else
      ans += "L";
    lst = u;
  }
  reverse(all(ans));
  cout << len(ans) << "\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  forn(i, n) cin >> s[i];
  solve();
  return 0;
}
