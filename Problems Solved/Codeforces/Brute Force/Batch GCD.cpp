#define FASTCOMP
#ifdef FASTCOMP
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
// #include<cstring>
#else
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#endif
using namespace std;
#ifndef FASTCOMP
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
#endif

// MACROS
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define sz(x) SZ(x)
#define len(x) SZ(x)
#define all(x) x.begin(), x.end()
#define esta(x, c) ((c).find(x) != (c).end())
// FOR
#define fore(i, a, b) for (auto i = a, to = b; i < to; ++i)
#define form(i, n, m) fore(i, n, m)
#define forn(i, n) form(i, 0, n)
#define dfor(i, n) for (int i = n; i-- > 0;)
#define forall(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
// DEBUG
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<
#define printv(v)                      \
  if (1) {                             \
    for (auto _ : v) cerr << _ << " "; \
    cerr << endl;                      \
  }

typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;

typedef unsigned long long u64;
typedef __uint128_t u128;

u64 modmul(u64 a, u64 b, u64 M) {
  ll ret = a * b - M * u64(1.L / M * a * b);
  return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
u64 binpow(u64 a, u64 e, u64 M) {
  u64 ret = 1;
  while (e) {
    if (e & 1) ret = modmul(ret, a, M);
    a = modmul(a, a, M);
    e >>= 1;
  }
  return ret;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = binpow(a, d, n);
  if (x == 1 || x == n - 1) return false;
  fore(i, 1, s) {
    x = modmul(x, x, n);
    if (x == 1 || x == n - 1) return false;
  }
  return true;
}
bool rabin(u64 n) {
  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;

  u64 d = n - 1;
  int s = 0;
  while (!(d & 1)) d >>= 1, s++;

  u64 A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  for (u64 a : A) {
    if (check_composite(n, a, d, s)) return false;
  }
  return true;
}

int _sieve_size;
vector<u64> cr;
vector<u64> pr;
void init_sieve(int N) {
  _sieve_size = N + 1;
  cr = vector<u64>(_sieve_size);
  for (int i = 0; i < _sieve_size; i++) cr[i] = i;
  for (int i = 4; i < _sieve_size; i += 2) cr[i] = 2;
  for (u64 i = 3; i < (u64)_sieve_size; i += 2) {
    if (cr[i] == i)
      for (u64 j = i * i; j < (u64)_sieve_size; j += i) cr[j] = i;
  }
  fore(i, 2, _sieve_size) if (cr[i] == i) pr.pb(i);
}
void fact(u64 n, vector<u64>& f) {
  for (int i = 0; pr[i] * pr[i] <= n; i++)
    if (n % pr[i] == 0) {
      while (n % pr[i] == 0) n /= pr[i];
      f.pb(pr[i]);
    }
  if (n > 1) f.pb(n);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const int pi = 9592;
  const int MAX = 1e7;
  init_sieve(MAX);
  int n;
  cin >> n;
  u64 a[n];
  forn(i, n) cin >> a[i];
  sort(a, a + n);

  vint idx;
  vector<u64> p;

  forn(i, n) {
    if (a[i] == 1LL) continue;
    if (a[i] < _sieve_size) {
      if (cr[a[i]] == a[i])
        p.pb(a[i]);
      else
        idx.pb(i);
    } else if (rabin(a[i]))
      p.pb(a[i]);
    else
      idx.pb(i);

    if (SZ(idx) > pi) break;
  }
  if (SZ(idx) > pi)
    cout << "YES\n";
  else {
    forn(i, SZ(idx)) {
      vector<u64> f;
      fact(a[idx[i]], f);
      for (auto& x : f) p.pb(x);
    }
    sort(all(p));
    bool yes = false;
    forn(i, SZ(p) - 1) {
      if (p[i] == p[i + 1]) {
        yes = true;
        break;
      }
    }
    if (yes)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}
