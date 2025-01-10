#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << "=" << x << " ";
#define raya cerr << "\n-----------------------\n";

typedef long long ll;

struct pt {
	ll x, y;
	pt(ll _x=0, ll _y=0) : x(_x), y(_y) {}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll operator%(pt p){return x*p.y-y*p.x;}
};
ll norm2(pt p){ return p * p; }

int main(){
	int n;
	scanf("%d",&n);
	pt vertices[n];
	for(int i=0; i<n; i++){
		scanf("%lld %lld", &vertices[i].x, &vertices[i].y);
	}
	ll cnt=0, a=0;
	for(int i=0; i<n; i++){
		a += (vertices[i] % vertices[(i+1)%n]);
		pt p1 = vertices[i], p2 = vertices[(i+1)%n];

		if(p1.x > p2.x) swap(p1, p2);

		if(p1.x == p2.x){
			cnt += abs(p1.y - p2.y);
			continue;
		}
		ll g = __gcd(abs(p1.y - p2.y), abs(p1.x - p2.x));
		ll den = (p2.x - p1.x) / g;

		cnt += (p2.x - p1.x) / den;
	}

	a = abs(a);
	ll I = (a - cnt + 2) / 2;
	printf("%lld %lld\n", I, cnt);
	return 0;
}

