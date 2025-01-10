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

const ll P=1777771,MOD[2]={999727999,1070777777};
struct Hash {
	vector<ll> h[2],pow[2];
	Hash(){}
	Hash(string& s){
		forn(k,2) h[k]=vector<ll>(len(s)+1,0),pow[k]=vector<ll>(len(s)+1,1);
		forn(k,2) fore(i,1,len(s)+1){
			h[k][i] = (h[k][i-1]*P+(ll)s[i-1])%MOD[k];
			pow[k][i]=(pow[k][i-1]*P)%MOD[k]; 
		}
	}
	ll get(int l, int r){
		ll ret[2];
		forn(k,2) ret[k]=((h[k][r]-pow[k][r-l]*h[k][l])%MOD[k]+MOD[k])%MOD[k];
		return (ret[0]<<32LL)|ret[1];
	}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	Hash h(s);
	vector<int> ans;
	fore(i,1,len(s)+1){
		bool can=true;
		for(int j=0; j<len(s); j+=i){
			int sz = min(i, len(s)-j);
			can &= h.get(0, sz) == h.get(j, j+sz);
		}
		if(can) ans.pb(i);
	}
	for(int i : ans) cout << i << " ";
	cout<<"\n";
	return 0;
}

