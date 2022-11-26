//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int MAXN = 1e6;
const ll MOD = 1000000007;

int n, m, y[MAXN];
string s, p;
ll b;

void calc() {
  int i = 0, j = 0;
  while (j < m) {
    i = y[j++] - 1;
    int cnt = 0;
    while (cnt < sz(p)) {
      if (j < m && y[j] - 1 == i) break;
      s[i++] = p[cnt++];
    }
  }
}

ll V(char c) {
  if (c == '?')
    return 28;
  else
    return c - 'a' + 1;
}

bool can() {
  ll B[MAXN + 7];
  B[0] = 1;
  for (int i = 1; i < MAXN + 7; i++) B[i] = (b * B[i - 1]) % MOD;

  ll hash_P = 0;
  rep(i, 0, sz(p)) {
    hash_P += (V(p[i]) * B[sz(p) - i - 1]) % MOD;
    hash_P %= MOD;
  }

  ll hash_S[n + 1];
  hash_S[0] = 0;
  rep(i, 1, n + 1) {
    hash_S[i] = ((hash_S[i - 1] * b) % MOD) + V(s[i - 1]);
    hash_S[i] %= MOD;
  }

  rep(i, 0, m) {
    int l = y[i], r = y[i] + sz(p) - 1;
    ll h = hash_S[r] - ((hash_S[l - 1] * B[r - l + 1])) % MOD;
    h += MOD;
    h %= MOD;
    if (hash_P != h) return false;
  }

  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  cin >> p;
  rep(i, 0, m) cin >> y[i];

  rep(i, 0, n) s.pb('?');
  calc();

  vector<ll> B;
  B.pb(33);
  B.pb(37);
  B.pb(41);
  shuffle(all(B), rng);
  b = B[0];

  if (can()) {
    ll ans = 1;
    rep(i, 0, n) if (s[i] == '?') {
      ans *= 26;
      ans %= MOD;
    }
    cout << ans << "\n";
  } else
    cout << "0\n";

  return 0;
}
