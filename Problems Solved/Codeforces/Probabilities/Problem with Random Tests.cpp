#include <bits/stdc++.h>
using namespace std;

int n;
string s;

string OR(int p) {
  string s1 = s;
  string s2;
  for (int i = 0; i <= p; i++) s2.push_back(s[i]);
  string ret = s1;

  int i = (int)s1.size() - 1, j = (int)s2.size() - 1;
  while (i >= 0 && j >= 0) {
    if (s2[j] == '1') ret[i] = '1';
    i--, j--;
  }
  return ret;
}

void print(string t) {
  bool check = false;
  for (char c : t) {
    if (!check && c == '0') continue;
    if (c == '1') check = true;
    cout << c;
  }
  cout << "\n";
}

void solve() {
  bool allZero = true;
  for (char c : s) allZero &= c == '0';
  if (allZero) {
    cout << "0\n";
    return;
  }
  int l = -1, r = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && l != -1) break;
    if (s[i] == '1' && l == -1)
      l = r = i;
    else if (s[i] == '1')
      r = i;
  }
  if (r == n - 1) {
    print(s);
    return;
  }
  string best = OR(l + (n - 1) - (r + 1));
  for (int i = l + 1; i <= r; i++) {
    string t = OR(i + (n - 1) - (r + 1));
    if (best < t) best = t;
  }
  print(best);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  solve();
  return 0;
}
