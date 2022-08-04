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

const int MAXN = 3000;

const ll MOD = 1e9 + 7;
ll B, powers[MAXN];

vector<ll> vals(26);

string s, l, r;
vector<ll> hash_S, hash_L, hash_R;

ll V(char c) { return vals[c - 'a']; }

vector<ll> calc_hash(string& p) {
  vector<ll> h(sz(p) + 1);
  h[0] = 0;
  rep(i, 1, sz(p) + 1) {
    h[i] = (h[i - 1] * B) % MOD;
    h[i] += V(p[i - 1]);
    h[i] %= MOD;
  }
  return h;
}

ll hash_fast(int i, int j) {
  ll ret = hash_S[j] - (hash_S[i - 1] * powers[j - i + 1]) % MOD;
  ret += MOD;
  if (ret >= MOD) ret -= MOD;
  return ret;
}

int solve(int k) {
  unordered_set<int> ret;
  rep(i, 0, sz(s)) {
    int j = (i + k - 1);
    if (j >= sz(s)) break;
    int h1 = (int)hash_fast(i + 1, i + sz(l));
    if (h1 != (int)hash_L[sz(l)]) continue;

    int h2 = (int)hash_fast(j + 2 - sz(r), j + 1);
    if (h2 != (int)hash_R[sz(r)]) continue;

    int h = (int)hash_fast(i + 1, j + 1);
    ret.insert(h);
  }
  return sz(ret);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<ll> bases;
  bases.pb(33);
  bases.pb(37);
  bases.pb(41);
  shuffle(all(bases), rng);
  B = bases[0];
  powers[0] = 1;
  rep(i, 1, 3000) powers[i] = (powers[i - 1] * B) % MOD;
  rep(i, 0, 26) vals[i] = i + 1;
  shuffle(all(vals), rng);

  cin >> s >> l >> r;
  hash_S = calc_hash(s), hash_L = calc_hash(l), hash_R = calc_hash(r);

  int n = sz(s), m = max(sz(l), sz(r));
  int ans = 0;
  rep(k, m, n + 1) ans += solve(k);
  printf("%d\n", ans);
  return 0;
}

