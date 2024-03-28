#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MOD = 1e9 + 7;

int k, L, n;
vvi a;
vi p;

void solve() {
  vvi dp(n + 1, vi(k, 0));
  vi pref(k + 1, 0);
  fore(i, 0, k) dp[n][i] = 1;
  fore(i, 1, k + 1) pref[i] = (pref[i - 1] + dp[n][i - 1]) % MOD;

  for (int i = n - 1; i >= 0; i--) {
    fore(j, 0, k) {
      if (i == 0)
        dp[i][j] = pref[k];
      else {
        /*
        fore(w,0,k){
          if(a[j][w]-L <= p[i-1] && a[j][w]+L >= p[i-1])
            dp[i][j] += dp[i+1][w], dp[i][j] %= MOD;
        }
        */
        int l =
            (int)distance(a[j].begin(), lower_bound(all(a[j]), p[i - 1] - L));
        if (l == k || a[j][l] - L > p[i - 1]) continue;
        int r =
            (int)distance(a[j].begin(), upper_bound(all(a[j]), p[i - 1] + L)) -
            1;
        dp[i][j] = (((pref[r + 1] - pref[l]) % MOD) + MOD) % MOD;
      }
    }
    fore(j, 1, k + 1) pref[j] = (pref[j - 1] + dp[i][j - 1]) % MOD;
  }
  cout << dp[0][0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> L;
  a = vvi(k, vi(k));
  fore(i, 0, k) fore(j, 0, k) cin >> a[i][j];
  cin >> n;
  p = vi(n - 1);
  fore(i, 0, n - 1) cin >> p[i];
  solve();
  return 0;
}
