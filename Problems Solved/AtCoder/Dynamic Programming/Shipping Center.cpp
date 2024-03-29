#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;

int N, M, K, dp[MAX][MAX], X[MAX];
pair<int, int> E[MAX];
vector<int> box;

int solve(int i, int j) {
  if (i == N || j == K) return 0;
  int& ret = dp[i][j];

  if (ret != -1) return ret;

  if (box[j] >= E[i].first) ret = E[i].second + solve(i + 1, j + 1);

  return ret = max(ret, solve(i + 1, j));
}

int main() {
  int Q;
  scanf("%d%d%d", &N, &M, &Q);

  for (int i = 0; i < N; i++) scanf("%d%d", &E[i].first, &E[i].second);

  sort(E, E + N, greater<pair<int, int>>());

  for (int i = 0; i < M; i++) scanf("%d", X + i);

  while (Q--) {
    memset(dp, -1, sizeof(dp));
    box.clear();

    int L, R;
    scanf("%d%d", &L, &R);

    for (int i = 0; i < L - 1; i++) box.push_back(X[i]);
    for (int i = R; i < M; i++) box.push_back(X[i]);

    K = (int)box.size();

    sort(box.begin(), box.end(), greater<int>());

    printf("%d\n", solve(0, 0));
  }

  return 0;
}
