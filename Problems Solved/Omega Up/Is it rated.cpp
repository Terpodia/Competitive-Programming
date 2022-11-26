#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n============================================\n";

const int MAXN = 1000;

typedef __uint128_t u128;
typedef long long ll;

struct problem {
  ll p, f, t;
  bool operator<(const problem& b) const { return f * b.t < b.f * t; }
};

int N, T;
problem a[MAXN];

int main() {
  scanf("%d%d", &N, &T);
  for (int i = 0; i < N; i++) scanf("%lld%lld%lld", &a[i].p, &a[i].f, &a[i].t);
  sort(a, a + N);

  ll dp[N + 1][T + 1];
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= T; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= a[i - 1].t) {
        dp[i][j] =
            max(dp[i][j], a[i - 1].p - a[i - 1].f * (T - (j - a[i - 1].t)) +
                              dp[i - 1][j - a[i - 1].t]);
      }
    }
  }

  printf("%lld\n", dp[N][T]);

  return 0;
}
