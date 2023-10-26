#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define SZ(x) (int)x.size()

bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.fst != y.fst) return x.fst < y.fst;
  return x.snd > y.snd;
}

const int INF = 1e9 + 99;

int main() {
  int n;
  scanf("%d", &n);
  pair<int, int> p[n];
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].fst, &p[i].snd);
    mp[p[i]] = i;
  }
  sort(p, p + n, cmp);
  ordered_set<pair<int, int>> s1, s2;
  s1.insert({p[0].snd, 0}), s2.insert({p[n - 1].snd, n - 1});
  int ans[2][n];
  memset(ans, 0, sizeof(ans));

  for (int i = 1; i < n; i++) {
    int k = s1.order_of_key({p[i].snd, -1});
    ans[1][mp[p[i]]] += SZ(s1) - k;
    s1.insert({p[i].snd, i});
  }
  for (int i = n - 2; i >= 0; i--) {
    int k = s2.order_of_key({p[i].snd, INF});
    ans[0][mp[p[i]]] += k;
    // printf("%d %d\n........\n",p[i].snd,k);
    s2.insert({p[i].snd, i});
  }

  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) printf("%d ", ans[k][i]);
    puts("");
  }
  return 0;
}
