#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 7;

int n;
ll v[MAXN], t[MAXN], pref[MAXN];

void solve() {
  ll cnt = 0;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  for (int i = 0; i < n; i++) {
    ll res = 0;
    cnt++;
    q.push(v[i] + pref[i]);
    while (!q.empty()) {
      ll b = q.top();
      if (b - pref[i + 1] < 0) {
        q.pop();
        res += b - pref[i];
        cnt--;
      } else
        break;
    }
    ll ans = cnt * t[i] + res;
    cout << ans << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + t[i - 1];
  solve();
  return 0;
}
