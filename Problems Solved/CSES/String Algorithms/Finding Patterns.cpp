#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

const int MAXN = 5e5 + 7;
;

int to[MAXN][26], suff_link[MAXN], len[MAXN], sz = 1;
vector<int> leaf[MAXN];

void add(string& s, int idx) {
  int cur = 0;
  for (char c : s) {
    if (!to[cur][c - 'a']) {
      to[cur][c - 'a'] = sz++;
      len[to[cur][c - 'a']] = len[cur] + 1;
    }
    cur = to[cur][c - 'a'];
  }
  leaf[cur].pb(idx);
}
void push_links() {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front(), v = suff_link[u];
    fore(c, 0, 26) {
      if (to[u][c]) {
        suff_link[to[u][c]] = u ? to[v][c] : 0;
        q.push(to[u][c]);
      } else
        to[u][c] = to[v][c];
    }
    q.pop();
  }
}

bool ans[MAXN], vis[MAXN];
void dfs(int u) {
  vis[u] = true;
  fore(i, 0, SZ(leaf[u])) ans[leaf[u][i]] = true;
  if (!vis[suff_link[u]]) dfs(suff_link[u]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int k;
  cin >> s >> k;
  fore(i, 0, k) {
    string p;
    cin >> p;
    add(p, i);
  }
  push_links();
  int cur = 0;
  fore(i, 0, SZ(s)) {
    cur = to[cur][s[i] - 'a'];
    if (!vis[cur]) dfs(cur);
  }
  fore(i, 0, k) {
    if (ans[i])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
