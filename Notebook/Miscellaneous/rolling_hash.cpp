#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int MAXN = 2e5;
const ll MOD = 1e9 + 7;
const ll c = 5381;

ll b, B[MAXN], C[MAXN];
vector<ll> vals(26);
ll V(char letter) { return vals[letter - 'a']; }

vector<ll> computeRollingHash(string& p) {
  vector<ll> h(sz(p) + 1);
  h[0] = 0;
  rep(i, 1, sz(p) + 1) {
    h[i] = (h[i - 1] * b) % MOD;
    h[i] += V(p[i - 1]);
    h[i] %= MOD;
  }
  return h;
}
ll hash_fast(vector<ll>& h, int i, int j) {
  ll ret = h[j] - (h[i - 1] * B[j - i + 1]) % MOD;
  ret = (ret + MOD) % MOD;
  ret = (ret + C[j - i + 1]) % MOD;
  return ret;
}

int main() {
  vector<ll> bases;
  bases.pb(33);
  bases.pb(37);
  bases.pb(41);
  shuffle(all(bases), rng);
  b = bases[0];
  B[0] = 1;
  rep(i, 1, (int)2e5) B[i] = (B[i - 1] * b) % MOD;
  rep(i, 1, (int)2e5) C[i] = (C[i - 1] * c) % MOD;
  rep(i, 0, 26) vals[i] = i;
  shuffle(all(vals), rng);

  string s, t;
  cin >> s >> t;
  vector<ll> hs, ht;
  hs = computeRollingHash(s), ht = computeRollingHash(t);

  if (hash_fast(hs, 1, sz(s)) == hash_fast(ht, 1, sz(t)))
    cout << "The strings are equal\n";
  else
    cout << "The strings are not equal\n";

  return 0;
}
