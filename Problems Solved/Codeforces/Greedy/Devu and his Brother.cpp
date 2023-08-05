#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

typedef long long ll;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(all(a));
  sort(all(b));

  map<ll, ll> mp1, mp2;
  for (int i = 0; i < n; i++) mp1[a[i]]++;
  for (int i = 0; i < m; i++) mp2[b[i]]++;

  set<ll> s;
  for (int i = 0; i < n; i++) s.insert(a[i]);
  a.clear();
  for (auto x : s) a.push_back(x);
  s.clear();
  for (int i = 0; i < m; i++) s.insert(b[i]);
  b.clear();
  for (auto x : s) b.push_back(x);

  int i = 0, j = sz(b) - 1;
  ll ans = 0;

  while (true) {
    if (mp1[a[i]] < mp2[b[j]]) {
      if (i == sz(a) - 1) {
        ans += max((ll)0, mp1[a[i]] * (b[j] - a[i]));
        break;
      }
      ans += mp1[a[i]] * (a[i + 1] - a[i]);
      mp1[a[i + 1]] += mp1[a[i]], mp1[a[i]] = 0;
      i++;
    } else {
      if (j == 0 || b[j - 1] <= a[i]) {
        ans += max((ll)0, mp2[b[j]] * (b[j] - a[i]));
        break;
      }
      ans += mp2[b[j]] * (b[j] - b[j - 1]);
      mp2[b[j - 1]] += mp2[b[j]], mp2[b[j]] = 0;
      j--;
    }
  }
  cout << ans << "\n";
  return 0;
}
