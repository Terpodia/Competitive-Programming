#include <cstdio>
#include <algorithm>
using namespace std;
int aux;

typedef long long ll;

const ll INF = 1e18;

int main() {
  int n; aux=scanf("%d",&n);
  ll a[n];
  for (int i=0; i<n; i++) aux=scanf("%lld",a+i);
  
  ll ans=-INF, sum=0;

  for (int i=0; i<n; i++) {
    sum += a[i];
    ans = max(ans, sum);
    if(sum < 0) sum = 0;
  }

  printf("%lld\n", ans);

  return 0;
}

