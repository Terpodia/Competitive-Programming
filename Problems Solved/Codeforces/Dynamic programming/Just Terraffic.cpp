#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;
const int INF = 1e9;

int n, t[MAXN], dp[2][MAXN][2];
bool amb = false;

int solve1(int i, int j) {
  int& ret = dp[0][i][j];
  if (i == n) return ret = (j == 0) ? 0 : 1;
  if (ret != -1) return ret;
  if (i == n - 1) return ret = INF;

  if (j == 0) {
    if (t[i + 1] - t[i] >= 2000) return ret = INF;
    if (i + 2 < n && t[i + 2] - t[i + 1] <= 1000) return ret = INF;

    int r1 = solve1(i + 2, 0) + 1, r2 = solve1(i + 2, 1);
    if (r1 >= INF && r2 >= INF)
      return ret = INF;
    else if (r1 != r2 && r1 < INF && r2 < INF) {
      // if(!amb) cout<<"here\n";
      amb = true;
      return ret = -3;
    }
    if (r1 >= INF) swap(r1, r2);
    return ret = r1;
  }

  if (i + 2 >= n) return ret = INF;
  if (t[i + 1] - t[i] >= 2000 || t[i + 2] - t[i + 1] >= 2000) return ret = INF;
  if (i + 3 < n && t[i + 3] - t[i + 2] <= 1000) return ret = INF;

  int r1 = solve1(i + 3, 0) + 1, r2 = solve1(i + 3, 1);
  if (r1 >= INF && r2 >= INF)
    return ret = INF;
  else if (r1 != r2 && r1 < INF && r2 < INF) {
    // if(!amb) cout<<r1<<" "<<r2<<"\n";
    amb = true;
    return ret = -3;
  }
  if (r1 >= INF) swap(r1, r2);
  return ret = r1;
}

int solve2(int i, int j) {
  int& ret = dp[1][i][j];
  if (i == n) return ret = (j == 0) ? 1 : 0;
  if (ret != -1) return ret;
  if (i == n - 1) return ret = INF;

  if (j == 0) {
    if (t[i + 1] - t[i] >= 2000) return ret = INF;
    if (i + 2 < n && t[i + 2] - t[i + 1] <= 1000) return ret = INF;

    int r1 = solve2(i + 2, 0), r2 = solve2(i + 2, 1) + 1;
    if (r1 >= INF && r2 >= INF)
      return ret = INF;
    else if (r1 != r2 && r1 < INF && r2 < INF) {
      amb = true;
      return ret = -3;
    }
    if (r1 >= INF) swap(r1, r2);
    return ret = r1;
  }

  if (i + 2 >= n) return ret = INF;
  if (t[i + 1] - t[i] >= 2000 || t[i + 2] - t[i + 1] >= 2000) return ret = INF;
  if (i + 3 < n && t[i + 3] - t[i + 2] <= 1000) return ret = INF;

  int r1 = solve2(i + 3, 0), r2 = solve2(i + 3, 1) + 1;
  if (r1 >= INF && r2 >= INF)
    return ret = INF;
  else if (r1 != r2 && r1 < INF && r2 < INF) {
    amb = true;
    return ret = -3;
  }
  if (r1 >= INF) swap(r1, r2);
  return ret = r1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i];
  memset(dp, -1, sizeof(dp));
  int r1 = solve1(0, 0) + 1, r2 = solve1(0, 1);

  if (r1 >= INF && r2 >= INF)
    cout << "Impossible\n";
  else if (amb || (r1 != r2 && r1 < INF && r2 < INF))
    cout << "Ambiguous\n";
  else {
    if (r1 >= INF) swap(r1, r2);
    cout << "Cars without trailers: " << r1 - 1 << "\n";
    r1 = solve2(0, 0), r2 = solve2(0, 1) + 1;
    if (r1 >= INF) swap(r1, r2);
    cout << "Cars with trailers: " << r1 - 1 << "\n";
  }
  return 0;
}
