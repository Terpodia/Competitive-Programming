#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,n) for(__typeof(n)i=(x);i!=(n);i+=1-2*((x)>(n)))
#define dbg(x) cout<<#x<<"="<<x<<" ";
#define line cout<<"\n............................................\n";

typedef long long ll;

const ll INF = 1e18;

typedef __int128_t i128;

const int MAXHSZ = 2e5;
int hsz;
ll hm[MAXHSZ], hb[MAXHSZ];

void add_line(ll m, ll b){
	while(hsz>1){
		if((i128)(hb[hsz-1]-b) * (i128)(hm[hsz-1]-hm[hsz-2]) <=
		   (i128)(hb[hsz-2]-hb[hsz-1]) * (i128)(m-hm[hsz-1])){ 
			hsz--; 
		   }
		else break;
	}
	hm[hsz]=m;
	hb[hsz++]=b;
}
ll query(ll x){
	int l=0, r=hsz-1;
	while(r>l){
		int mid=l+(r-l+1)/2;

		ll m1=hm[mid], m2=hm[mid-1], b1=hb[mid], b2=hb[mid-1];
		if(m2 - m1 < 0){swap(m2,m1); swap(m1,m2);}

		if(b1-b2 <= x*(m2-m1)) l=mid;
		else r=mid-1;
	}
	return hm[l] * x + hb[l];
}

int main(){
	int n;
	ll C;
	scanf("%d%lld",&n,&C);
	ll h[n];
	rep(i,0,n) scanf("%lld",h+i);

	ll dp[n];
	dp[0] = 0;
	rep(i,1,n){
		add_line(-2*h[i-1], dp[i-1] + h[i-1]*h[i-1]);
		dp[i] = query(h[i]) + h[i]*h[i] + C;
	}
	printf("%lld\n",dp[n-1]);
	return 0;
}

