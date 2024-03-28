#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int f(deque<char>& a) {
  for (int i = 1; i < (int)a.size(); i++) {
    if (a[i] == a[0]) return i;
  }
  return INF;
}

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    deque<char> a;
    for (int i = 0; i < n; i++) a.push_back(s[i]);
    int cnt = 0;
    while ((int)a.size() > 1) {
      int idx = INF;
      if (a[0] == a[1])
        idx = 1;
      else if (a[0] == '(' && a[1] == ')')
        idx = 1;
      else
        idx = f(a);

      if (idx == INF) break;
      for (int i = 0; i <= idx; i++) a.pop_front();
      cnt++;
    }
    printf("%d %d\n", cnt, (int)a.size());
  }
  return 0;
}
