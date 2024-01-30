#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

const ll MOD = 998244353, INF = 1e18;
const int MAXN = 3e5 + 1;

int n;
ll p[MAXN], dp[MAXN];

void mod(ll& x) { x %= MOD, x += MOD, x %= MOD; }

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    fore(i, 0, n) cin >> p[i];
    memset(dp, 0, sizeof(dp));

    stack<ll> st;
    vector<ll> pref(n + 1, 0);
    ll cur = 1;
    pref[1] = 1;
    st.push(0);

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      while (!st.empty() && p[st.top()] > p[i]) {
        cur -= dp[st.top()];
        mod(cur);
        st.pop();
      }
      dp[i] += cur;
      mod(dp[i]);

      if (st.empty())
        dp[i] += pref[i] + 1;
      else
        dp[i] += pref[i] - pref[st.top() + 1];
      mod(dp[i]);

      st.push(i);
      cur += dp[i];
      mod(cur);
      pref[i + 1] = pref[i] + dp[i];
      mod(pref[i + 1]);
    }

    ll ans = 0, lo = INF;
    for (int i = n - 1; i >= 0; i--) {
      if (p[i] < lo) ans += dp[i], ans %= MOD;
      lo = min(lo, p[i]);
    }
    cout << ans << "\n";
  }
  return 0;
}
