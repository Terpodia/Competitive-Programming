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

#define mp make_pair

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

const ll INF = 1e18 + 10LL;

const int MAXM = 3e5 + 10;

ll n;
int m;

ll sx, sy, fx, fy, ans;

vector<pair<int, ll>> g[MAXM];

vector<pair<ll, ll>> pt;

bool cmp(pair<pair<ll, ll>, int> u, pair<pair<ll, ll>, int> v) {
  if (u.fst.snd != v.fst.snd) return u.fst.snd < v.fst.snd;
  return u.fst.fst < v.fst.fst;
}

void construct() {
  forn(i, m) {
    g[0].push_back({i + 1, min(abs(pt[i].fst - sx), abs(pt[i].snd - sy))});
    g[i + 1].push_back({0, abs(pt[i].fst - sx) + abs(pt[i].snd - sy)});
    g[m + 1].push_back({i + 1, min(abs(pt[i].fst - fx), abs(pt[i].snd - fy))});
    g[i + 1].push_back({m + 1, abs(pt[i].fst - fx) + abs(pt[i].snd - fy)});
  }

  vector<pair<pair<ll, ll>, int>> ptx(m), pty(m);
  forn(i, m) ptx[i] = {pt[i], i + 1};
  pty = ptx;
  sort(all(ptx));
  sort(all(pty), cmp);

  forn(i, m) {
    if (i > 0) {
      g[ptx[i].snd].push_back(
          {ptx[i - 1].snd, ptx[i].fst.fst - ptx[i - 1].fst.fst});
    }
    if (i < m - 1) {
      g[ptx[i].snd].push_back(
          {ptx[i + 1].snd, -ptx[i].fst.fst + ptx[i + 1].fst.fst});
    }
  }
  forn(i, m) {
    if (i > 0) {
      g[pty[i].snd].push_back(
          {pty[i - 1].snd, pty[i].fst.snd - pty[i - 1].fst.snd});
    }
    if (i < m - 1) {
      g[pty[i].snd].push_back(
          {pty[i + 1].snd, -pty[i].fst.snd + pty[i + 1].fst.snd});
    }
  }

  map<ll, vector<pair<ll, int>>> hor, ver;

  forn(i, m) hor[pt[i].fst].push_back({pt[i].snd, i + 1});
  forn(i, m) ver[pt[i].snd].push_back({pt[i].fst, i + 1});
  for (auto &[x, y] : hor) {
    sort(all(y));
    forn(i, len(y) - 1) {
      g[y[i].snd].push_back({y[i + 1].snd, 0LL});
      g[y[i + 1].snd].push_back({y[i].snd, 0LL});
    }
  }
  for (auto &[x, y] : ver) {
    sort(all(y));
    forn(i, len(y) - 1) {
      g[y[i].snd].push_back({y[i + 1].snd, 0LL});
      g[y[i + 1].snd].push_back({y[i].snd, 0LL});
    }
  }
}

ll dist[MAXM];
void dijkstra(int s) {
  forn(i, MAXM) dist[i] = INF;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  dist[s] = 0;
  pq.push(mp(0, s));
  while (!pq.empty()) {
    auto [p, u] = pq.top();
    pq.pop();
    if (p != dist[u]) continue;
    for (auto &[v, w] : g[u]) {
      if (p + w < dist[v]) dist[v] = p + w, pq.push(mp(p + w, v));
    }
  }
}

void solve() {
  construct();
  dijkstra(0);

  /*
  forn(i,m+2){
          dbg(g[i]);
  }
  */

  ans = min(ans, dist[m + 1]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> sx >> sy >> fx >> fy;
  pt = vector<pair<ll, ll>>(m);
  forn(i, m) { cin >> pt[i].fst >> pt[i].snd; }
  ans = abs(sx - fx) + abs(sy - fy);
  solve();
  cout << ans << "\n";
  return 0;
}
