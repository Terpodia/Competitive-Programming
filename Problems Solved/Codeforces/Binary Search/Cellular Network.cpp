#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

int main() {
  fastIO();
  int n, m;
  cin >> n >> m;
  vi a(n), b(m);

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  ll r = -1e9;
  for (int i = 0; i < n; i++) {
    auto itr = lower_bound(b.begin(), b.end(), a[i]);
    auto itr2 = b.end();

    if (itr != b.begin()) itr2 = itr - 1;

    if (itr2 != b.end() && itr != b.end())
      r = max(r, min(abs(a[i] - *itr), abs(a[i] - *itr2)));

    else if (itr2 != b.end())
      r = max(r, abs(a[i] - *itr2));

    else
      r = max(r, abs(a[i] - *itr));
  }

  cout << r << "\n";

  return 0;
}
