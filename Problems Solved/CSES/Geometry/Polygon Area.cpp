#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << "=" << x << " ";
#define raya cerr << "\n-----------------------\n";

typedef long long ll;

struct pt {
	ll x, y;
	pt(ll _x=0, ll _y=0) : x(_x), y(_y){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
};

int main(){
	int n;	
	scanf("%d",&n);
	pt p[n];
	for(int i=0; i<n; i++){
		scanf("%lld %lld", &p[i].x, &p[i].y);
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		ans += (p[i] % p[(i+1)%n]);
	}
	printf("%lld\n", abs(ans));
	return 0;
}


