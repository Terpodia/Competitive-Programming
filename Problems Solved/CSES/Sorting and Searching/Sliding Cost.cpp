#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second

typedef long long ll;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  ll a[n];
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  ordered_set<pair<ll, int>> s;
  for (int i = 0; i < k; i++) s.insert({a[i], i});

  ll cur = s.find_by_order((k + 1) / 2 - 1)->fst, acc = 0;
  for (int i = 0; i < k; i++) acc += abs(a[i] - cur);

  printf("%lld ", acc);

  for (int i = k; i < n; i++) {
    acc -= abs(a[i - k] - cur);
    s.erase({a[i - k], i - k});

    s.insert({a[i], i});

    if (k % 2 == 0) {
      acc -= abs(cur - s.find_by_order((k + 1) / 2)->fst);
      acc += abs(s.find_by_order((k + 1) / 2 - 1)->fst -
                 s.find_by_order((k + 1) / 2)->fst);
    }

    cur = s.find_by_order((k + 1) / 2 - 1)->fst;
    acc += abs(a[i] - cur);

    printf("%lld ", acc);
  }
  puts("");
  return 0;
}
