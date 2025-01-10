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

vector<int> g[2][MAXN];
int comp[MAXN];
bool vis[MAXN];
vector<int> st;
int n, m, k;

void dfs1(int u){
  vis[u]=true;
  for(int v : g[1][u]) if(!vis[v]) dfs1(v);
  st.push_back(u);
}
void dfs2(int u, int idx){
  comp[u]=idx;
  for(int v : g[0][u]) if(comp[v]==-1) dfs2(v,idx);
}
void scc(){
  for(int i=0; i<n; i++) if(!vis[i]) dfs1(i);
  reverse(st.begin(), st.end());
  for(int u : st) if(comp[u]==-1) dfs2(u,k), k++;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  forn(i,m){
    int u,v;
    cin>>u>>v;
    u--, v--;
    g[0][u].pb(v);
    g[1][v].pb(u);
  }
  memset(comp,-1,sizeof(comp));
  scc();
  cout << k << "\n";
  forn(i,n) cout << comp[i]+1 << " ";
  cout << "\n";
  return 0;
}

