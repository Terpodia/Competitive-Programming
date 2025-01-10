#include <bits/stdc++.h>
using namespace std;

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

bool segment_segment(line l1, line l2){
	ld a = ( (l1.p % l1.d) - (l2.p % l1.d) ) / (l2.d % l1.d);
	if(a < 0 || a > 1) return false;

	ld b = ( (l2.p % l2.d) - (l1.p % l2.d) ) / (l1.d % l2.d);
	if(b < 0 || b > 1) return false;

	return true;
}

int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		pt p1, p2, p3, p4;
		scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);

		line l1 = { p1, p2-p1 };
		line l2 = { p3, p4-p3 };

		if(abs(l1.d % l2.d) < EPS){
			bool can = false;
			can |= point_in_segment(l1, p3);
			can |= point_in_segment(l1, p4);
			can |= point_in_segment(l2, p1);
			can |= point_in_segment(l2, p2);

			printf("%s\n", (can) ? "YES" : "NO");
		}
		else{
			printf("%s\n", (segment_segment(l1, l2)) ? "YES" : "NO");
		}
	}
	return 0;
}

