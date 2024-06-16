#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
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

const int MAXN = 2e5 + 10;

int n;
vector<int> g[MAXN];
int h[MAXN];

void dfs(int u, int p = -1) {
  if (p != -1) h[u] = h[p] + 1;
  for (int v : g[u])
    if (v != p) {
      dfs(v, u);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, n) {
    int p;
    cin >> p;
    p--;
    if (p != -1) {
      g[i].pb(p);
      g[p].pb(i);
    }
  }
  dfs(0);
  set<pair<int, int>> s;

  set<int> del;

  vector<int> ans;

  int deg[n];

  forn(i, n) {
    deg[i] = len(g[i]);
    if (deg[i] % 2 == 0) s.insert({-h[i], i});
  }

  while (!s.empty()) {
    int u = s.begin()->snd;
    ans.pb(u + 1);
    del.insert(u);
    s.erase(s.begin());
    for (int v : g[u]) {
      if (del.find(v) != del.end()) continue;

      deg[v]--;
      if (deg[v] % 2 == 1)
        s.erase({-h[v], v});
      else
        s.insert({-h[v], v});
    }
  }

  if (len(ans) < n)
    cout << "NO\n";
  else {
    cout << "YES\n";
    forn(i, n) cout << ans[i] << "\n";
  }
  return 0;
}
