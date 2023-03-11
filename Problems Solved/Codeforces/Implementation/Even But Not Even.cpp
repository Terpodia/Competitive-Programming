#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += s[i] - '0';
    if (sum % 2 != 0) {
      for (int i = 0; i < n; i++)
        if ((s[i] - '0') % 2 != 0) {
          s[i] = '-';
          break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '-') continue;
      if ((s[i] - '0') % 2 != 0) break;
      s[i] = '-';
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '-') continue;
      if ((s[i] - '0') != 0) break;
      s[i] = '-';
    }
    vector<int> ans;
    for (char c : s) {
      if (c == '-') continue;
      ans.push_back(c - '0');
    }
    if (ans.empty())
      cout << "-1\n";
    else {
      for (int i : ans) cout << i;
      cout << "\n";
    }
  }
  return 0;
}
