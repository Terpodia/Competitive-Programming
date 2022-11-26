#include <bits/stdc++.h>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll Prim(vvi &G, vvi &W) {
  priority_queue<ii> Q;
  Q.push({-0, 0});
  ii arc;
  ll w, u, v, p, answer = 0;
  vector<bool> vis(G.size(), false);

  while (!Q.empty()) {
    arc = Q.top();
    Q.pop();

    v = arc.second;
    p = -arc.first;
    if (!vis[v]) {
      vis[v] = true;
      answer += p;

      forr(i, 0, G[v].size()) {
        u = G[v][i];
        w = W[v][i];
        Q.push({-w, u});
      }
    }
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll N, M, u, v, w;
  cin >> N >> M;
  vvi G(N);
  vvi W(N);

  forr(i, 0, M) {
    cin >> u >> v >> w;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
    W[u - 1].push_back(w);
    W[v - 1].push_back(w);
  }

  cout << Prim(G, W) << "\n";
  return 0;
}
