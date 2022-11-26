#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

#define sz(x) (int)x.size()

const int MAXN = 2e5, MAXLOG = 30, INF = 1e9;

vector<int> G[MAXN], e, d;
map<int, int> f;
bool vis[MAXN];

struct sparse_table {
  vector<vector<pi>> st;

  sparse_table(vector<int>& a) {
    st = vector<vector<pi>>(sz(a), vector<pi>(MAXLOG, make_pair(INF, -1)));

    for (int i = 0; i < sz(a); i++) st[i][0] = make_pair(a[i], i);

    for (int j = 1; j <= MAXLOG; j++) {
      for (int i = 0; i + (1 << j) - 1 < sz(a); i++) {
        pair<int, int> p1 = st[i][j - 1];
        pair<int, int> p2 = st[i + (1 << (j - 1))][j - 1];

        if (p1.first < p2.first)
          st[i][j] = p1;
        else
          st[i][j] = p2;
      }
    }
  }

  int calc(int l, int r) {
    int ret = -1, lo = INF;

    for (int j = MAXLOG; j >= 0; j--) {
      if ((1 << j) <= r - l + 1) {
        if (lo > st[l][j].first) {
          lo = st[l][j].first;
          ret = st[l][j].second;
        }
        l += 1 << j;
      }
    }

    return ret;
  }
};

void euler_tour(int u, int depth = 0) {
  vis[u] = true;
  d.push_back(depth);
  e.push_back(u);

  for (int v : G[u]) {
    if (vis[v]) continue;
    euler_tour(v, depth + 1);
    e.push_back(u);
    d.push_back(depth);
  }
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  euler_tour(0);

  for (int i = 0; i < sz(e); i++) {
    if (f.find(e[i]) == f.end()) f[e[i]] = i;
  }

  sparse_table st(d);

  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    int l = f[u], r = f[v];
    if (l > r) swap(l, r);

    int pos = st.calc(l, r);

    printf("%d\n", e[pos]);
  }

  return 0;
}
