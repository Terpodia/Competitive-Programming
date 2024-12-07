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

struct restrictions {
  string s;
  int player;
  int cnt;
};

vector<int> g[2][120];

int comp[120];
bool vis[120];
vector<int> st;

void dfs1(int u) {
  vis[u] = true;
  for (int v : g[1][u])
    if (!vis[v]) dfs1(v);
  st.push_back(u);
}
void dfs2(int u, int idx) {
  comp[u] = idx;
  for (int v : g[0][u])
    if (comp[v] == -1) dfs2(v, idx);
}
void scc() {
  forn(i, 120) for (int v : g[0][i]) { g[1][v].pb(i); }
  for (int i = 0; i < 120; i++)
    if (!vis[i]) dfs1(i);
  reverse(st.begin(), st.end());
  for (int u : st)
    if (comp[u] == -1) dfs2(u, u);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  restrictions a[n];
  forn(i, n) cin >> a[i].s >> a[i].player >> a[i].cnt;
  int ans = 0;
  forn(c1, 26) fore(c2, c1 + 1, 26) fore(c3, c2 + 1, 26) {
    forn(i, 26) if (i != c1 && i != c2 && i != c3) {
      g[0][i + 26].pb(i + 2 * 26);
      g[0][i + 3 * 26].pb(i);

      g[0][i].pb(i + 3 * 26);
      g[0][i + 2 * 26].pb(i + 26);
    }
    forn(i, n) {
      int l1 = a[i].s[0] - 'A';
      int l2 = a[i].s[1] - 'A';
      if (a[i].player == 1) {
        if (a[i].cnt == 0) {
          g[0][l1].pb(l1 + 26);
          g[0][l2].pb(l2 + 26);
        } else if (a[i].cnt == 2) {
          g[0][l1 + 26].pb(l1);
          g[0][l2 + 26].pb(l2);
        } else {
          g[0][l1 + 26].pb(l2);
          g[0][l2 + 26].pb(l1);

          g[0][l1].pb(l2 + 26);
          g[0][l2].pb(l1 + 26);
        }
      } else {
        if (a[i].cnt == 0) {
          g[0][l1 + 2 * 26].pb(l1 + 3 * 26);
          g[0][l2 + 2 * 26].pb(l2 + 3 * 26);
        } else if (a[i].cnt == 2) {
          g[0][l1 + 3 * 26].pb(l1 + 2 * 26);
          g[0][l2 + 3 * 26].pb(l2 + 2 * 26);
        } else {
          g[0][l1 + 26 * 3].pb(l2 + 2 * 26);
          g[0][l2 + 26 * 3].pb(l1 + 2 * 26);

          g[0][l1 + 2 * 26].pb(l2 + 26 * 3);
          g[0][l2 + 2 * 26].pb(l1 + 26 * 3);
        }
      }
    }
    g[0][c1].pb(c1 + 26);
    g[0][c1 + 2 * 26].pb(c1 + 3 * 26);

    g[0][c2].pb(c2 + 26);
    g[0][c2 + 2 * 26].pb(c2 + 3 * 26);

    g[0][c3].pb(c3 + 26);
    g[0][c3 + 2 * 26].pb(c3 + 3 * 26);

    memset(comp, -1, sizeof(comp));
    forn(i, 120) vis[i] = false;
    st.clear();

    scc();
    bool can = true;
    forn(i, 26) {
      can &= comp[i] != comp[i + 26];
      can &= comp[i + 2 * 26] != comp[i + 3 * 26];
    }
    if (can) ans++;
    forn(j, 2) forn(i, 120) g[j][i].clear();
  }
  cout << ans << "\n";
  return 0;
}
