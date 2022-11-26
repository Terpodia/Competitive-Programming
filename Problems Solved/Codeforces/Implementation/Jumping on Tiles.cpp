#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int idx(char c) { return c - 'a' + 1; }

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int)s.size();

    int l = min(idx(s[0]), idx(s[n - 1])), r = max(idx(s[0]), idx(s[n - 1]));
    vector<pair<int, int>> a;

    for (int i = 1; i < n - 1; i++) {
      if (idx(s[i]) >= l && idx(s[i]) <= r) a.push_back({idx(s[i]), i});
    }

    if (l == idx(s[0]))
      sort(a.begin(), a.end());
    else
      sort(a.begin(), a.end(), cmp);

    cout << r - l << " " << (int)a.size() + 2 << "\n";
    cout << 1 << " ";
    for (int i = 0; i < (int)a.size(); i++) cout << a[i].second + 1 << " ";
    cout << n << "\n";
  }
  return 0;
}
