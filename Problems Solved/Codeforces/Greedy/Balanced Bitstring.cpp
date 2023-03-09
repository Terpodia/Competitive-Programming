#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

int n, k;
char s[MAXN];

void solve() {
  int v[k];
  memset(v, -1, sizeof(v));

  bool can = true;

  for (int i = 0; i < k; i++) {
    int c = -1;
    for (int j = i; j < n; j += k) {
      if (s[j] == '?') continue;
      if (c == -1)
        c = s[j] - '0';
      else
        can &= c == (int)(s[j] - '0');
    }
    v[i] = c;
  }
  if (!can) {
    puts("NO");
    return;
  }

  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < k; i++)
    if (v[i] != -1) {
      (v[i] == 0) ? cnt0++ : cnt1++;
    }
  if (cnt1 < cnt0) swap(cnt1, cnt0);

  int t = k - cnt1 - cnt0;

  if (t < cnt1 - cnt0) can = false;

  t -= min(t, cnt1 - cnt0);

  can &= t % 2 == 0;

  if (!can) {
    puts("NO");
    return;
  }
  puts("YES");
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    solve();
  }
  return 0;
}
