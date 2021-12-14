#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int aux;

#define sz(x) (int)x.size()

const int MAXN = 2e5;
const int INF = 1e9;

int n; pair<int,char> a[MAXN];
string c;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

void solve() {
  vector<int> b, f;

  for (int i=0; i<n; i++) {
    if (a[i].first < 1) {
      if (a[i].second == 'B') { cout << "NO\n"; return; }
      b.push_back(INF);
    }
    else if (a[i].first >= 1 && a[i].first <= n) {
      if (a[i].second == 'B') b.push_back(a[i].first);
      else f.push_back(a[i].first);
    }

    else {
      if (a[i].second == 'R') { cout << "NO\n"; return; }
      else f.push_back(-INF);
    }
  }

  sort(b.begin(), b.end());
  sort(f.begin(), f.end(), greater<int>());

  int l=1, r=n;

  for (int i=0; i<sz(b); i++) {
    if (b[i] < l) { cout << "NO\n"; return; }
    l++;
  }

  for (int i=0; i<sz(f); i++) {
    if (f[i] > r) { cout << "NO\n"; return; }
    r--;
  }

  cout << "YES\n";
}

int main() {
  fastIO();
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0; i<n; i++)
      cin >> a[i].first;

    for (int i=0; i<n; i++)
      cin >> a[i].second;
    
    solve();
  }

  return 0;
}

