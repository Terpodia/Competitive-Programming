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

  p.push_back(2);

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

vll primeFactors(ll n) {
  vll factors;
  for (int i=0; i < (int)p.size() && p[i] * p[i] <= n; i++) {
    while (n % p[i] == 0) factors.push_back(p[i]), n /= p[i];
  }

  if (n > 1) factors.push_back(n);
  return factors;
}

int numPF(ll n) {
  int ret=0;

  for (int i=0; i < (int)p.size() && p[i] * p[i] <= n; i++) {
    while (n % p[i] == 0) n /= p[i], ret++;
  }

  if (n > 1) ret++;
  return ret;
}

int numDiv(ll n) {
  int ret=1;

  for (int i=0; i < (int)p.size() && p[i] * p[i] <= n; i++) {
    int cnt=1;
    while (n % p[i] == 0) n /= p[i], cnt++;

    ret *= cnt;
  }

  if (n > 1) ret *= 2;
  return ret;
}

ll sumDiv(ll n) {
  ll ret=1;

  for (int i=0; i < (int)p.size() && p[i] * p[i] <= n; i++) {
    ll cnt=1, power=p[i];
    while (n % p[i] == 0) n /= p[i], cnt += power, power *= p[i];
    
    ret *= cnt;
  }

  if (n > 1) ret *= (1 + n);

  return ret;
}

ll eulerPhi(ll n) {
  ll ret = n;

  for (int i=0; i < (int)p.size() && p[i] * p[i] <= n; i++) {
    if (n % p[i] == 0) ret -= ret / p[i];
    while (n % p[i] == 0) n /= p[i];
  }

  if (n > 1) ret -= ret / n;
  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0); 

  sieve(10000000);

  ll N; cin >> N;

  cout << "There are " << (int)p.size() << " primes in range [1, " << _sieve_size << ")\n";

  (isPrime(N)) ? cout << N << " is prime\n" : cout << N << " is composite\n";

  cout << N << " has " << numPF(N) << " prime factors\n";

  vll factors = primeFactors(N);

  if (!factors.empty()) {
    cout << "They are: ";
    for (auto x : factors) cout << x << " ";
    cout << "\n";
  }

  cout << N << " has " << numDiv(N) << " divisors\n"; 

  cout << "The sum of the divisors of " << N << " is " << sumDiv(N) << "\n";

  cout << "eulerPhi(" << N << ") = " << eulerPhi(N) << "\n";

  return 0;
}

