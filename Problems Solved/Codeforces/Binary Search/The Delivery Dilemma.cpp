#include <cstdio>

const int MAXN = 2e5, INF = 1e9;

int n, a[MAXN], b[MAXN];

bool ok(int k){
	int s=0;
	for(int i=0; i<n; i++){
		if(a[i] <= k) continue;
		s += b[i];
		if(s > k) return false;
	}
	return true;
}

int bs(){
	int l=0, r=INF;
	while(r>l){
		int mid = l+(r-l)/2;
		if(ok(mid)) r=mid;
		else l=mid+1;
	}
	return r;
}

int main(){
	int tt;
	scanf("%d",&tt);
	while(tt--){
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",a+i);
		for(int i=0; i<n; i++) scanf("%d",b+i);
		printf("%d\n", bs());
	}
	return 0;
}
