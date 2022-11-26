#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int, int>;

#define sz(x) (int)x.size()
#define f first
#define s second

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
  vector<vector<int>> pref(sz(mat) + 1, vector<int>(sz(mat[0]) + 1, 0)),
      ans(sz(mat), vector<int>(sz(mat[0])));

  for (int i = 1; i <= sz(mat); i++)
    for (int j = 1; j <= sz(mat[0]); j++)
      pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] +
                   mat[i - 1][j - 1];

  for (int i = 0; i < sz(mat); i++) {
    for (int j = 0; j < sz(mat[0]); j++) {
      ii s, d;
      s = {max(i - K, 0), max(j - K, 0)};
      d = {min(i + K, sz(mat) - 1), min(j + K, sz(mat[0]) - 1)};

      ans[i][j] = pref[d.f + 1][d.s + 1] - pref[d.f + 1][s.s] -
                  pref[s.f][d.s + 1] + pref[s.f][s.s];
    }
  }

  return ans;
}

int main(void) {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  vector<vector<int>> mat(N, vector<int>(M));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%d", &mat[i][j]);

  vector<vector<int>> ans = matrixBlockSum(mat, K);

  cout << "[";
  for (int i = 0; i < N; i++) {
    cout << "[";
    for (int j = 0; j < M; j++) {
      cout << ans[i][j] << ",";
    }
    if (i < N - 1)
      cout << "],";
    else
      cout << "]";
  }

  cout << "]\n";

  return 0;
}
