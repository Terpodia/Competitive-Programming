#include "bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int MAXN = 5010;

const ll INF = 1e18;

int n;
ll x[MAXN], dp[MAXN][MAXN], pref[MAXN];
int opt[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	forn(i,n) cin>>x[i];
	fore(i,1,n+1) pref[i]=pref[i-1]+x[i-1];
	forn(i,n) forn(j,n) dp[i][j]=INF;
	forn(i,n) dp[i][i]=0, opt[i][i]=i;

	fore(r,1,n) dfor(l,r){
		ll C = pref[r+1]-pref[l];
		fore(i,opt[l][r-1],min(r, opt[l+1][r])+1){
			if(dp[l][r] > C+dp[l][i]+dp[i+1][r]){
				dp[l][r] = C+dp[l][i]+dp[i+1][r];
				opt[l][r] = i;
			}
		}
	}
	cout << dp[0][n-1] << "\n";
	return 0;
}

