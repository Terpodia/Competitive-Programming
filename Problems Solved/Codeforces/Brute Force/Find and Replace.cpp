#include <cstdio>

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf(" %s", s);
    char mp[26];
    for (int i = 0; i < 26; i++) mp[i] = '-';

    for (int i = 0; i < n; i++) {
      if (mp[s[i] - 'a'] == '-') mp[s[i] - 'a'] = (i % 2 == 0) ? '1' : '0';
    }

    bool can = true;
    for (int i = 0; i < n - 1; i++)
      can &= (mp[s[i] - 'a'] != mp[s[i + 1] - 'a']);

    (can) ? puts("YES") : puts("NO");
  }
  return 0;
}
