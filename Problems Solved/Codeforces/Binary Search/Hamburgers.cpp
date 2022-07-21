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

const ll INF = 1e13;

ll cntb, cnts, cntc, nb, ns, nc, pb, ps, pc, r;

bool can(ll k){
	if(k==0) return true;

	ll acc=0;
	if(cntb > 0 && acc<=r){
		ll m=k;
		m -= nb/cntb;
		if(m > 0) acc += (cntb - (nb%cntb)) * pb + cntb * (m-1) * pb;
	}
	if(cnts > 0 && acc<=r){
		ll m=k;
		m -= ns/cnts;
		if(m > 0) acc += (cnts - (ns%cnts)) * ps + cnts * (m-1) * ps;
	}	
	if(cntc > 0 && acc<=r){ 
		ll m=k;
		m -= nc/cntc;
		if(m > 0) acc += (cntc - (nc%cntc)) * pc + cntc * (m-1) * pc;
	}

	return acc<=r;
}

ll solve(){
	ll lo=0, hi=INF;
	while(hi>lo){
		ll mid=lo+(hi-lo+1)/2;
		if(can(mid)) lo=mid;
		else hi=mid-1;
	}
	return lo;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	for(char c : s){
		if(c=='B') cntb++;
		else if(c=='S') cnts++;
		else cntc++;
	}
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	cout << solve() << "\n";
	return 0;
}

