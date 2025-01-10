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

const int INF = 1e9+10;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n, q;
  cin>>n>>q;
  int x[n];
  forn(i,n) cin>>x[i];
  int st[n][20];
  forn(i,n) forn(j,20) st[i][j]=INF;
  forn(i,n) st[i][0] = x[i];
  fore(j,1,20) forn(i,n) {
    st[i][j] = st[i][j-1];
    int p = 1<<(j-1);
    if(i+p < n) st[i][j]=min(st[i][j], st[i+p][j-1]);
  }
  while(q--){
    int l,r;
    cin>>l>>r;
    l--, r--;
    int ans = INF;
    for(int j=19; j>=0; j--){
      int p = 1<<j;
      if(l+p-1 <= r){
        ans=min(ans,st[l][j]), l+=p;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
