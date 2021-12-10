#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int aux;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int n, m; aux=scanf("%d%d",&n,&m);  
  ll a[n][m];
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      aux=scanf("%lld",a[i]+j);

  ll pref[n+1][m+1];
  memset(pref, 0, sizeof(pref));

  for (int i=1; i<=n; i++) 
    for (int j=1; j<=m; j++)
      pref[i][j] = pref[i][j-1] + a[i-1][j-1];

  ll ans=-INF;

  for (int l=1; l<=m; l++) {
    for (int r=l; r<=m; r++) {
      ll sum=0;

      for (int i=1; i<=n; i++) {
        sum += pref[i][r] - pref[i][l-1]; 
        ans = max(ans, sum);
        if(sum < 0) sum = 0;
      }
    }
  }

  printf("%lld\n", ans);
  
  return 0;
}

