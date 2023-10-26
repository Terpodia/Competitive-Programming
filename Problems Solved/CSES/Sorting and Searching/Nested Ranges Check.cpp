#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.fst != y.fst) return x.fst < y.fst;
  return x.snd > y.snd;
}

int main() {
  int n;
  scanf("%d", &n);
  pair<int, int> r[n];
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    r[i] = make_pair(x, y);
    mp[r[i]] = i;
  }
  sort(r, r + n, cmp);
  bool ans[2][n];
  memset(ans, false, sizeof(ans));
  int max_y = r[0].snd, min_y = r[n - 1].snd;
  for (int i = n - 2; i >= 0; i--) {
    if (min_y <= r[i].snd) ans[0][mp[r[i]]] = true;
    min_y = min(min_y, r[i].snd);
  }
  for (int i = 1; i < n; i++) {
    if (max_y >= r[i].snd) ans[1][mp[r[i]]] = true;
    max_y = max(max_y, r[i].snd);
  }

  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) printf("%c ", ans[k][i] ? '1' : '0');
    puts("");
  }
  return 0;
}
