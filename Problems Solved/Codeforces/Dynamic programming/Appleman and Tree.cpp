#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

typedef long long ll;

const int MAXN = 1e5 + 3;
const ll MOD = 1e9 + 7;

int n;
vector<int> g[MAXN];
ll x[MAXN];

pair<ll, ll> dp[MAXN];

pair<ll, ll> solve(int u, int p = -1) {
  auto& ret = dp[u];
  if (ret.fst != -1) return ret;
  if (x[u] == 1)
    ret.fst = 1, ret.snd = 0;
  else
    ret.fst = 0, ret.snd = 1;

  for (int v : g[u])
    if (v != p) {
      auto [b, w] = solve(v, u);
      ll res1 = 0, res2 = 0;
      res1 += ((b * ret.snd) % MOD + (w * ret.fst) % MOD) % MOD;
      res2 += (w * ret.snd) % MOD;
      res1 += (b * ret.fst) % MOD;
      res2 += (b * ret.snd) % MOD;
      res1 %= MOD, res2 %= MOD;

      ret.fst = res1, ret.snd = res2;
    }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int v;
    cin >> v;
    g[i + 1].push_back(v);
    g[v].push_back(i + 1);
  }
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n + 10; i++) dp[i] = make_pair(-1LL, -1LL);
  cout << solve(0).fst << "\n";
  return 0;
}
