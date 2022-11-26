#include <bits/stdc++.h>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

void topSort(vvi &G) {
  priority_queue<ll> Q;
  ll v, counter = 0;
  vi degrees(G.size(), 0), answer;
  forr(i, 0, G.size()) forr(j, 0, G[i].size()) degrees[G[i][j]]++;

  forr(i, 0, degrees.size()) if (degrees[i] == 0) Q.push(-i);

  while (!Q.empty()) {
    v = Q.top() * -1;
    Q.pop();
    answer.push_back(v + 1);

    forr(i, 0, G[v].size()) {
      degrees[G[v][i]]--;
      if (degrees[G[v][i]] == 0) {
        Q.push(-G[v][i]);
      }
    }
    counter++;
  }

  if (counter != G.size())
    cout << "Sandro fails.";
  else
    forr(i, 0, answer.size()) cout << answer[i] << " ";

  cout << "\n";
}

int main() {
  ll n, m, u, v;
  cin >> n >> m;

  vvi G(n);

  forr(i, 0, m) {
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
  }

  topSort(G);
  return 0;
}
