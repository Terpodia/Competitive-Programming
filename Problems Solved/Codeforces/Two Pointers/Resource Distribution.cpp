#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x1, x2;
  cin >> n >> x1 >> x2;
  bool s = false;
  if (x1 < x2) {
    swap(x1, x2);
    s = true;
  }
  vector<pair<int, int>> a(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
    c[i] = a[i].first;
  }
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  vector<pair<int, int>> d;

  int l = -1, r = -1;

  for (int i = n - 1; i >= 0; i--) {
    int k = (x1 + n - i - 1) / (n - i);
    if (c[i] >= k) {
      l = i, r = n - 1;
      break;
    }
  }
  if (l <= 0) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < l; i++) {
    d.push_back({i, c[i]});
  }

  // for(int i=0; i<(int)d.size(); i++) cout<<d[i].second<<"\n";

  for (int i = (int)d.size() - 1; i >= 0; i--) {
    int k = (x2 + (int)d.size() - i - 1) / ((int)d.size() - i);
    if (d[i].second >= k) {
      cout << "Yes\n";
      if (s) {
        cout << (int)d.size() - i << " " << r - l + 1 << "\n";
        for (int j = i; j < (int)d.size(); j++)
          cout << a[d[j].first].second << " ";
        cout << "\n";
        for (int j = l; j <= r; j++) cout << a[j].second << " ";
        cout << "\n";
        return 0;
      }
      cout << r - l + 1 << " " << (int)d.size() - i << "\n";
      for (int j = l; j <= r; j++) cout << a[j].second << " ";
      cout << "\n";
      for (int j = i; j < (int)d.size(); j++)
        cout << a[d[j].first].second << " ";
      cout << "\n";
      return 0;
    }
  }
  int ls = (int)d.size() - 1, cnt = 1;
  while (l > 0 && ls >= 0) {
    l--, r--;
    d[ls] = {r + 1, c[r + 1]};
    int aux = ls - 1;

    while (l >= 0 && c[l] < (x1 + r - l) / (r - l + 1)) {
      if (aux >= 0) d[aux] = {-1, -1};
      aux--, l--;
    }
    if (l < 0) break;

    if (d[ls].second >= (x2 + cnt - 1) / cnt) {
      cout << "Yes\n";
      if (s) {
        cout << cnt << " " << r - l + 1 << "\n";
        int k = (int)d.size() - 1;
        while (cnt > 0 && k >= 0) {
          if (d[k].first != -1) cout << a[d[k].first].second << " ", cnt--;
          k--;
        }
        cout << "\n";
        for (int j = l; j <= r; j++) cout << a[j].second << " ";
        cout << "\n";
        return 0;
      }
      cout << r - l + 1 << " " << cnt << "\n";
      for (int j = l; j <= r; j++) cout << a[j].second << " ";
      cout << "\n";
      int k = (int)d.size() - 1;
      while (cnt > 0 && k >= 0) {
        if (d[k].first != -1) cout << a[d[k].first].second << " ", cnt--;
        k--;
      }
      cout << "\n";
      return 0;
    }
    ls = aux;
    cnt++;
  }
  cout << "No\n";
  return 0;
}
