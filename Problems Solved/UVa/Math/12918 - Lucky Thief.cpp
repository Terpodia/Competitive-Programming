#include <iostream>
using namespace std;
int aux;

typedef long long ll;

int main() {
  int tc; aux=scanf("%d",&tc);
  while (tc--) {
    ll n, m;
    aux=scanf("%lld%lld",&n,&m);
    if (n > m) swap(n, m);

    printf("%lld\n", (n * (m-1 + m-n)) / 2);
  }

  return 0;
}

