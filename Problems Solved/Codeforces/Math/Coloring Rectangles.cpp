#include <algorithm>
#include <cstdio>
using namespace std;
int aux;

typedef long long ll;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    ll n, m;
    aux = scanf("%lld%lld", &n, &m);
    printf("%lld\n", (n * m + 2) / 3);
  }

  return 0;
}
