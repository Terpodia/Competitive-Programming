#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

struct segment {
  int l, r;
  bool operator<(const segment &seg) {
    if (seg.l != l) return l < seg.l;
    return r < seg.r;
  }
};

const int MAXG = 1e4;
int L, G;
segment s[MAXG];

int solve() {
  bool can = true;
  int ret = G;

  int pos = 0, i = 0;
  sort(s, s + G);

  while (pos < L) {
    int aux = pos;
    while (i < G && s[i].l <= pos) aux = max(aux, s[i++].r);

    if (pos == aux) {
      can = false;
      break;
    }
    pos = aux;
    ret--;
  }

  return (can) ? ret : -1;
}

int main() {
  do {
    scanf("%d%d", &L, &G);
    if (L == 0 && G == 0) break;
    for (int i = 0; i < G; i++) {
      int x, r;
      scanf("%d%d", &x, &r);
      s[i].l = max(x - r, 0);
      s[i].r = min(L, x + r);
    }

    printf("%d\n", solve());

  } while (L != 0 && G != 0);

  return 0;
}
