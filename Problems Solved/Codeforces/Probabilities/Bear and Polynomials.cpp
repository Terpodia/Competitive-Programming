// Si puedes imaginarlo puedes programarlo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define pb push_back
#define make_pair mp
#define dbg(x) cerr << #x << "=" << x << " "
#define line cerr << "\n========================================\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const ll MOD[10] = {1000000123, 1000000181, 1000000207, 1000000223, 1000000241,
                    1000000271, 1000000289, 1000000297, 1000000321, 1000000349};

const ll INF = 1e18;

ll binpow(ll a, ll b, ll p) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

struct num {
  vector<ll> v;
  num() {}
  num(ll a) {
    v = vector<ll>(10, 0);
    rep(i, 0, 10) v[i] = (a % MOD[i] + MOD[i]) % MOD[i];
  }
  ll get() {
    ll res1 = v[0], res2 = v[0] - MOD[0];
    rep(i, 1, 10) {
      if (res1 != v[i]) res1 = INF;
      if (res2 != v[i] - MOD[i]) res2 = INF;
    }
    if (res1 != INF) return res1;
    if (res2 != INF) return res2;
    return INF;
  }
};

num sum(num a, num b) {
  num res(0);
  rep(i, 0, 10) res.v[i] = (a.v[i] + b.v[i]) % MOD[i];
  return res;
}

num sub(num a, num b) {
  num res(0);
  rep(i, 0, 10) res.v[i] = ((a.v[i] - b.v[i]) % MOD[i] + MOD[i]) % MOD[i];
  return res;
}

num mult(num a, num b) {
  num res(0);
  rep(i, 0, 10) res.v[i] = (a.v[i] * b.v[i]) % MOD[i];
  return res;
}

num div(num a, num b) {
  num res(0);
  rep(i, 0, 10) res.v[i] =
      (a.v[i] * binpow(b.v[i], MOD[i] - 2LL, MOD[i])) % MOD[i];
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  ll k;
  cin >> n >> k;
  ll a[n + 1];
  rep(i, 0, n + 1) cin >> a[i];

  num t[n + 1];
  t[0] = num(1);
  rep(i, 1, n + 1) t[i] = mult(t[i - 1], num(2));
  num s(0);
  rep(i, 0, n + 1) s = sum(s, mult(t[i], num(a[i])));

  int ans = 0;

  rep(i, 0, n + 1) {
    num r = sub(mult(num(a[i]), t[i]), s);
    r = div(r, t[i]);

    ll res = r.get();
    if (abs(res) > k || (i == n && res == 0)) continue;
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
