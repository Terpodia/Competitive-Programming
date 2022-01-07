#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef __uint128_t u128;
typedef long long ll;

const int MAXN=1e7+10;

ll gcd(ll a, ll b){ return (b==0)? a : gcd(b, a%b); }

ll mult(ll a, ll b, ll m){
  a%=m, b%=m; return ((u128)a*b)%m;
}

ll binpow(ll a, ll e, ll m){
  ll ret=1;
  while(e){
    if(e&1) ret=mult(ret,a,m);
    a=mult(a,a,m);
    e>>=1;
  }
  return ret;
}

bool isComposite(ll p, ll d, ll n, ll s){
  ll x=binpow(p,d,n);
  if (x==1 || x==n-1) return false;
  for (int i=1; i<s; i++){
    x = mult(x,x,n);
    if(x==n-1) return false;
  }
  return true;
}

bool rabin(ll n){
  if(n<2) return false;
  ll d=n-1; int s=0;
  while ((d&1)==0) d>>=1, s++;
  for(ll p : { 2, 3, 5, 7, 11, 13, 17, 19, 23 }){
    if(n==p) return true;
    if(isComposite(p,d,n,s)) return false;
  }
  return true;
}

ll sieve[MAXN+1];

void build_sieve(){
  for(int i=0; i<=MAXN; i++) sieve[i]=i;
  for(int i=4; i<=MAXN; i+=2) sieve[i]=2;
  for(ll i=3; i<=(ll)MAXN; i+=2){
    if (sieve[i]==i)
      for(ll j=i*i; j<=(ll)MAXN; j+=i)
        sieve[j]=i;
  }
}

ll rho(ll n){
  if((n&1)==0) return 2;
  static ll s[MAXN+1];
  while(1){
    ll x=rand()%n, y=x, c=rand()%n, v=0, p=1, *px=s, *py=s; 
    while(1){
      *py++=y=(mult(y,y,n)+c)%n; 
      *py++=y=(mult(y,y,n)+c)%n;
      if((x=*px++)==y) break;
      ll t=p;
      p=mult(p,abs(x-y),n);
      if(!p) return gcd(t, n);
      if (++v==26){
        if ((p=gcd(n,p))>1 && p<n) return p;
        v=0;
      }
    }
    if(v && (p=gcd(n,p))>1 && p<n) return p;
  }
}

void pollard_rho(ll n, map<ll,int>& f){
  for(auto& [p,cnt]:f){
    if(n<=1) break;
    while(n%p==0) n/=p, cnt++;
  } 
  if(n<=1) return;
  if(n<=MAXN){
    while(n>1) f[sieve[n]]++, n/=sieve[n];
    return;
  }
  if(rabin(n)) f[n]++;
  else { ll d=rho(n); pollard_rho(d, f); pollard_rho(n/d, f); }
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  build_sieve();
  ll n;
  while(cin>>n && n>-1){
    map<ll,int> factors;
    pollard_rho(n,factors);
    for(auto [p,cnt]:factors){
      for(int i=0; i<cnt; i++) cout << "    " << p << "\n";
    }    
    cout << "\n";
  }
  return 0;
}

