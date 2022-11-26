#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1e5;
int n, q, k;
ll a[MAXN], s[MAXN];

void fastIO() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
}

void setupS(ll s[]) {
  s[0] = a[0] - 1;
  s[0] += a[1] - a[0] - 1;
  s[n - 1] = k - a[n - 1];
  s[n - 1] += a[n - 1] - a[n - 2] - 1;
  for (int i = 1; i < n - 1; i++) {
    s[i] = a[i + 1] - a[i] - 1;
    s[i] += a[i] - a[i - 1] - 1;
    s[i] += s[i - 1];
  }
  s[n - 1] += s[n - 2];
}

int solve(int l, int r) {
  if (r - l == 0) return k - 1;

  ll ans = 0;

  ll left = a[l + 1] - 2, right = k - a[r - 1] - 1;
  ans = left + right;
  l++;
  r--;
  if (r >= l) {
    ans += s[r] - s[l - 1];
  }
  return ans;
}

int main() {
  fastIO();
  cin >> n >> q >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  setupS(s);

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << solve(l - 1, r - 1) << "\n";
  }

  return 0;
}
