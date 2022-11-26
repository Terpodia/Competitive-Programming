#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct cow {
  double x, y, p;
};

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN = 200, INF = 1e9;
vvi G(MAXN);
vector<bool> vis(MAXN, false);
int N;
cow cows[MAXN];

bool dist(cow a, cow b) {
  double d = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
  return d <= a.p;
}

void DFS(int node, int &cnt) {
  vis[node] = true;
  cnt++;
  for (int i : G[node])
    if (!vis[i]) DFS(i, cnt);
}

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("moocast.in");
  fout.open("moocast.out");

  fin >> N;
  for (int i = 0; i < N; i++) fin >> cows[i].x >> cows[i].y >> cows[i].p;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (dist(cows[i], cows[j]) && i != j) {
        G[i].push_back(j);
      }
    }
  }

  int ans = -INF;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    DFS(i, cnt);
    ans = max(ans, cnt);
    for (int j = 0; j < N; j++) vis[j] = false;
  }

  fout << ans << "\n";

  fin.close();
  fout.close();
  return 0;
}
