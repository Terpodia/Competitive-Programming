#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
int aux;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n; aux=scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) {
      aux=scanf("%d",a+i); 
    }

    int ans[n][n+1];
    for (int i=0; i<n; i++) ans[i][0] = a[i];

    for (int i=1; i<=n; i++) {
      unordered_map<int,int> mp;
      for (int j=0; j<n; j++) mp[ans[j][i-1]]++;
      for (int j=0; j<n; j++) ans[j][i] = mp[ans[j][i-1]];
    }

    int q; aux=scanf("%d",&q);

    while (q--) {
      int x, k; aux=scanf("%d%d",&x,&k);
      k = min(k, n);
      printf("%d\n", ans[x-1][k]);
    }
  }

  return 0;
}

