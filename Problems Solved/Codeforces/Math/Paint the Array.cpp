#include <cstdio>
int aux;

typedef long long ll;

ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n;
    aux = scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; i++) aux = scanf("%lld", a + i);

    bool can = true;

    ll acc = 0;

    for (int i = 0; i < n; i += 2) acc = gcd(acc, a[i]);

    for (int i = 1; i < n; i += 2) {
      if (a[i] % acc == 0) can = false;
    }

    if (can) {
      printf("%lld\n", acc);
      continue;
    }

    can = true;
    acc = 0;

    for (int i = 1; i < n; i += 2) acc = gcd(acc, a[i]);

    for (int i = 0; i < n; i += 2) {
      if (a[i] % acc == 0) can = false;
    }

    if (can)
      printf("%lld\n", acc);
    else
      puts("0");
  }

  return 0;
}
