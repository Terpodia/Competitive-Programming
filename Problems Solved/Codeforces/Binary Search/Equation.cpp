// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rep(i,x,n) for(__typeof(n)i=(x); i!=(n); i+=1-2*((x)>(n)))
#define dbg(x) cout<<#x<<"="<<x<<" ";
#define line cout<<"\n............................................\n";

typedef long double ld;

ld C;

ld solve(){
	ld l=0,r=1e5;
	rep(i,0,70){
		ld mid = l+(r-l)/2;
		if(mid*mid + sqrtl(mid) <= C) l = mid;
		else r = mid;
	}
	return l;
}

int main(){
	scanf("%Lf",&C);
	printf("%.7Lf\n", solve());
	return 0;
}

