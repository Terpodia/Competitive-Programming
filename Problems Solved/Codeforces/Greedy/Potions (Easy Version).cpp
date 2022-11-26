#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
using ii = pair<ll, int>;

#define sz(x) (int)x.size()

const int MAXN = 2000;
int n;
ll a[MAXN];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);

  int ans = 0;
  priority_queue<ii> pq;

  ll b[n];
  memset(b, 0, sizeof(b));

  for (int i = 0; i < n; i++) pq.push({a[i], i});

  while (!pq.empty()) {
    ll x = pq.top().first;
    int p = pq.top().second;
    pq.pop();

    b[p] = x;
    ll s = 0;
    bool can = true;

    for (int i = 0; i < n; i++) {
      s += b[i];
      if (s < 0) {
        can = false;
        break;
      }
    }
    (!can) ? b[p] = 0 : ans++;
  }

  printf("%d\n", ans);

  return 0;
}
