#include <iostream>
#include <algorithm>
using namespace std;
int aux;

typedef long long ll;

int main() {
  ll n, m, a, b;
  aux=scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
  ll res = n%m;

  ll ans = min((m-res) * a, (res) * b);
  printf("%lld\n", ans);

  return 0;
}

