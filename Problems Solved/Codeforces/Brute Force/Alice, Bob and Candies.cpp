#include <cstdio>

const int MAXN = 1007;

int n, a[MAXN];

void solve() {
  int l = 0, r = n - 1, flag = 0, k = 0, alice = 0, bob = 0, prev_move = 0,
      curr_move = 0;

  while (r >= l) {
    curr_move = 0;
    int i;

    if (flag == 0) {
      for (i = l; i <= r; i++) {
        if (curr_move > prev_move) break;
        curr_move += a[i];
      }
    }

    else {
      for (i = r; i >= l; i--) {
        if (curr_move > prev_move) break;
        curr_move += a[i];
      }
    }

    prev_move = curr_move;
    (flag == 0) ? alice += curr_move : bob += curr_move;
    (flag == 0) ? l = i : r = i;
    flag = 1 - flag;
    k++;
  }

  printf("%d %d %d\n", k, alice, bob);
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    solve();
  }
  return 0;
}

