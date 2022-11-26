#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5000;
int Q, N, cnt = 0;

vector<int> G[MAXN], R[MAXN];
vector<bool> vis(MAXN, false);

void DFS(int v, int k) {
  cnt++;
  vis[v] = true;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int u = G[v][i];
    int r = R[v][i];

    if (!vis[u] && r >= k) DFS(u, k);
  }
}

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("mootube.in");
  fout.open("mootube.out");

  fin >> N >> Q;

  for (int i = 0; i < N - 1; i++) {
    int u, v, r;
    fin >> u >> v >> r;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);

    R[u - 1].push_back(r);
    R[v - 1].push_back(r);
  }

  while (Q--) {
    int k, v;
    fin >> k >> v;
    cnt = 0;

    fill(vis.begin(), vis.end(), false);
    DFS(v - 1, k);
    fout << cnt - 1 << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
