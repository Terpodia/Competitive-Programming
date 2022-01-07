#include <iostream>
#include <vector>
using namespace std;
int aux;

typedef vector<int> vi;

#define FOR(i,x,n) for (int i=(x); i<(int)(n); i++) 

int n,m,f[500][500];
vi g[510],vis,match;

int mcbm(int L){
  if(vis[L]) return 0;
  vis[L]=1;
  for(auto& R : g[L]){
    if(match[R] == -1 || mcbm(match[R])){
      match[R] = L;
      return 1;
    }
  } 
  return 0;
}

int main(){
  int TC; aux=scanf("%d",&TC);
  FOR(_,1,TC+1){
    aux=scanf("%d%d",&n,&m); //number of nodes in left and right side
    FOR(i,0,n) FOR(j,0,m) aux=scanf("%d",&f[i][j]);
    FOR(i,0,n) FOR(j,0,m){
      if(f[i][j]) // true if there is an adge between left node and right node
        g[i].push_back(n+j); 
    }
    match = vi(n+m,-1);
    int ans=0;
    FOR(L,0,n){
      vis=vi(n,0);
      ans+=mcbm(L);
    } 
    printf("Case %d: MCBM = %d\n",_,ans);
    FOR(i,0,n) g[i].clear(); 
  }
  return 0;
}

