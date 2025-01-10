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

const int MAXN = 1e5+10;

int n,m;
vector<int> g[MAXN];
vector<int> ans;
set<pair<int,int>> s;
set<pair<int,int>> edges;

void dfs(int u){
  while(len(g[u])){
    int v = g[u].back();
    g[u].pop_back();
    dfs(v);
  }
  ans.pb(u);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  forn(i,m){
    int u,v;
    cin>>u>>v;
    u--, v--;
    g[u].pb(v);
    edges.insert(make_pair(u,v));
  }
  dfs(0);
  reverse(all(ans));
  if(ans[0] != 0 || ans.back() != n-1){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  forn(i,len(ans)-1){
    int u = ans[i], v = ans[i+1];
    if(s.find(make_pair(u,v)) != s.end()){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if(edges.find(make_pair(u,v)) == edges.end()){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    s.insert(make_pair(u,v));
  }
  forn(u,n) for(int v : g[u]){
    if(s.find(make_pair(u,v)) == s.end()){
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  forn(i,len(ans)) cout<<ans[i]+1<<" ";
  cout<<"\n";
  return 0;
}

