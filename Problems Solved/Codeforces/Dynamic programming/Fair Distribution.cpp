#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()

const int MAXN = 4e5 + 20, INF = 1e9;

int g, m, w[MAXN], s[MAXN], sum;

int dp[2][MAXN];

bool flag;

/*
int solve(int i, int W){
  if(i == m) return -INF;
  if(abs(W) >= MAXN/2) return -INF;
  int& ret = dp[i][W + MAXN/2];
  if(ret != -2) return ret;

  ret = -INF;
  if(!flag){
    if(W % g == 0 && abs(W) != sum) return ret=0;
  }
  else{
    if(W % g == 0) return ret=0;
  }

  if(solve(i+1, W) >= 0) return ret = 0;
  if(solve(i, W-2*w[i]) >= 0 && solve(i, W-2*w[i])+1 <= s[i])
    return ret = solve(i,W-2*w[i])+1;
  return ret;
}
*/

void solve() {
  for (int i = m - 1; i >= 0; i--) {
    for (int W = -sum; W <= sum; W++) {
      dp[i % 2][W + MAXN / 2] = -INF;
      if (!flag) {
        if (W % g == 0 && abs(W) != sum) {
          dp[i % 2][W + MAXN / 2] = 0;
          continue;
        }
      } else {
        if (W % g == 0) {
          dp[i % 2][W + MAXN / 2] = 0;
          continue;
        }
      }

      if (dp[(i + 1) % 2][W + MAXN / 2] >= 0) {
        dp[i % 2][W + MAXN / 2] = 0;
        continue;
      }

      int P = W - 2 * w[i];
      if (P + MAXN / 2 < 0) continue;

      if (dp[i % 2][P + MAXN / 2] >= 0 && dp[i % 2][P + MAXN / 2] < s[i])
        dp[i % 2][W + MAXN / 2] = dp[i % 2][P + MAXN / 2] + 1;
    }
  }
  if (dp[0][sum + MAXN / 2] >= 0)
    puts("Y");
  else
    puts("N");
}

int main() {
  int n;
  scanf("%d", &n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int G, R;
    scanf("%d%d", &G, &R);
    mp[G]++;
    if (G == 0) flag = true;
    g = __gcd(g, R);
  }
  if (n == 1) {
    puts("N");
    return 0;
  }
  m = SZ(mp);
  int idx = 0;
  for (auto& [x, y] : mp) {
    w[idx] = x, s[idx++] = y;
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < MAXN; j++) dp[i][j] = -INF;

  for (int i = 0; i < m; i++) sum += w[i] * s[i];
  solve();

  return 0;
}
