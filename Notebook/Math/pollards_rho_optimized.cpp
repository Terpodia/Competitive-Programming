#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
typedef unsigned long long u64;
typedef __uint128_t u128;
typedef unordered_map<u64, u64> ump;
 
u64 mult(u64 a, u64 b, u64 mod){return ((u128)a * b) % mod;}
 
u64 binpow(u64 a, u64 e, u64 mod){
  u64 ret=1;
  while (e) {
    if(e & 1) ret = mult(ret, a, mod); 
    a = mult(a, a, mod);
    e >>= 1;
  }
  return ret;
}
 
bool check_composite(u64 n, u64 a, u64 d, int s){
  u64 x = binpow(a, d, n);
  if(x == 1 || x == n-1) return false;
  for(int i=1; i<s; i++) {
      x = mult(x, x, n);
      if(x == n-1) return false;
  }
  return true;
}
 
bool rabin(u64 n){
  if(n < 2) return false;
  u64 d = n-1;
  int s=0;
  while((d & 1) == 0){
      d >>= 1;
      s++;
  }
  for(u64 a : { 2, 3, 5, 7, 11, 13, 17, 19, 23 } ){
      if(n == a) return true;
      if(check_composite(n, a, d, s)) return false;
  }
  return true;
}
 
int _sieve_size;
vector<u64> sieve;
 
void buildSieve(int N){
  _sieve_size = N+1;
  sieve = vector<u64>(_sieve_size);
  for (int i=0; i<_sieve_size; i++) sieve[i] = i;
  for (int i=4; i<_sieve_size; i+=2) sieve[i] = 2;
  
  for (u64 i=3; i<(u64)_sieve_size; i+=2){
    if (sieve[i] == i) 
      for (u64 j=i*i; j<(u64)_sieve_size; j+=i) 
        sieve[j] = i;
  }
}
 
u64 rho(u64 n){
  if((n & 1) == 0) return 2;
	static u64 s[10000011];
	while(1){
	u64 x=rand()%n,y=x,c=rand()%n;
		u64 *px=s,*py=s,v=0,p=1;
		while(1){
			*py++=y=(mult(y,y,n)+c)%n;
			*py++=y=(mult(y,y,n)+c)%n;
			if((x=*px++)==y)break;
			u64 t=p;
      p=(y>x)?mult(p,y-x,n):mult(p,x-y,n);
			if(!p)return __gcd(t,n);

			if(++v==26){
				if((p=__gcd(p,n))>1&&p<n)return p;
				v=0;
			}
		}
		if((p=__gcd(p,n))>1&&p<n)return p;
	}
}
 
void fact(u64 n, ump& f){
  for(auto it=f.begin(); it!=f.end(); it++){
    if(n<=1) break;
    while (n%it->first==0) {
      it->second++; 
      n /= it->first;
    }
  }
  if(n<=1)return;
  if (n<(u64)_sieve_size){
    while(n>1) {
      f[sieve[n]]++;
      n /= sieve[n];
    }
    return;
  }
  if (rabin(n)) {f[n]++; return;}
  u64 q = rho(n); fact(q, f); fact(n/q, f);
}
 
void fastIO(){cin.tie(0)->sync_with_stdio(0);}
 
int main(){
  fastIO();
  buildSieve((int)1e7 + 10);
  u64 n; cin >> n;
  ump factors;
  fact(n, factors);
  for(auto [p, e] : factors)
    cout << p << "^" << e << "\n";
  return 0;
}

