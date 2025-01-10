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

const ll MOD = 1e9+7;

int n, m;
string s;
vector<int> p;
ll dp[1010][110], po[1010];

vector<int> kmppre(string& s){
	vector<int> b(len(s)+1,-1);
	int j=-1;
	fore(i,0,len(s)){
		while(j > -1 && s[i]!=s[j])j=b[j];
		b[i+1]=++j;
	}
	return b;
}

ll solve(int i, int j){
	ll& ret = dp[i][j];
	if(ret != -1) return ret;
	if(j == m) return po[n-i];
	if(i == n) return ret=0;
	ret = 0;
	forn(c,26){
		int k = j;
		while(k > -1 && (c+'A') != s[k]) k = p[k];
		ret += solve(i+1, k+1);
		ret %= MOD;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	m = len(s);
	p = kmppre(s);
	memset(dp,-1,sizeof(dp));
	po[0]=1;
	fore(i,1,1010) po[i] = (po[i-1] * 26) % MOD;
	cout << solve(0,0) << "\n";
	return 0;
}

