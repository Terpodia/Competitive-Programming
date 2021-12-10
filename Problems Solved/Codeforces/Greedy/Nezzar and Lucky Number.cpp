#include <cstdio>

typedef long long ll;

bool is_d_lucky(int d, ll x){
  while(x>0){
    int dd = x%10;
    if(dd == d) return true;
    x/=10;
  }
  return false;
}

bool is_trivial(int d, ll x){
	return x%d == 0 || is_d_lucky(d, x); 
}

bool solve(ll a, int d){
	if(is_trivial(d, a)) return true;
    int r = a%d;
    while(!is_d_lucky(d, r)) r+=d;
    return (r <= a);
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
  	int q, d; scanf("%d%d",&q,&d);
  	
    while(q--){
    	ll a; scanf("%lld",&a);
		printf(solve(a, d) ? "YES\n" : "NO\n");
    }
  }

	return 0;
}
