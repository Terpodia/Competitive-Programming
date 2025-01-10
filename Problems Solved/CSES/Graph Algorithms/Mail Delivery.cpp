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
bool vis[MAXN];
set<pair<int,int>> s;
vector<int> ans;

void cc(int u){
  vis[u]=true;
  for(int v : g[u]) if(!vis[v]) cc(v);
}

void dfs(int u){
  while(len(g[u])){
    int v = g[u].back();
    g[u].pop_back();
    pair<int,int> p = make_pair(u,v);
    if(p.fst > p.snd) swap(p.fst, p.snd);
    if(s.find(p) != s.end()) continue;
    s.insert(p);
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
    u--,v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  bool can=true;
  forn(i,n) can &= len(g[i])%2==0;
  cc(0);
  forn(i,n) if(!vis[i]) can &= len(g[i])==0;
  if(!can) cout << "IMPOSSIBLE\n";
  else{
    dfs(0);
    for(int i : ans) cout << i+1 << " ";
    cout << "\n";
  }
  return 0;
}

