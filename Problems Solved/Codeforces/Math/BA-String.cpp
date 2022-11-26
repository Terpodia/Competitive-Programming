#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;

#define sz(x) (int)x.size()

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int n;
ll k, x;
string s;

bool check(ll a, ll b) { return ((ld)a * (ld)b > 1e18); }

void solve() {
  vector<ll> cnt;
  ll acc = 0;

  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '*')
      acc++;
    else {
      if (acc > 0) cnt.push_back(acc * k + 1);
      acc = 0;
    }
  }
  if (acc > 0) cnt.push_back(acc * k + 1);
  cnt.push_back(1);

  acc = 1;
  int j = 0;

  for (int i = 1; i < sz(cnt) - 1; i++) {
    while (check(acc, cnt[i])) {
      acc /= cnt[j + 1];
      j++;
    }
    acc *= cnt[i];
  }

  int i = 0, z = 0;
  string ans;

  while (i < n) {
    if (s[i] != '*') {
      ans.push_back(s[i]);
      i++;
      continue;
    }
    if (z < j) {
      while (i < n && s[i] == '*') i++;
      z++;
      continue;
    }

    ll y;

    if (acc >= x)
      y = 0;
    else
      y = (x - 1) / acc;

    for (int _ = 0; _ < (int)y; _++) ans.push_back('b');

    x -= y * acc;
    z++;
    acc /= cnt[z];
    while (i < n && s[i] == '*') i++;
  }

  cout << ans << "\n";
}

int main() {
  fastIO();
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> k >> x;
    cin >> s;

    solve();
  }

  return 0;
}
