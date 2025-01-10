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

vector<int> g[2][MAXN];
int comp[MAXN], state[MAXN];
bool vis[MAXN];
vector<int> st;
int n, m;

void dfs1(int u){
  vis[u]=true;
  for(int v : g[1][u]) if(!vis[v]) dfs1(v);
  st.push_back(u);
}
void dfs2(int u, int idx){
  comp[u]=idx;
  int x = (u < n) ? (u) : (u-n);
  if(state[x] == -1) state[x] = (u < n) ? (1) : (0);
  for(int v : g[0][u]) if(comp[v]==-1) dfs2(v,idx);
}
void scc(){
  for(int i=0; i<2*n; i++) if(!vis[i]) dfs1(i);
  reverse(st.begin(), st.end());
  for(int u : st) if(comp[u]==-1) dfs2(u,u);
}

void add(int x, int y){
    int neg_x = (x < n) ? (x+n) : (x-n);
    g[0][neg_x].pb(y);
    int neg_y = (y < n) ? (y+n) : (y-n);
    g[0][neg_y].pb(x);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>m>>n;
  forn(i,m){
    char c1, c2;
    int a1, a2;
    cin>>c1>>a1>>c2>>a2;
    a1--, a2--;
    if(c1 == '-') a1 += n;
    if(c2 == '-') a2 += n;
    add(a1,a2);
  }
  forn(u,2*n) for(int v : g[0][u]){
    g[1][v].pb(u);
  }
  memset(comp,-1,sizeof(comp));
  memset(state,-1,sizeof(state));
  scc();
  forn(i,n) if(comp[i] == comp[i+n]){
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  forn(i,n){
    if(state[i] == 0) cout << "- ";
    else cout << "+ ";
  }
  cout<<"\n";
  return 0;
}

