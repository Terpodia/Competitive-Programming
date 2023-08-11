
#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define mp make_pair
#define sz(x) (int)x.size()
#define dbg(x) cerr << #x << "=" << x << " "
#define line cerr << "\n==============================================\n"
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXM = 3e5 + 7;
const ll INF = 1e18;

int m;
ll n, k, b[MAXM], l, r;
vector<ii> pref;

void solve() {
  ll acc = 0, p[m + 1];
  p[0] = 0;
  for (int i = 1; i <= m; i++) p[i] = p[i - 1] + b[i - 1];
  pref.push_back(mp(0, -1));
  for (int i = 0; i < m; i++) {
    acc += b[i];
    pref.push_back(mp(acc, i));
  }
  sort(pref.begin(), pref.end());
  acc = 0;
  for (int i = 0; i < m; i++) {
    acc += b[i];
    auto it = lower_bound(pref.begin(), pref.end(), mp(acc - k, (ll)i));
    if (it == pref.begin()) continue;
    it--;
    if (it->snd >= i || acc - it->fst != k) continue;

    if (r - l >= i - it->snd - 1 &&
        (r - l != i - it->snd - 1 || it->snd + 1 < l))
      l = it->snd + 1, r = i;
  }

  ll curr = 0;
  for (int i = m - 1; i >= 0; i--) {
    curr += b[i];
    auto it = lower_bound(pref.begin(), pref.end(), mp(k - curr, (ll)-1));
    if (it == pref.end() || it->snd + m >= n || curr + it->fst != k) continue;

    if (r - l >= it->snd + m - i && (r - l != it->snd + m - i || i < l))
      l = i, r = it->snd + m;
  }

  if (acc == 0) return;

  if (acc < 0) {
    for (int i = 0; i <= m; i++) p[i] *= -1;
    pref.clear();
    for (int i = 0; i <= m; i++) pref.push_back(mp(p[i], i - 1));
    sort(pref.begin(), pref.end());
    for (int i = 0; i < m; i++) b[i] *= -1;
    k *= -1;
    acc *= -1;
  }

  map<ll, vector<ll>> mprefs;
  for (int i = 0; i <= m; i++) {
    mprefs[(p[i] % acc + acc) % acc].push_back(p[i]);
  }
  for (auto it = mprefs.begin(); it != mprefs.end(); it++)
    sort(it->snd.begin(), it->snd.end());

  curr = 0;
  for (int i = m - 1; i >= 0; i--) {
    curr += b[i];
    ll v = ((k - curr) % acc + acc) % acc;
    auto it = mprefs.find(v);

    if (it == mprefs.end()) continue;

    auto it2 = upper_bound(it->snd.begin(), it->snd.end(), k - curr);
    if (it2 == it->snd.begin()) continue;
    it2--;

    auto it3 = lower_bound(pref.begin(), pref.end(), mp(*it2, (ll)-1));
    if (it3 == pref.end()) continue;

    ll c = (k - it3->fst - curr) / acc;
    ll rx = it3->snd + (c + 1LL) * (ll)m;

    if (rx >= n || curr + c * acc + it3->fst != k) continue;
    if (r - l >= rx - i && (r - l != rx - i || i < l)) l = i, r = rx;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    l = -1, r = INF;
    pref.clear();
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++) cin >> b[i];
    solve();
    if (l == -1)
      cout << "-1\n";
    else
      cout << l << " " << r << "\n";
  }
  return 0;
}
