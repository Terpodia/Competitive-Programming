#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
string s;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool ok(int m, vector<int> cnt) {
  for (int i = 0; i < k; i++) {
    int w = m / 2;
    for (int& c : cnt) {
      if (w == 0) break;
      int r = min(c / 2, w);
      w -= r;
      c -= r * 2;
    }
    if (w > 0) return false;
  }

  if (m % 2 == 1) {
    int sum = 0;
    for (int i : cnt) sum += i;
    return sum >= k;
  }
  return true;
}

int solve(vector<int>& cnt) {
  int l = 1, r = n;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (ok(mid, cnt))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  fastIO();
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k >> s;
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    cout << solve(cnt) << "\n";
  }
  return 0;
}
