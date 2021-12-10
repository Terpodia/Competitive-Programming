#include <cstdio>
#include <algorithm>
using namespace std;
int aux;

typedef long long ll;

const ll INF = 2e9;

ll n, k;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    aux=scanf("%lld%lld",&n,&k);

    ll ans=0;
    ll j=0;
    for (ll i=0; ; i++) {
      if (((ll)1 << i) >= min(n, k)) { j = i; break; }
    }

    ans += j;
    ans += (max(n - ((ll)1 << j), (ll)0) + k - 1) / k;

    printf("%lld\n", ans);
  }

  return 0;
}

