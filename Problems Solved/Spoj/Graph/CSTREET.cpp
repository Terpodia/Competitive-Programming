#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
 
ll Prim(vvi &G, vvi &W, ll a) {
  vi dist(G.size(), 1e9);
  vector<bool> vis(G.size(), false);
  priority_queue<ii> Q;
  Q.push({-0, 0});
  dist[0] = 0;
  ii arc;
  ll v, u, w, p, answer = 0;
 
  while (!Q.empty()) {
    arc = Q.top();
    Q.pop();
    p = -arc.first;
    v = arc.second;
 
    if(dist[v] != p) continue;
    vis[v] = true;
    answer += p;
 
    forr(i, 0, G[v].size()){
      u = G[v][i];
      w = W[v][i];
      if(w < dist[u] && !vis[u]){
        dist[u] = w;
        Q.push({-w, u});
      }
    }
  }
  return answer * a;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int t, n, m, p;
  cin >> t;
 
  forr(k, 0, t) {
    ll w, v, u;
    cin >> p >> n >> m;
    vvi G(n), W(n);
 
    forr(i, 0, m) {
      cin >> v >> u >> w;
      G[v - 1].push_back(u - 1);
      G[u - 1].push_back(v - 1);
      W[u - 1].push_back(w);
      W[v - 1].push_back(w);
    }
 
    cout << Prim(G, W, p) << "\n";
  }
 
  return 0;
} 

