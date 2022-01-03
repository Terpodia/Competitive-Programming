#include <cstdio>
#include <algorithm>
using namespace std;
int aux;

typedef long long ll;

int main() {
  int tc; aux=scanf("%d",&tc);
  for (int _=1; _<=tc; _++) {
    ll n; aux=scanf("%lld",&n);
    ll num = n * (n-1);
    ll den = 4;

    ll g = __gcd(num, den);
    num /= g;
    den /= g;

    printf("Case %d: ", _);

    if (num % den == 0) printf("%lld\n", num/den);
    else printf("%lld/%lld\n", num, den);
  }

  return 0;
}

