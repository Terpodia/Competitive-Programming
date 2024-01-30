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

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  ordered_set<pair<int, int>> s;
  for (int i = 0; i < k; i++) s.insert({a[i], i});

  printf("%d ", s.find_by_order((k + 1) / 2 - 1)->fst);
  for (int i = k; i < n; i++) {
    s.erase({a[i - k], i - k});
    s.insert({a[i], i});
    printf("%d ", s.find_by_order((k + 1) / 2 - 1)->fst);
  }
  puts("");
  return 0;
}
