#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i, x, n) for (int i = (x); i < (int)n; i++)

int n;

int f(vector<int> a, int flag) {
  int ret = 0, cnt = 0;
  vector<int> odds, evens;

  forn(i, 0, n) if (a[i] % 2 == 1) odds.push_back(i);

  forn(i, 0, n) if (a[i] % 2 == 0) evens.push_back(i);

  int i = 0, j = 0;

  while (cnt < n) {
    if (cnt % 2 == flag)
      ret += max(0, evens[i++] - cnt);
    else
      ret += max(0, odds[j++] - cnt);
    cnt++;
  }

  return ret;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    vector<int> a(n);
    forn(i, 0, n) scanf("%d", &a[i]);

    int cnt1, cnt2;
    cnt1 = cnt2 = 0;

    forn(i, 0, n)(a[i] % 2 == 0) ? cnt1++ : cnt2++;

    if (n % 2 == 0 && cnt1 != cnt2)
      puts("-1");
    else if (n % 2 == 1 && abs(cnt1 - cnt2) > 1)
      puts("-1");
    else {
      if (n % 2 == 0)
        printf("%d\n", min(f(a, 0), f(a, 1)));
      else if (cnt1 > cnt2)
        printf("%d\n", f(a, 0));
      else
        printf("%d\n", f(a, 1));
    }
  }

  return 0;
}
