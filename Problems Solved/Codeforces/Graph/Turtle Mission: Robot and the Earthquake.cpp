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

void solve() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  forn(i, n) forn(j, m) cin >> a[i][j];

  int dist[n][m];
  forn(i, n) forn(j, m) dist[i][j] = INF;
  dist[0][0] = 0;
  queue<pair<int, int>> q;
  q.push({0, 0});

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    if (j < m - 1 && dist[(i + 1) % n][j + 1] == INF &&
        a[(i + 1) % n][j + 1] == 0) {
      dist[(i + 1) % n][j + 1] = dist[i][j] + 1;
      q.push({(i + 1) % n, j + 1});
    }
    if (dist[(i + 2) % n][j] == INF && a[(i + 1) % n][j] == 0 &&
        a[(i + 2) % n][j] == 0) {
      dist[(i + 2) % n][j] = dist[i][j] + 1;
      q.push({(i + 2) % n, j});
    }
  }

  /*
  forn(i,n){
          forn(j,m) cout<<dist[i][j]<<" ";
          cout<<"\n";
  }
  */

  int ans = INF;
  forn(i, n) {
    if (dist[i][m - 1] != INF) {
      int r = (n - 1 + dist[i][m - 1]) % n;
      int cnt = 0;
      if (r <= i)
        cnt = i - r;
      else
        cnt = n - r + i;
      ans = min(ans, dist[i][m - 1] + cnt);
    }
  }
  if (ans == INF)
    cout << "-1\n";
  else
    cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
