#include <cstdio>
#include <cstring>
int aux;

typedef long long ll;

const ll MOD = 1e9+7;

int n, m;

ll dp[10][1000][2];

ll f1(int i, int prev) {
  if (i == -1) return 1;
  ll& ret = dp[i][prev][0];

  if (ret != -1) return ret;
  ret = 0;

  for (int j=prev; j>=1; j--)
    ret = (ret + f1(i-1, j)) % MOD;

  return ret;
}

ll f2(int i, int prev) {
  if (i == -1) return 1;
  ll& ret = dp[i][prev][1];

  if (ret != -1) return ret;
  ret = 0;

  for (int j=prev; j<=n; j++)
    ret = (ret + f2(i-1, j)) % MOD;

  return ret;
}

int main() {
  aux=scanf("%d%d",&n,&m); 
  ll a[n+1], b[n+1];

  memset(dp, -1, sizeof(dp));

  for (int i=1; i<=n; i++) {
    a[i] = f1(m-2, i);  
    b[i] = f2(m-2, i);
  }

  ll ans=0;

  for (int i=1; i<=n; i++) {
    for (int j=i; j<=n; j++) 
      ans = (ans + ((a[i] * b[j]) % MOD)) % MOD;  
  }

  printf("%lld\n", ans);

  return 0;
}

