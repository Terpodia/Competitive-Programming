#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {
  int n;
  scanf("%d", &n);
  vector<ll> a(n), b(n), c(n), p(n + 10, 1);

  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i < n + 10; i++) p[i] = (p[i - 1] * 2LL) % MOD;

  for (int i = 0; i < n; i++) {
    ll cur = 0;
    for (int j = i; j < n; j += i + 1) cur = max(cur, a[j]);
    b[i] = cur;
  }
  c = b;
  sort(c.begin(), c.end());

  ll ans = 0;
  set<ll> s;
  for (int i = 0; i < n; i++) s.insert(a[i]);
  for (int i : s) {
    int j = (int)distance(c.begin(), lower_bound(c.begin(), c.end(), i));
    if (c[j] != i) continue;
    int k = (int)distance(c.begin(), upper_bound(c.begin(), c.end(), i));

    // printf("%d %d %d\n", i, j, k);

    ans += ((ll)i * (((((p[k - j] - 1) * (p[j])) % MOD) + MOD) % MOD)) % MOD;
    // printf("ans=%d\n", ans);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
