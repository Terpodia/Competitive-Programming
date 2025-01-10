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

const ll INF = 8000000000000000000LL;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	cin>>n;
	pair<ll,ll> p[n];
	forn(i,n){
		ll x,y;
		cin>>x>>y;
		p[i] = {x,y};
	}
	sort(p,p+n);
	set<pair<ll,ll>> s;
	s.insert(make_pair(p[0].snd, p[0].fst));
	int j=0;
	ll ans = INF;

	fore(i,1,n){
		ll d = ceil(sqrt(ans));
		while(p[i].fst - p[j].fst > d){
			s.erase(make_pair(p[j].snd, p[j].fst));
			j++;
		}
		auto it1 = s.upper_bound(make_pair(p[i].snd - d - 1LL, INF));
		auto it2 = s.upper_bound(make_pair(p[i].snd + d, INF));

		for(auto it = it1; it != it2; it++){
			ans = min(ans, (it->snd-p[i].fst)*(it->snd-p[i].fst)+(it->fst-p[i].snd)*(it->fst-p[i].snd));
		}

		s.insert(make_pair(p[i].snd, p[i].fst));
	}
	cout << ans << "\n";
	return 0;
}

