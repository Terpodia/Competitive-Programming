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

typedef long double ld;

ld dp[101][101];
int n, k;

ld solve(int i, int j){
	ld& ret = dp[i][j];
	if(ret > -1) return ret;
	ret=0;
	if(i==n) return ret=j;

	fore(z,1,k+1){
		ret += solve(i+1, max(j,z)) / k;	
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cout << fixed << setprecision(6);
	cin>>n>>k;
	forn(i,101) forn(j,101) dp[i][j]=-10;
	cout << solve(0,0) << "\n";
	return 0;
}

