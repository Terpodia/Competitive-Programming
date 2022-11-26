#include <iostream>
#include <vector>
using namespace std;

#define GRAY (int)1
#define GREEN (int)2
#define BLACK (int)3

const int MAXN = 2 * 1e5;

int G[MAXN];
vector<int> rev_G[MAXN];
int N, it = 0;
vector<int> vis(MAXN, GRAY), ans(MAXN, -1);
vector<pair<int, int>> cycles[MAXN];
int c = -1;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

void addCycle(int v) {
  int cnt = 1;
  int u = G[v];
  cycles[it].push_back({v, 0});

  while (u != v) {
    cycles[it].push_back({u, 0});
    cnt++;
    u = G[u];
  }
  cycles[it][0].second = cnt;
}

void detectCycle(int i) {
  vis[i] = GREEN;
  if (vis[G[i]] == GRAY)
    detectCycle(G[i]);

  else if (vis[G[i]] == GREEN)
    c = G[i];

  vis[i] = BLACK;
}

void DFS(int v, int n, int i) {
  vis[v] = GREEN;
  if (ans[v] == -1) {
    ans[v] = cycles[i][0].second + n;
    n++;
  }
  for (int u : rev_G[v]) {
    if (vis[u] == GRAY) DFS(u, n, i);
  }
}

int main() {
  fastIO();
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> G[i];
    G[i]--;
    rev_G[G[i]].push_back(i);
  }

  for (int i = 0; i < N; i++) {
    if (vis[i] == GRAY) {
      detectCycle(i);
      if (c != -1) {
        addCycle(c);
        c = -1;
        it++;
      }
    }
  }

  fill(vis.begin(), vis.end(), GRAY);

  for (int i = 0; i < it; i++) {
    for (pair<int, int> j : cycles[i]) {
      ans[j.first] = cycles[i][0].second;
    }
    DFS(cycles[i][0].first, 1, i);
  }

  for (int i = 0; i < N; i++) cout << ans[i] << " ";

  cout << "\n";
  return 0;
}
