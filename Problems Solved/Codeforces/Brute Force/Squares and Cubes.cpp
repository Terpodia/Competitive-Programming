#include <cstdio>
#include <unordered_set>
using namespace std;
int aux;

#define sz(x) (int)x.size()

typedef long long ll;

int main() {
  int TC;
  aux = scanf("%d", &TC);
  while (TC--) {
    ll n;
    aux = scanf("%lld", &n);
    unordered_set<ll> us;

    for (ll i = 1; i * i <= n; i++) us.insert(i * i);
    for (ll i = 1; i * i * i <= n; i++) us.insert(i * i * i);

    printf("%d\n", sz(us));
  }

  return 0;
}
