// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rep(i, x, n) for (__typeof(n) i=(x); i!=(n); i+=1-2*((x)>(n))) 
#define dbg(x) cout << #x << "=" << x;
#define line cout << "\n===============================\n"

typedef long long ll;

const int MAXN = 100, MAXW = 1e5;
const ll INF = 1e18;

int N, W, w[MAXN];
ll v[MAXN], dp[2][MAXW+1];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N >> W; 
  rep(i,0,N) cin >> w[i] >> v[i];

  rep(i,1,N+1) rep(j,0,W+1) {
    int prev = 1 - (i%2);
    dp[i%2][j] = dp[prev][j];
    if (j - w[i-1] >= 0) 
      dp[i%2][j] = max(dp[i%2][j], v[i-1]+dp[prev][j-w[i-1]]);
  }
  cout << dp[N%2][W] << "\n";
  return 0;
}

