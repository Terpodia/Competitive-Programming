// https://cses.fi/165/list/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n.................................................\n";

typedef long long ll;

const int MAXN = 1e6 + 7;
const ll MOD = 1e9 + 7;

ll B = 37, pows[MAXN], val[26];

string s;

ll f(char c) { return val[c - 'a']; }

int solve() {
  int n = sz(s), l = 0, r = n - 1, ret = 0;
  while (r >= l) {
    if (l == r) {
      ret++;
      break;
    }
    ll h1 = f(s[l]), h2 = f(s[r]);
    int cnt = 1;
    // dbg(l); dbg(r); line;

    while (r - 1 > l + 1 && h1 != h2) {
      l++, r--, cnt++;
      h1 = (((h1 * B) % MOD) + f(s[l])) % MOD;
      h2 = (h2 + ((f(s[r]) * pows[cnt - 1]) % MOD)) % MOD;
    }
    if (h1 != h2) {
      ret++;
      break;
    } else
      ret += 2;
    l++, r--;
  }
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  srand(time(NULL));

  ll bases[] = {37, 39, 41};
  random_shuffle(bases, bases + 3);
  B = bases[0];
  pows[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    pows[i] = (pows[i - 1] * B) % MOD;
  }
  for (int i = 0; i < 26; i++) val[i] = i + 1;
  random_shuffle(val, val + 26);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    cout << solve() << "\n";
  }
  return 0;
}
