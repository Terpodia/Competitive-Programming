#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define all(x) x.begin(), x.end()

typedef pair<int, int> ii;

bool cmp(ii a, ii b) {
  if (a.snd != b.snd) return a.snd < b.snd;
  return a.fst > b.fst;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].fst, &a[i].snd);
  sort(a, a + n, cmp);

  multiset<int> r;
  for (int i = 0; i < k; i++) r.insert(-1);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto it = r.upper_bound(a[i].fst);
    if (it == r.begin()) continue;
    r.erase(--it);
    r.insert(a[i].snd);
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
