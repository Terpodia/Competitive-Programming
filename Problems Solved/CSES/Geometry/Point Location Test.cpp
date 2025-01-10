#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		ll x1, y1, x2, y2, x3, y3;	
		scanf("%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3);
		
		ll prod = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);

		if(prod < 0) puts("RIGHT");
		else if(prod > 0) puts("LEFT");
		else puts("TOUCH");
	}
	return 0;
}

