#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
typedef long long ll;
vector<pair<int, char>> a;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

bool compare(pair<int, char> b, pair<int, char> c) { return b.first > c.first; }

void solve() {
  ll ans = 0;
  sort(a.begin(), a.end(), compare);
  int cntH = 1, cntV = 1;
  for (int i = 0; i < (int)a.size(); i++) {
    ll b = a[i].first;
    if (a[i].second == 'v') {
      cntV++;
      ans += b * cntH;
    } else {
      cntH++;
      ans += b * cntV;
    }
  }
  cout << ans << "\n";
}

int main() {
  fastIO();

  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    for (int i = 0; i < m - 1; i++) {
      int b;
      cin >> b;
      a.push_back({b, 'v'});
    }
    for (int i = 0; i < n - 1; i++) {
      int b;
      cin >> b;
      a.push_back({b, 'h'});
    }
    solve();
    a.clear();
  }

  return 0;
}
