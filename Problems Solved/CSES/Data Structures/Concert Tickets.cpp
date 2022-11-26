#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  ll t[n];
  multiset<ll> h;

  for (int i = 0; i < n; i++) {
    ll hi;
    cin >> hi;
    h.insert(hi);
  }

  for (int i = 0; i < m; i++) cin >> t[i];

  for (int i = 0; i < m; i++) {
    auto itr = h.lower_bound(t[i]);
    if (itr != h.end() && *itr == t[i]) {
      cout << *itr << "\n";
      h.erase(itr);
    }

    else if (itr == h.begin())
      cout << -1 << "\n";
    else {
      itr--;
      cout << *itr << "\n";
      h.erase(itr);
    }
  }

  return 0;
}
