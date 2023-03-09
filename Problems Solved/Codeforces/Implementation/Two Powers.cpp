#include <bits/stdc++.h>
using namespace std;

int f(string& s) {
  int ret = -1;
  for (int i = 0; i < (int)s.size() - 1; i++) {
    if (s[i] == s[i + 1]) {
      ret = i;
      break;
    }
  }
  return (ret + 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    if (f(s) == 0 && f(t) == 0)
      cout << "YES\n";
    else {
      if (f(t) != 0) swap(s, t);
      int j = (int)s.size() - f(s);
      while (j > 0) {
        t.push_back(s.back());
        s.pop_back();
        j--;
      }
      if (f(s) == 0 && f(t) == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
