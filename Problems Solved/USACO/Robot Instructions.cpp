// "Si puedes imaginarlo, puedes programarlo" Alejandro Taboada

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n=========================================\n";

typedef long long ll;
typedef pair<ll, ll> ii;

struct hashll {
  size_t operator()(const ii& p) const { return p.f + 239 * p.s; }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N;
  cin >> N;

  ii op[N], goal;
  cin >> goal.f >> goal.s;
  rep(i, 0, N) cin >> op[i].f >> op[i].s;

  ll ans[N + 1];
  rep(i, 0, N + 1) ans[i] = 0;

  unordered_map<ii, vector<ll>, hashll> mp;

  rep(i, 0, 1 << ((N + 1) / 2)) {
    int cnt = 0;
    ii pos = {0, 0};
    rep(j, 0, (N + 1) / 2) if (i & (1 << j)) {
      pos.f += op[j].f, pos.s += op[j].s, cnt++;
    }
    if (mp[pos].empty()) mp[pos] = vector<ll>(N + 1, 0);
    mp[pos][cnt]++;
  }
  rep(i, 0, 1 << (N / 2)) {
    int cnt = 0;
    ii pos = {0, 0};
    rep(j, 0, N / 2) if (i & (1 << j)) {
      pos.f += op[j + (N + 1) / 2].f, pos.s += op[j + (N + 1) / 2].s, cnt++;
    }
    ii p = make_pair(goal.f - pos.f, goal.s - pos.s);
    if (mp[p].empty()) continue;

    for (int j = 0; cnt + j <= N; j++) {
      ans[cnt + j] += mp[p][j];
    }
  }
  rep(i, 1, N + 1) cout << ans[i] << "\n";

  return 0;
}

