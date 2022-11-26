#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

#define f first
#define s second
#define sz(x) (int)x.size()

typedef long long ll;

const ll _sieve_size = 1e7 + 10;

ll n, m;
bitset<_sieve_size> bs;
vector<ll> p;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  p.push_back(2);
  for (ll i = 4; i < _sieve_size; i += 2) bs[i] = 0;
  for (ll i = 3; i < _sieve_size; i += 2) {
    if (bs[i]) {
      p.push_back(i);
      for (ll j = i * i; j < _sieve_size; j += i) bs[j] = 0;
    }
  }
}

vector<pair<ll, int>> f(ll x) {
  vector<pair<ll, int>> ret;

  for (int i = 0; i < sz(p) && p[i] * p[i] <= x; i++) {
    int cnt = 0;
    while (x % p[i] == 0) x /= p[i], cnt++;
    if (cnt > 0) ret.push_back({p[i], cnt});
  }

  if (x != 1) ret.push_back({x, 1});

  return ret;
}

bool solve(ll a, int cnt) {
  ll b = 1;
  for (int i = 0; i < cnt; i++) b *= a;
  ll acc = 0, currentExp = cnt, curr = 0;

  while (b > 1) {
    curr += ((n / b) - acc) * currentExp;
    acc += (n / b) - acc;
    if (curr >= cnt) return true;
    b /= a;
    currentExp--;
  }

  return false;
}

int main() {
  sieve();

  while (scanf("%lld%lld", &n, &m) != EOF) {
    vector<pair<ll, int>> factors = f(m);
    bool can = true;
    for (int i = 0; i < sz(factors); i++) {
      can &= solve(factors[i].f, factors[i].s);
    }
    if (can)
      printf("%lld divides %lld!\n", m, n);
    else
      printf("%lld does not divide %lld!\n", m, n);
  }
  return 0;
}
