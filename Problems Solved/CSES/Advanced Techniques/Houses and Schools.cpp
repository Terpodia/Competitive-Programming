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

const ll INF = 1e17;

const int MAXN = 3010;

int n;
ll a[MAXN], c[MAXN][MAXN], pref1[MAXN], pref2[MAXN], dp[MAXN][MAXN];

void calc(int i, int l, int r, int optl, int optr){
	if(r < l) return;
	int mid = (r+l)/2;
	int opt = optl;
	if(mid == n){
		dp[i][mid] = (pref2[n]-pref2[optl-1])-(ll)optl*(pref1[n]-pref1[optl-1])+dp[i-1][optl-1];
		fore(j,optl+1,min(mid,optr)+1){
			ll x = pref1[n]-pref1[j-1];
			ll y = pref2[n]-pref2[j-1];

			ll res = y - (ll) j * x + dp[i-1][j-1];
			if(dp[i][mid] > res) dp[i][mid] = res, opt = j;
		}
	}
	else{
		dp[i][mid] = c[optl][mid+1] + dp[i-1][optl-1];
		fore(j,optl+1,min(mid,optr)+1){
			ll res = c[j][mid+1] + dp[i-1][j-1];
			if(dp[i][mid] > res) dp[i][mid] = res, opt = j;
		}
	}
	calc(i, l, mid-1, optl, opt);
	calc(i, mid+1, r, opt, optr);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int k;
	cin>>n>>k;
	fore(i,1,n+1) cin>>a[i];
	if(n==1){
		cout<<"0\n";
		return 0;
	}

	fore(i,1,n+1){
		pref1[i]=pref1[i-1]+a[i];
		pref2[i]=pref2[i-1]+(ll)i*a[i];
	}
	fore(l,1,n+1){
		fore(r,l,n+1){
			// a[i] * (i-l) = a[i] * i - a[i] * l

			int mid = (l+r)/2;
			ll x = pref1[mid]-pref1[l-1];
			ll y = pref2[mid]-pref2[l-1];
			c[l][r] += y - (ll) l * x;

			// a[i] * (r-i) = a[i] * r - a[i] * i

			x = pref1[r]-pref1[mid];
			y = pref2[r]-pref2[mid];
			c[l][r] += (ll)r * x - y;
		}
	}
	dp[0][n] = INF;
	dfor(i,n){
		int r = i+1;
		dp[0][i] = pref1[r] * r - pref2[r];
	}
	fore(i,1,k+1){
		calc(i, 1, n, 1, n);
	}
	cout << dp[k][n] << "\n";
	return 0;
}

