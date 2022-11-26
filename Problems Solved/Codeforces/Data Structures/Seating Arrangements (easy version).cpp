#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int aux;

const int MAXN = 300;

#define LSOne(x) (x) & (-x)

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}

int ft[MAXN + 7];

int psum(int j) {
  int ret = 0;
  for (int i = j; i > 0; i -= LSOne(i)) {
    ret += ft[i];
  }
  return ret;
}

void update(int j, int v) {
  for (int i = j; i <= MAXN; i += LSOne(i)) ft[i] += v;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n, m;
    aux = scanf("%d%d", &n, &m);
    pair<int, int> a[m];
    for (int i = 0; i < m; i++) {
      aux = scanf("%d", &a[i].first);
      a[i].second = i;
    }

    sort(a, a + m, cmp);
    int p[m];
    for (int i = 0; i < m; i++) p[a[i].second] = i + 1;

    memset(ft, 0, sizeof(ft));

    int ans = 0;

    for (int i = 0; i < m; i++) {
      ans += psum(p[i]);
      update(p[i], 1);
    }

    printf("%d\n", ans);
  }

  return 0;
}
