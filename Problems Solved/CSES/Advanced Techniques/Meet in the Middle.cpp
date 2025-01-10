#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i,a,b) for(auto i=a;i<b;i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for(auto i=n;i-->0;)
#define dbg(x) cerr << "LINE" $ __LINE__ <<":" $ #x << "=" << x << endl;
#define raya cerr << "\n-----------------------------------------------------------\n"
#define $ <<" "<<

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T,U> &p){
	os << '(' << p.first $ p.second << ')';
	return os;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
	os << "[";
	forn(i, len(v)){
		if(i) os << ", ";
		os << v[i];
	}
	os << "]";
	return os;
}

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	ll x;
	cin>>n>>x;
	ll a[n];
	forn(i,n) cin>>a[i];
	if(n==1){
		if(a[0] == x) cout<<"1\n";
		else cout<<"0\n";
		return 0;
	}

	vector<ll> v1, v2;

	forn(msk, 1<<(n/2)){
		ll sum=0;
		forn(i,n/2) if(msk & (1<<i)){
			sum += a[i];
		}
		v1.pb(sum);
	}
	forn(msk, 1<<((n+1)/2)){
		ll sum=0;
		forn(i,(n+1)/2) if(msk & (1<<i)){
			sum += a[i + n/2];
		}
		v2.pb(sum);
	}
	sort(all(v2));

	ll ans=0;

	for(ll i : v1){
		if(i > x) continue;
		auto it = lower_bound(all(v2), x-i);
		if(it == v2.end()) continue;
		auto it2 = upper_bound(all(v2), x-i);
		ans += (ll)distance(it, it2);
	}

	cout << ans << "\n";
	return 0;
}

