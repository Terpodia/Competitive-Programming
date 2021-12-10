#include <cstdio>
#include <algorithm>
using namespace std;
int aux;

typedef long long ll;

int main() {
  int t; aux=scanf("%d",&t); 
  while (t--) {
    int n; ll k; aux=scanf("%d%lld",&n,&k);
    ll a[n+1];
    for (int i=0; i<n; i++) {
      int m; aux=scanf("%d",&m);
      ll acc=1;
      for (int j=0; j<m; j++) acc *= 10;
      a[i] = acc;
    }

    a[n] = 1e18;
    ll curr = k+1;
    ll ans=0;

    for (int i=0; i<n; i++) {
      ans += a[i] * min(curr, a[i+1]/a[i] - 1); 
      curr -= a[i+1]/a[i] - 1;
      if (curr <= 0) break;
    }
    printf("%lld\n", ans);
  } 

  return 0;
}

