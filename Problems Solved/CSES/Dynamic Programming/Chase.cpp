// https://cses.fi/165/list/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n............................................\n";

typedef long long ll;

const int MAXN = 1e5;
const ll INF = 1e18;

int n, k;

vector<int> g[MAXN];
vector<ll> f;
ll sum[MAXN], ans[MAXN], res;

pair<ll, ll> dp1[MAXN][102], dp2[MAXN][102];

pair<ll, ll> combine(pair<ll, ll> x, pair<ll, ll> y) {
  pair<ll, ll> ret;
  ret.fst = max(x.fst, y.fst);
  ret.snd = min(x.fst, y.fst);
  ret.snd = max(ret.snd, x.snd);
  ret.snd = max(ret.snd, y.snd);
  return ret;
}

ll dfs(int u, int cnt = 0, int p = -1) {
  if (cnt == k) return 0;

  if (dp1[u][cnt].fst != -1) return max(dp1[u][cnt].fst, dp2[u][cnt].fst);

  dp1[u][cnt] = dp2[u][cnt] = mp(-INF, -INF);

  for (int v : g[u]) {
    if (v != p) {
      dp1[u][cnt] = combine(dp1[u][cnt], mp(dfs(v, cnt, u), -INF));
      dp2[u][cnt] = combine(
          dp2[u][cnt],
          mp(dfs(v, cnt + 1, u) + sum[u] - ((p == -1) ? 0 : f[p]), -INF));
    }
  }
  if (dp1[u][cnt].fst == -INF) dp1[u][cnt].fst = 0;
  if (dp2[u][cnt].fst == -INF) dp2[u][cnt].fst = 0;
  return max(dp1[u][cnt].fst, dp2[u][cnt].fst);
}

void go(int u, int p = -1) {
  ans[u] = res;

  for (int v : g[u]) {
    if (v != p) {
      rep(i, 0, k) {
        pair<ll, ll> v1 = dp1[v][i], v2 = dp2[v][i];
        pair<ll, ll> v3 = dp1[v][i + 1], v4 = dp2[v][i + 1];
        pair<ll, ll> v5 = dp1[v][i + 2], v6 = dp2[v][i + 2];

        pair<ll, ll> u1, u2, u3, u4;

        u1 = (dp1[u][i].fst == max(v1.fst, v2.fst)) ? mp(dp1[u][i].snd, -INF)
                                                    : dp1[u][i];

        u2 = (dp2[u][i].fst == max(v3.fst, v4.fst) + sum[u])
                 ? mp(dp2[u][i].snd - f[v], -INF)
                 : mp(dp2[u][i].fst - f[v], dp2[u][i].snd - f[v]);

        dp1[v][i] = combine(v1, combine(u1, u2));

        u3 = (dp1[u][i + 1].fst == max(v3.fst, v4.fst))
                 ? mp(dp1[u][i + 1].snd + sum[v], -INF)
                 : mp(dp1[u][i + 1].fst + sum[v], dp1[u][i + 1].snd + sum[v]);

        if (i == k - 1)
          u4 = mp(0, -INF);
        else {
          u4 = (dp2[u][i + 1].fst == max(v5.fst, v6.fst) + sum[u])
                   ? mp(dp2[u][i + 1].snd - f[v] + sum[v], -INF)
                   : mp(dp2[u][i + 1].fst - f[v] + sum[v],
                        dp2[u][i + 1].snd - f[v] + sum[v]);
        }

        dp2[v][i] = mp(v2.fst + f[u], v2.snd + f[u]);
        dp2[v][i] = combine(dp2[v][i], combine(u3, u4));
      }
      res = max(dp1[v][0].fst, dp2[v][0].fst);
      go(v, u);
    }
  }
}

int main() {
  scanf("%d%d", &n, &k);
  f = vector<ll>(n);
  rep(i, 0, n) scanf("%lld", &f[i]);

  rep(i, 0, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  if (k == 0) {
    puts("0");
    return 0;
  }

  rep(u, 0, n) for (int v : g[u]) sum[u] += f[v];
  rep(i, 0, n) rep(j, 0, 102) dp1[i][j] = dp2[i][j] = mp(-1, -1);
  rep(i, 0, n) rep(j, k, 102) dp1[i][j] = dp2[i][j] = mp(0, -INF);

  res = dfs(0);
  rep(i, 1, k) dfs(0, i);
  rep(i, 0, n) rep(j, 0, 102) if (dp1[i][j].fst == -1) {
    dp1[i][j] = dp2[i][j] = mp(0, -INF);
  }
  go(0);
  printf("%lld\n", *max_element(ans, ans + n));
  return 0;
}

