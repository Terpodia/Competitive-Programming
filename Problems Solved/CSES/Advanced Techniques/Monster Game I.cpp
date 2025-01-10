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

const int MAXN = 2e5+10;

const ll INF = 1e18;

int n;
ll s[MAXN], f[MAXN], dp[MAXN];

struct CHT {
  vector<ll> hm, hb;
  int hsz=0;
  CHT(){}
  void add_line(ll m, ll b){
    while(hsz>1){
      if((hb[hsz-1]-b)*(hm[hsz-1]-hm[hsz-2])<=(hb[hsz-2]-hb[hsz-1])*(m-hm[hsz-1])){
        hsz--;
        hm.pop_back(); hb.pop_back();
      }
      else break;
    }
    hm.pb(m);hb.pb(b);hsz++;
  }
  ll query(ll x){
    int l=0, r=hsz-1;
    while(r>l){
      int mid=l+(r-l+1)/2;
      if((hm[mid]-hm[mid-1])*x > hb[mid-1]-hb[mid]) l=mid;
      else r=mid-1;
    }
    return hm[l]*x+hb[l];
  }
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll x;
	cin>>n>>x;
	fore(i,1,n+1) cin>>s[i];
	fore(i,1,n+1) cin>>f[i];
	s[0] = 0, f[0] = x;
	dp[n] = 0;
	CHT chull;
	chull.add_line(-s[n], -0);
	dfor(i,n){
		dp[i] = -chull.query(f[i]);
		chull.add_line(-s[i], -dp[i]);
	}
	cout << dp[0] << "\n";
	return 0;
}

