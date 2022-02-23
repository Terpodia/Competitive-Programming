// https://codeforces.com/problemset/problem/919/D

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rep(i,x,n) for (__typeof(n) i=(x); i!=(n); i+=1-2*(x>n))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n=============================================\n";

const int MAXN = 3e5;

typedef vector<int> vi;

int n, m;
string s;
vi G[MAXN], color;
bool can=true;

void dfs(int u, vi& toposort) {
  color[u]=1;
  for (int v : G[u]) {
    if (!color[v]) dfs(v, toposort);
    else if (color[v]==1) can = false;
  }
  color[u]=2;
  toposort.push_back(u);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m; 
  cin >> s;
  rep(i, 0, m) {
    int u, v; 
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
  }
  int ans=0;
  vi dp(n+1,0);
  rep(i, 0, 26) {
    color = vector<int>(n, 0);
    char c = (char)(i+(int)'a');
    vi toposort;
    rep(j, 0, n) {
      if (!color[j]) dfs(j, toposort);
    }
    if (!can) break;
    reverse(all(toposort));
    while (!toposort.empty()) {
      int u = toposort.back(), val = (s[u] == c) ? 1 : 0;
      toposort.pop_back();
      dp[u] = val;
      for (int v : G[u]) dp[u] = max(dp[u], dp[v]+val);
      ans = max(ans, dp[u]);
    }
  }
  if (!can) cout << "-1\n";
  else cout << ans << "\n";
  return 0;
}

