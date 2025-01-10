#include <bits/stdc++.h>
using namespace std;

#define fore(i,a,b) for(auto i=a; i<b; i++)
#define forn(i,n) fore(i,0,n)
#define dbg(x) cerr << #x << "=" << x << " ";
#define raya cerr << "\n-----------------------\n";

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-12;

struct pt {
	ld x, y;
	pt(){}
	pt(ld _x, ld _y){
		x = _x, y = _y;
	}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld k){return pt(x*k,y*k);}
	pt operator/(ld k){return pt(x/k,y/k);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator==(const pt p) const {
		return (abs(x-p.x) < EPS && abs(y-p.y) < EPS);
	}
};
ld norm2(pt p){ return p * p; }

struct line {
	pt p, d;
	pt eval(ld x){
		return p + d*x;
	}
};

bool point_in_segment(line l, pt p){
	pt q = p - l.p;
	if(q * l.d < 0) return false;
	if(q * l.d > norm2(l.d)) return false;

	ld a = (ld)(q * l.d) / (ld)norm2(l.d);
	return l.eval(a) == p;
}

bool line_segment(line l, line s){
	ld a = ( (l.p % l.d) - (s.p % l.d) ) / (s.d % l.d);
	if(a < 0 || a > 1) return false;

	ld b = ( (s.p % s.d) - (l.p % s.d) ) / (l.d % s.d);
	if(b < 0) return false;

	return true;
}

const int MAXN = 2000;

int n, m;

pt vertices[MAXN];

int solve(pt p){
	forn(i,n){
		line l = { vertices[i], vertices[(i+1)%n] - vertices[i] };
		if(point_in_segment(l, p)) return 1;
	}
	pt q;
	q.x = rand(), q.y = rand();
	bool flag=true;
	forn(i,n){
		if((vertices[(i+1)%n] - vertices[i]) % (q-p) == 0) flag=false;
	}
	while(!flag){
		flag=true;
		q.x = rand(), q.y = rand();
		forn(i,n){
			if((vertices[(i+1)%n] - vertices[i]) % (q-p) == 0) flag=false;
		}
	}
	int cnt=0;

	line l = { p, q-p };
	
	forn(i,n){
		line s = { vertices[i], vertices[(i+1)%n] - vertices[i] };
		if(line_segment(l, s)) cnt++;
	}

	if(cnt % 2 == 1) return 2;
	return 3;
}

int main(){
	scanf("%d%d",&n,&m);
	forn(i,n) scanf("%Lf %Lf", &vertices[i].x, &vertices[i].y);
	forn(i,m){
		pt p;
		scanf("%Lf %Lf", &p.x, &p.y);
		int ans = solve(p);
		if(ans == 1) puts("BOUNDARY");
		else if(ans == 2) puts("INSIDE");
		else puts("OUTSIDE");
	}
	return 0;
}

