#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
	cin>>n;
	vector<ll> a[n];
	forn(i,n){
		string s;
		cin>>s;
		ll cur=0;
		a[i].pb(0);
		for(char c : s){
			if(c=='1'){
				a[i].back() |= (1LL<<cur);
			}
			cur++;
			if(cur==63) a[i].pb(0), cur=0;
		}
	}
	ll ans=0;
	forn(i,n) fore(j,i+1,n){
		ll m=0;
		forn(k,len(a[i])){
			m += __builtin_popcountll(a[i][k] & a[j][k]);
		}
		ans += (m * (m-1LL))/2LL;
	}
	cout<<ans<<"\n";
	return 0;
}

