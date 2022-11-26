#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 7;

int N, s[MAXN], t[MAXN];
ll W, p[MAXN];

bool solve() {
  ll l[MAXN];
  memset(l, 0, sizeof(l));

  for (int i = 0; i < N; i++) {
    l[s[i]] += p[i];
    l[t[i]] -= p[i];
  }

  ll acc = 0;

  for (int i = 0; i < MAXN; i++) {
    acc += l[i];
    if (acc > W) return false;
  }

  return true;
}

int main() {
  scanf("%d%lld", &N, &W);
  for (int i = 0; i < N; i++) {
    scanf("%d%d%lld", s + i, t + i, p + i);
  }

  (solve()) ? puts("Yes") : puts("No");

  return 0;
}
