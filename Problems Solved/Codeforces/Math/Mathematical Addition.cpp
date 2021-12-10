#include <cstdio>
int aux;

typedef long long ll;

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    ll u,v;
    aux=scanf("%lld%lld",&u,&v);
    printf("%lld %lld\n", -u*u, v*v);
  }

  return 0;
}

