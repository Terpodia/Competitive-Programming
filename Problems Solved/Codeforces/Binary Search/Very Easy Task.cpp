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

typedef long long ll;

ll n, x, y;

ll solve(){
	ll l=0, r=n;
	while(r>l){
		ll mid=l+(r-l)/2;
		ll t1 = mid * x;
		ll t2 = (n - mid) * y;
		if (t1 >= t2) r = mid;
		else l = mid + 1;
	}
	ll t1 = r * x, t2 = (n - r + 1) * y;
	return min(t1, t2);
}

int main(){
	scanf("%lld%lld%lld",&n,&x,&y);
	if(x>y) swap(x,y);
	ll ans=x;
	n--;
	ans += solve();
	printf("%lld\n", ans);
	return 0;
}

