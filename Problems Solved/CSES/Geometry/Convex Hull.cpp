#include <bits/stdc++.h>
using namespace std;

#define fore(i,a,b) for(auto i=a; i<b; i++)
#define forn(i,n) fore(i,0,n)
#define len(x) (int)x.size()
#define pb push_back
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

bool ccw(pt a, pt b, pt c){
	pt ab = b-a;
	pt ac = c-a;
	return ab % ac >= 0;
}

int main(){
	int n;
	scanf("%d",&n);
	pt p[n];	
	forn(i,n){
		scanf("%lld %lld", &p[i].x, &p[i].y);
	}
	pt p0 = p[0];
	fore(i,1,n){
		if(p[i].y < p0.y) p0=p[i];
		else if(p[i].y == p0.y && p[i].x < p0.x) p0=p[i];
	}
	sort(p,p+n,[&p0](pt a, pt b){
		pt p0a = a-p0;
		pt p0b = b-p0;
		if(p0a % p0b == 0) return norm2(p0a) < norm2(p0b);
		return p0a % p0b > 0;
	});

	int j=n-1;
	while(j >= 0 && (p[j]-p0) % (p[n-1]-p0) == 0){
		j--;
	}
	reverse(p+j+1, p+n);

	vector<pt> ans;
	forn(i,n){
		while(len(ans) > 1 && !ccw(ans[len(ans)-2], ans.back(), p[i])){
			ans.pop_back();
		}
		ans.pb(p[i]);
	}
	printf("%d\n", len(ans));
	forn(i,len(ans)){
		printf("%lld %lld\n", ans[i].x, ans[i].y);
	}
	return 0;
}

