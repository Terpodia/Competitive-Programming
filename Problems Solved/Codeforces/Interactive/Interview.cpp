#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

typedef long long ll;

ll query(int k, vector<int>& p) {
  cout << "? " << k << " ";
  for (int i = 0; i < sz(p); i++) cout << p[i] << " ";
  cout << endl;
  ll ret;
  cin >> ret;
  return ret;
}

int n;
vector<ll> a;

bool can(int l, int r) {
  ll s = 0, w;
  vector<int> index;
  for (int i = l; i <= r; i++) index.push_back(i + 1), s += a[i];
  w = query(sz(index), index);
  return s < w;
}

void solve() {
  int l = 0, r = n;
  while (r > l) {
    int mid = l + (r - l) / 2;
    if (can(l, mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << "! " << r + 1 << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    a = vector<ll>(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    solve();
  }
  return 0;
}
