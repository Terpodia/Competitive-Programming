#include <iostream>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define f first
#define s second

const int MAXN = 2e5;

string s;
int pref[MAXN + 1];
int n;

ll calc(int m, int k) {
  ii y = {k - 1 - m, k - 1};
  ii x = {0, y.f - 1};
  ll ret = 0;
  int sum = 0;
  for (int i = y.f; i <= y.s; i++) sum += (s[i] == '0') ? 0 : (1 << (y.s - i));
  if (s[y.f] == '1' && x.f - (sum - k) > -1 &&
      pref[x.s + 1] - pref[x.f - (sum - k)] == 0)
    ret++;

  for (int i = k; i < n; i++) {
    sum -= (s[y.f] == '1') ? k : 0;
    sum *= 2;
    sum += (s[i] == '1') ? 1 : 0;
    y.f++, y.s++, x.f++, x.s++;

    if (s[y.f] == '1' && x.f - (sum - k) > -1 &&
        pref[x.s + 1] - pref[x.f - (sum - k)] == 0)
      ret++;
  }
  return ret;
}

void solve() {
  pref[0] = 0;
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i - 1] - '0');
  ll ans = 0;
  for (int sz = 0; (1 << sz) <= n; sz++) {
    ans += calc(sz, 1 << sz);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> s;
    n = (int)s.size();
    solve();
  }
  return 0;
}
