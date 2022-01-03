#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs;
vll p;

void sieve(ll upperbound) {
  _sieve_size = upperbound+1;
  bs.set(); 

  bs[0] = bs[1] = 0;

  for (ll i=4; i<_sieve_size; i+=2) bs[i] = 0;
  
  for (ll i=3; i<_sieve_size; i+=2) {
    if (bs[i]) {
      p.push_back(i);
      for (ll j = i*i; j<_sieve_size; j+=i) 
        bs[j] = 0;
    }
  }
}

bool isPrime(ll n) {
  if (n < _sieve_size) return bs[n];
  else {
    for (int i=0; i < (int)p.size() && p[i] * p[i] <= n; i++) 
      if (n % p[i] == 0) 
        return false;
  }

  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0); 

  sieve(10000000);

  int N; cin >> N;

  cout << "There are " << (int)p.size() << " primes in range [1, " << _sieve_size << ")\n";

  (isPrime(N)) ? cout << N << " is prime\n" : cout << N << " is composite\n";

  return 0;
}

