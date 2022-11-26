#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int aux;

typedef long long ll;

const ll INF = 1e9;
const int MAXN = 2e5;

ll cnt[32][MAXN + 3];

int main() {
  for (ll i = 0; i < 32; i++) {
    for (ll j = 1; j <= MAXN; j++) {
      cnt[i][j] = cnt[i][j - 1];

      if ((j & (1 << i)) != 0) {
        cnt[i][j]++;
      }
    }
  }

  int t;
  aux = scanf("%d", &t);

  while (t--) {
    ll l, r;
    aux = scanf("%lld%lld", &l, &r);

    ll ans = INF;

    for (int i = 0; i < 32; i++)
      ans = min(ans, (r - l + 1) - (cnt[i][r] - cnt[i][l - 1]));

    printf("%lld\n", ans);
  }

  return 0;
}
