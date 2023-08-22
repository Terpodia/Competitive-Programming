#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

typedef long long ll;

const ll INF = 1e18;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> pos;
    for (int i = 0; i < n; i++)
      if (s[i] == '*') pos.push_back(i);
    vector<ll> pref(sz(pos) + 1, 0);
    for (int i = 1; i <= sz(pos); i++) pref[i] = pref[i - 1] + pos[i - 1];

    ll ans = INF;

    for (int i = 0; i < n; i++) {
      if (s[i] != '*') {
        auto it = lower_bound(pos.begin(), pos.end(), i);
        int j = (int)distance(pos.begin(), it);
        int k = j - 1;

        ll res1 = 0, res2 = 0;

        if (j < sz(pos)) {
          ll cnt_der = sz(pos) - j;
          res1 += pref[sz(pos)] - pref[j] - (ll)i * cnt_der -
                  ((cnt_der + 1) * cnt_der) / 2LL;
          res2 += pref[sz(pos)] - pref[j] - (ll)i * cnt_der -
                  ((cnt_der - 1) * cnt_der) / 2LL;
        }
        if (k >= 0) {
          ll cnt_izq = k + 1;
          res1 +=
              (ll)i * cnt_izq - pref[k + 1] - ((cnt_izq - 1) * cnt_izq) / 2LL;
          res2 +=
              (ll)i * cnt_izq - pref[k + 1] - ((cnt_izq + 1) * cnt_izq) / 2LL;
        }
        ans = min(ans, res1);
        ans = min(ans, res2);
        continue;
      }
      auto it = lower_bound(pos.begin(), pos.end(), i);
      int j = (int)distance(pos.begin(), it);
      int k = j - 1;
      j++;
      ll res = 0, cnt_der = sz(pos) - j, cnt_izq = k + 1;
      if (j < sz(pos))
        res += pref[sz(pos)] - pref[j] - (ll)i * cnt_der -
               ((cnt_der + 1) * cnt_der) / 2LL;
      if (k >= 0)
        res += (ll)i * cnt_izq - pref[k + 1] - ((cnt_izq + 1) * cnt_izq) / 2LL;
      ans = min(ans, res);
    }
    cout << ans << "\n";
  }
  return 0;
}
