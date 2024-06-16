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

const int MAXN = 1e7 + 10;
int cr[MAXN];
vector<ll> p;
void init_sieve() {
  for (int i = 2; i < MAXN; i += 2) cr[i] = 2;
  p.pb(2);
  for (int i = 3; i < MAXN; i += 2)
    if (!cr[i]) {
      p.pb(i), cr[i] = i;
      for (ll j = 1LL * i * i; j < MAXN; j += i) cr[j] = i;
    }
}

vector<int> path;
vector<vector<int>> g;
vector<vector<bool>> can;

void dfs(int u) {
  while (len(g[u])) {
    int v = g[u].back();
    g[u].pop_back();
    if (!can[u][v]) continue;
    can[u][v] = can[v][u] = false;
    dfs(v);
  }
  path.pb(u);
}

void construct(int k) {
  path.clear();
  g = vector<vector<int>>(k);
  can = vector<vector<bool>>(k, vector<bool>(k, true));
  int cnt = k;
  vector<bool> flag(k, false);
  flag[0] = true, flag[k - 1] = true;
  forn(i, k) {
    forn(j, k) {
      if (k % 2 == 0 && cnt > 2 && i != j && !flag[i] && !flag[j]) {
        flag[i] = true;
        flag[j] = true;
        cnt -= 2;
        can[i][j] = can[j][i] = false;
        continue;
      }
      if (can[i][j]) g[i].pb(j);
    }
  }
  dfs(0);
  reverse(all(path));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init_sieve();

  vector<int> cnt(1418, 0);
  int cur = 2, inc = 5;
  for (int i = 1; i < 1418; i += 2) {
    cnt[i] = cur;
    cur += inc;
    inc += 4;
  }
  cur = 4, inc = 6;
  for (int i = 2; i < 1418; i += 2) {
    cnt[i] = cur;
    cur += inc;
    inc += 4;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int k = 1;
    fore(i, 1, 1418) {
      if (cnt[i] >= n) {
        k = i;
        break;
      }
    }
    construct(k);

    forn(i, n) { cout << p[path[i]] << " "; }
    cout << "\n";
  }
  return 0;
}
