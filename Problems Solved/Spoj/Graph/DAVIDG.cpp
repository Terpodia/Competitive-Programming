#include <bits/stdc++.h>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;

ll MOD = 1e9 + 7;

ll cost(ll x1, ll x2, ll y1, ll y2, ll P) {
  ll x = x1 - x2, y = y1 - y2;
  long double aux = (((x * x) % MOD) + ((y * y) % MOD)) % MOD;
  aux = sqrtl(aux);
  aux = aux * P;
  aux = ceil(aux);
  ll ans = aux;
  return ans % MOD;
}

ll Prim(vvi &G, vvi &W) {
  vi dist(G.size(), 1e15);
  vector<bool> vis(G.size(), false);

  priority_queue<ii> Q;
  Q.push({-0, 0});
  dist[0] = 0;

  ll u, v, w, p, answer = 0;
  ii arc;

  while (!Q.empty()) {
    arc = Q.top();
    Q.pop();
    p = -arc.first;
    v = arc.second;

    if (dist[v] != p) continue;
    vis[v] = true;

    answer = (answer + p) % MOD;

    forr(i, 0, G[v].size()) {
      u = G[v][i];
      w = W[v][i];
      if (w < dist[u] && !vis[u]) {
        dist[u] = w;
        Q.push({-w, u});
      }
    }
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll T, N, P, w;
  cin >> T;

  forr(i, 1, T + 1) {
    cin >> N >> P;
    ii pos[N];
    vvi G(N), W(N);
    forr(j, 0, N) cin >> pos[j].first >> pos[j].second;

    forr(j, 0, N) {
      forr(k, j + 1, N) {
        G[j].push_back(k);
        G[k].push_back(j);
        w = cost(pos[j].first, pos[k].first, pos[j].second, pos[k].second, P);
        W[j].push_back(w);
        W[k].push_back(w);
      }
    }
    cout << "Scenario #" << i << ": " << Prim(G, W) << "\n";
  }

  return 0;
}
