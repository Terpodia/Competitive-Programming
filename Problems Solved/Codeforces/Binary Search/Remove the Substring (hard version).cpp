#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

vector<int> suff;
string s, t;

bool can(int k) {
  int curr = -1;
  for (int i = 0, j = 0; i < sz(s) && j < sz(t); i++) {
    if (curr + k + 1 > sz(s)) break;
    if (suff[curr + k + 1] == sz(t) - j) return true;

    if (s[i] == t[j]) j++, curr = i;

    if (curr + k + 1 > sz(s)) break;
    if (suff[curr + k + 1] == sz(t) - j) return true;
  }
  return false;
}

void solve() {
  int l = 0, r = (int)1e6;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (can(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s >> t;
  suff = vector<int>(sz(s) + 1, 0);
  for (int i = sz(s) - 1; i >= 0; i--) {
    if (suff[i + 1] == sz(t))
      suff[i] = suff[i + 1];
    else if (s[i] == t[sz(t) - suff[i + 1] - 1])
      suff[i] = suff[i + 1] + 1;
    else
      suff[i] = suff[i + 1];
  }
  solve();
  return 0;
}
