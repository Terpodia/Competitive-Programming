#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;

    vector<bool> ok(26, false);
    for (char c : s) ok[c - 'a'] = true;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
      if (ok[i]) cnt++;

    bool can = true;

    string u, v;
    for (int i = 0; i < cnt; i++) u.push_back(s[i]);

    for (int i = cnt; i < (int)s.size(); i++) {
      if (i % cnt == 0) {
        if (!v.empty()) can &= u == v;
        v.clear();
      }
      v.push_back(s[i]);
    }
    for (int i = 0; i < (int)v.size(); i++) {
      can &= u[i] == v[i];
    }

    if (can)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
