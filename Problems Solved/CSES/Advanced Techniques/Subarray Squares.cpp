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

const int MAXN = 3010;

const ll INF = 1e17+10LL;

ll x[MAXN], dp[MAXN][MAXN], pref[MAXN];

void f(int i, int l, int r, int optl, int optr){
	if(l > r) return;

	int mid = (l+r)/2;
	
	ll res = (pref[mid] - pref[optl-1]) * (pref[mid] - pref[optl-1]) + dp[i-1][optl-1];
	int opt = optl;

	fore(j,optl+1,min(optr, mid)+1){
		ll C = pref[mid] - pref[j-1]; C *= C;
		if(res >= C + dp[i-1][j-1]){
			res = C + dp[i-1][j-1];
			opt = j;
		}
	}
	dp[i][mid] = res;
	f(i, l, mid-1, optl, opt);
	f(i, mid+1, r, opt, optr);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n, k;
	cin>>n>>k;
	fore(i,1,n+1) cin>>x[i];

	fore(i,1,n+1) pref[i]=pref[i-1]+x[i];

	forn(i,n+1) forn(j,n+1) dp[i][j] = INF;
	dp[0][0] = 0;
	fore(i,1,k+1){
		f(i,1,n,1,n);
	}
	cout << dp[k][n] << "\n";
	return 0;
}

