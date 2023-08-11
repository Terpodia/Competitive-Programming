#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int w, h, n;
  cin >> w >> h >> n;

  multiset<int> diff_row, diff_col;
  set<int> cut_row, cut_col;

  cut_row.insert(0);
  cut_row.insert(h);
  cut_col.insert(0);
  cut_col.insert(w);
  diff_row.insert(h);
  diff_col.insert(w);

  for (int i = 0; i < n; i++) {
    char t;
    int x;
    cin >> t >> x;
    if (t == 'H') {
      auto j = cut_row.lower_bound(x);
      int r = *j;
      j--;
      int l = *j;
      auto k = diff_row.find(r - l);
      diff_row.erase(k);
      diff_row.insert(x - l);
      diff_row.insert(r - x);
      cut_row.insert(x);
    } else {
      auto j = cut_col.lower_bound(x);
      int r = *j;
      if (j == cut_col.begin()) cout << x << "\n";
      j--;
      int l = *j;
      auto k = diff_col.find(r - l);
      diff_col.erase(k);
      diff_col.insert(x - l);
      diff_col.insert(r - x);
      cut_col.insert(x);
    }
    auto j = diff_row.end();
    j--;
    auto k = diff_col.end();
    k--;
    cout << (ll)*j * (ll)*k << "\n";
  }
  return 0;
}
