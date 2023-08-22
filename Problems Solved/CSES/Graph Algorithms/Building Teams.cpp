#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool flag = true;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

void DFS(vvi &G, vector<bool> &vis, int n, vi &colors, int color) {
  vis[n] = true;
  colors[n] = color;
  for (int i : G[n]) {
    if (!vis[i])
      DFS(G, vis, i, colors, 1 - color);
    else if (colors[i] == colors[n])
      flag = false;
  }
}

int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  vvi G(n);
  vi colors(n, -1);
  vector<bool> vis(n, false);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i]) DFS(G, vis, i, colors, 0);
  }

  if (flag) {
    for (int i : colors) cout << i + 1 << " ";
    cout << "\n";
  } else
    cout << "IMPOSSIBLE\n";

  return 0;
}
