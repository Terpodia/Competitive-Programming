#include <iostream>
using namespace std;

typedef uint64_t u64;      // Unsigned integer 64 bits
typedef __uint128_t u128;  // Unsigned integer 128 bits

// Fast exponentiation O(log(e))
u64 binpow(u64 a, u64 e, u64 mod) {
  u64 ret = 1;
  a %= mod;

  // a^((14)base10) = a^((1110)base2) =
  // a^((1000 + 0100 + 0010)base2) =
  // a^((1000)base2) * a^((0100)base2) * a^((0010)base2)

  while (e) {   // While e > 0
    if (e & 1)  // if bit on first position is 1
      ret = ((u128)ret * (u128)a) % (u128)mod;

    a = ((u128)a * (u128)a) % (u128)mod;
    e >>= 1;  // shift to the right all bits -> 1101 >> 1 = 0110
  }

  return ret;  // ret = a^e % mod
}

// Return true if n is a composite number
bool check_composite(u64 n, u64 a, u64 d, int r) {
  u64 x = binpow(a, d, n) % n;
  if (x == 1 || x == n - 1) return false;

  for (int i = 1; i < r; i++) {
    x = ((u128)x * (u128)x) % (u128)n;
    if (x == n - 1) return false;
  }

  return true;
}

// Return true if n is prime, otherwise false
bool MillerRabin(u64 n) {
  if (n < 2) return false;  // 1 or 0 are not prime numbers

  u64 d = n - 1;
  int r = 0;
  while ((d & 1) == 0) {
    d >>= 1;
    r++;
  }

  for (u64 a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a) return true;
    if (check_composite(n, a, d, r)) return false;
  }

  return true;
}

int main() {
  int t;
  cin >> t;  // number of test cases

  while (t--) {
    u64 n;
    cin >> n;  // print YES if n is prime, otherwise print NO
    (MillerRabin(n)) ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
