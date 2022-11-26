#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int aux;

const int MAXN = 2e5;

typedef long long ll;

int N, M;
pair<int, int> p[MAXN];

ll a[MAXN];

int main() {
  int aux;
  aux = scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) aux = scanf("%d%d", &p[i].first, &p[i].second);

  ll cnt[2 * M + 1][2];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < N; i++) {
    cnt[p[i].first][0]++;
    cnt[p[i].second][1]++;
  }

  for (int i = 0; i <= 2 * M; i++) {
    for (int j = 0; i - j > -1; j++) {
      a[i] += cnt[i - j][0] * cnt[j][0];
      a[i + 1] -= cnt[i - j][1] * cnt[j][1];
    }
  }

  ll sum = 0;
  for (int i = 0; i <= M * 2; i++) {
    sum += a[i];
    printf("%lld\n", sum);
  }

  return 0;
}
