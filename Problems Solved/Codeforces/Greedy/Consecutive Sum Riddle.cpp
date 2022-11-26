#include <cstdio>
int aux;

typedef long long ll;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    ll n;
    aux = scanf("%lld", &n);
    printf("%lld %lld\n", -n + 1, n);
  }

  return 0;
}
