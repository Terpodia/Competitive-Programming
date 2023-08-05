#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll, ll> ii;

const ll INF = 1e18;

int c[26][26];
vector<ll> w[26];
string s;

vector<ii> G[26];

vector<ll> calc(int i) {
  vector<ll> dist(26, INF);
  dist[i] = 0;
  priority_queue<ii> pq;
  pq.push({-0, i});
  while (!pq.empty()) {
    auto [p, u] = pq.top();
    p *= -1;
    pq.pop();
    if (p != dist[u]) continue;

    for (auto& [v, weight] : G[u]) {
      if (dist[v] > p + weight) {
        dist[v] = p + weight;
        pq.push({-dist[v], v});
      }
    }
  }
  return dist;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) cin >> c[i][j];
  }
  cin >> s;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      G[i].push_back({j, c[i][j]});
    }
  }
  for (int i = 0; i < 26; i++) w[i] = calc(i);
  /*
  for(int i=0; i<26; i++){
    for(int j=0; j<26; j++){
      cout<<w[i][j]<<" ";
    }
    cout<<"\n";
  }
  */

  ll ans = 0;
  int i = 0, j = sz(s) - 1;

  while (i < j) {
    ll res = INF;
    for (int k = 0; k < 26; k++)
      res = min(res, w[s[i] - 'a'][k] + (ll)w[s[j] - 'a'][k]);
    ans += res;
    i++, j--;
  }
  cout << ans << "\n";

  return 0;
}
