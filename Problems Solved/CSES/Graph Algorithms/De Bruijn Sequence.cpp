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

const int MAXN = 1<<15;

int n;
vector<int> g[MAXN];
vector<int> a, ans;

void solve(int u){
  while(len(g[u])){
    int v = g[u].back();
    g[u].pop_back();
    solve(v);
  }
  a.pb(u);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  if(n==1){
    cout<<"10\n";
    return 0;
  }
  forn(msk,1<<(n-1)){
    int nmsk = msk;
    if(nmsk & (1<<(n-2))) nmsk ^= (1<<(n-2));
    nmsk = (nmsk << 1);
    g[msk].pb(nmsk);
    g[msk].pb(nmsk^1);
  }
  solve(0);
  reverse(all(a));
  forn(i,len(a)-1){
    int b = a[i] & (1<<(n-2));
    if(b>0) b=1;
    ans.pb(b);
  }
  
  forn(i,n-1) ans.pb(ans[i]);

  for(int i : ans) cout << i;
  cout << "\n";
  return 0;
}

