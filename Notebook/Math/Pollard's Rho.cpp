#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef uint64_t u64;
typedef __uint128_t u128;

u64 multiply(u64 a, u64 b, u64 mod) { return ((u128)a * (u128)b) % (u128)mod; }

u64 gcd(u64 a, u64 b) { return (b == 0) ? a : gcd(b, a % b); }

u64 binpow(u64 a, u64 e, u64 mod) {
  u64 ret = 1;
  while (e) {
    if (e & 1) ret = multiply(ret, a, mod);
    a = multiply(a, a, mod);
    e >>= 1;
  }

  return ret;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
  u64 x = binpow(a, d, n);
  if (x == 1 || x == n - 1) return false;

  for (int i = 1; i < s; i++) {
    x = multiply(x, x, n);
    if (x == n - 1) return false;
  }

  return true;
}

bool rabin(u64 n) {
  if (n < 2) return false;
  u64 d = n - 1;
  int s = 0;

  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }

  for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, s)) return false;
  }

  return true;
}

u64 roh(u64 n) {
  if ((n & 1) == 0) return 2;
  u64 x = 2, y = 2, c = rand() % n + 1, g = 1;

  while (g == 1) {
    x = (multiply(x, x, n) + c) % n;
    y = (multiply(y, y, n) + c) % n;
    y = (multiply(y, y, n) + c) % n;
    g = (x > y) ? gcd(x - y, n) : gcd(y - x, n);
  }

  return (g == n) ? roh(n) : g;
}

void fact(u64 n, map<u64, int>& f) {
  if (n == 1) return;
  if (rabin(n)) {
    f[n]++;
    return;
  }
  u64 q = roh(n);
  fact(q, f);
  fact(n / q, f);
}

int main() {
  u64 n;

  while (cin >> n && n != 0) {
    if (n == 1) {
      cout << n << "\n";
      continue;
    }

    map<u64, int> f;
    fact(n, f);
    for (auto p : f) cout << p.first << "^" << p.second << " ";
    cout << "\n";
  }

  return 0;
}
