#include <iostream>
using namespace std;

#define sz(x) (int)x.size()

int aux;

int ndigits(int n) {
  int cnt = 0;
  while (n > 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int x1, p1, x2, p2;
    aux = scanf("%d%d%d%d", &x1, &p1, &x2, &p2);

    if (p1 + ndigits(x1) != p2 + ndigits(x2)) {
      (p1 + ndigits(x1) > p2 + ndigits(x2)) ? puts(">") : puts("<");
    }

    else {
      string s = to_string(x1);
      string w = to_string(x2);

      int x = 0, y = 0;

      int val = 0;

      while (x < sz(s) && y < sz(w)) {
        if (s[x] < w[y]) {
          val = 2;
          break;
        } else if (s[x] > w[y]) {
          val = 1;
          break;
        }
        x++, y++;
      }

      if (val == 1)
        puts(">");
      else if (val == 2)
        puts("<");
      else {
        for (int i = x; i < sz(s); i++)
          if (s[i] != '0') val = 1;
        for (int i = y; i < sz(w); i++)
          if (w[i] != '0') val = 2;

        if (val == 0)
          puts("=");
        else if (val == 1)
          puts(">");
        else
          puts("<");
      }
    }
  }

  return 0;
}
