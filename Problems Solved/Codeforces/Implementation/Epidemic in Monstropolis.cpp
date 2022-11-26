#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 500;

int n, k, a[MAXN], b[MAXN];
vector<pair<int, char>> ans;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

bool check(int l, int r, int j) {
  int hi = 0, s = 0;

  for (int i = l; i <= r; i++) hi = max(hi, a[i]);
  for (int i = l; i <= r; i++) s += a[i];

  if (s != b[j]) return false;

  if (l == r) return true;

  int pos = -1;
  for (int i = l; i <= r; i++) {
    if (a[i] == hi) {
      if (i == l) {
        if (a[i + 1] < a[i]) pos = i;
      } else if (i == r) {
        if (a[i - 1] < a[i]) pos = i;
      } else {
        if (a[i - 1] < a[i] || a[i + 1] < a[i]) pos = i;
      }
    }
  }

  if (pos == -1) return false;

  if (pos == l) {
    for (int i = 0; i < r - l; i++) ans.push_back(make_pair(j + 1, 'R'));
  }

  else if (pos == r) {
    for (int i = r; i > l; i--) ans.push_back(make_pair(j + (i - l) + 1, 'L'));
  }

  else {
    if (a[pos - 1] < a[pos]) {
      ans.push_back(make_pair(j + (pos - l) + 1, 'L'));
      pos--, r--;
    }

    else {
      ans.push_back(make_pair(j + (pos - l) + 1, 'R'));
      r--;
    }

    for (int i = 0; i < r - pos; i++)
      ans.push_back(make_pair(j + (pos - l) + 1, 'R'));

    for (int i = pos; i > l; i--)
      ans.push_back(make_pair(j + (i - l) + 1, 'L'));
  }

  return true;
}

int main() {
  fastIO();

  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> k;
  for (int i = 0; i < k; i++) cin >> b[i];

  int l = 0, curr = 0, cnt = 0;

  for (int i = 0; i < n; i++) {
    if (cnt == k) {
      cnt = -1;
      break;
    }
    if (check(l, i, curr)) curr++, cnt++, l = i + 1;
  }

  if (cnt != k)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (auto& [i, c] : ans) cout << i << " " << c << "\n";
  }

  return 0;
}
