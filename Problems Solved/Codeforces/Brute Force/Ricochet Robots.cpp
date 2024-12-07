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

int n, w, h, l, ans;

vector<string> s;

map<vector<pair<int, int>>, int> d;

pair<int, int> target;
vector<pair<int, int>> p;

int nxt_right[11][11], nxt_left[11][11], nxt_up[11][11], nxt_down[11][11];

int move_right(int i, vector<pair<int, int>> &cur) {
  int res = nxt_right[cur[i].fst][cur[i].snd] - 1;
  forn(j,
       n) if (j != i && cur[j].fst == cur[i].fst && cur[j].snd > cur[i].snd) {
    res = min(res, cur[j].snd - 1);
  }
  return res;
}

int move_left(int i, vector<pair<int, int>> &cur) {
  int res = nxt_left[cur[i].fst][cur[i].snd] + 1;
  forn(j,
       n) if (j != i && cur[j].fst == cur[i].fst && cur[j].snd < cur[i].snd) {
    res = max(res, cur[j].snd + 1);
  }
  return res;
}

int move_up(int i, vector<pair<int, int>> &cur) {
  int res = nxt_up[cur[i].fst][cur[i].snd] + 1;
  forn(j,
       n) if (j != i && cur[j].snd == cur[i].snd && cur[j].fst < cur[i].fst) {
    res = max(res, cur[j].fst + 1);
  }
  return res;
}

int move_down(int i, vector<pair<int, int>> &cur) {
  int res = nxt_down[cur[i].fst][cur[i].snd] - 1;
  forn(j,
       n) if (j != i && cur[j].snd == cur[i].snd && cur[j].fst > cur[i].fst) {
    res = min(res, cur[j].fst - 1);
  }
  return res;
}

void solve() {
  queue<vector<pair<int, int>>> q;
  q.push(p);
  d[p] = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    int dist = d[cur];
    if (dist > l) break;
    if (cur[0] == target) {
      ans = dist;
      break;
    }
    forn(i, n) {
      int idx = move_right(i, cur);
      auto v = cur;
      v[i] = make_pair(cur[i].fst, idx);
      if (!d[v]) {
        d[v] = dist + 1;
        q.push(v);
      }
      idx = move_left(i, cur);
      v = cur;
      v[i] = make_pair(cur[i].fst, idx);
      if (!d[v]) {
        d[v] = dist + 1;
        q.push(v);
      }
      idx = move_up(i, cur);
      v = cur;
      v[i] = make_pair(idx, cur[i].snd);
      if (!d[v]) {
        d[v] = dist + 1;
        q.push(v);
      }
      idx = move_down(i, cur);
      v = cur;
      v[i] = make_pair(idx, cur[i].snd);
      if (!d[v]) {
        d[v] = dist + 1;
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> w >> h >> l;

  swap(w, h);
  s = vector<string>(w);
  p = vector<pair<int, int>>(n);

  forn(i, w) cin >> s[i];

  forn(i, w) forn(j, h) {
    if (s[i][j] == 'X')
      target = make_pair(i, j);
    else if (s[i][j] != '.' && s[i][j] != 'W') {
      p[s[i][j] - '1'] = make_pair(i, j);
    }
  }
  forn(i, w) {
    int cur = -1;
    forn(j, h) {
      if (s[i][j] == 'W') cur = j;
      nxt_left[i][j] = cur;
    }
    cur = h;
    dfor(j, h) {
      if (s[i][j] == 'W') cur = j;
      nxt_right[i][j] = cur;
    }
  }
  forn(j, h) {
    int cur = -1;
    forn(i, w) {
      if (s[i][j] == 'W') cur = i;
      nxt_up[i][j] = cur;
    }
    cur = w;
    dfor(i, w) {
      if (s[i][j] == 'W') cur = i;
      nxt_down[i][j] = cur;
    }
  }
  ans = INF;
  solve();
  if (ans > l)
    cout << "NO SOLUTION\n";
  else
    cout << ans << "\n";
  return 0;
}
