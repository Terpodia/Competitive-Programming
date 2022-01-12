#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <tuple>
using namespace std;
int aux;

int n,x[7],v[7];
set<tuple<int,int,int>> s;

// A B C A+B A+C B+C A+B+C
void solve(){
  int T[7]; memset(T,-1,sizeof(T));
  for(int i=0; i<n; i++) T[v[i]] = x[i];

  int cnt=0;
  for(int i=0; i<3; i++) if(T[i]!=-1) cnt++;

  if(cnt<3){
    if(cnt==0){
      if((T[4]-T[3]+T[5])%2!=0) return;
      T[2]=(T[4]-T[3]+T[5])/2;
      T[1]=T[5]-T[2];
      T[0]=T[3]-T[1];
    }
    else if(cnt==1){
      int *A=nullptr, *B=nullptr, *C=nullptr;    
      int *APLUSB=nullptr, *APLUSC=nullptr, *BPLUSC=nullptr;
      if(T[0]!=-1){
        A=&T[0],B=&T[1],C=&T[2];
        if(T[3]!=-1) APLUSB=&T[3];
        if(T[4]!=-1) APLUSC=&T[4];
        if(T[5]!=-1) BPLUSC=&T[5];
      }
      else if(T[1]!=-1){
        A=&T[1], B=&T[0], C=&T[2];
        if(T[3]!=-1) APLUSB=&T[3];
        if(T[4]!=-1) BPLUSC=&T[4];
        if(T[5]!=-1) APLUSC=&T[5];
      }
      else{
        A=&T[2], B=&T[1], C=&T[0];
        if(T[3]!=-1) BPLUSC=&T[3];
        if(T[4]!=-1) APLUSC=&T[4];
        if(T[5]!=-1) APLUSB=&T[5];
      }

      if(APLUSB!=nullptr && APLUSC!=nullptr){
        *B=*APLUSB-*A, *C=*APLUSC-*A;
      }
      else if(APLUSB!=nullptr){
        *B=*APLUSB-*A;
        *C=*BPLUSC-*B;
      }
      else{
        *C=*APLUSC-*A;
        *B=*BPLUSC-*C;
      }
    }

    else{
      int *A=nullptr, *B=nullptr, *C=nullptr;    
      int *BPLUSC=nullptr, *APLUSC=nullptr;
      if(T[0]!=-1 && T[1]!=-1){
        A=&T[0], B=&T[1], C=&T[2];
        if(T[4]!=-1) APLUSC=&T[4];
        if(T[5]!=-1) BPLUSC=&T[5];
      }
      else if(T[0]!=-1 && T[2]!=-1){
        A=&T[0], B=&T[2], C=&T[1];
        if(T[3]!=-1) APLUSC=&T[3];
        if(T[5]!=-1) BPLUSC=&T[5];
      }
      else{
        A=&T[1], B=&T[2], C=&T[0];
        if(T[3]!=-1) APLUSC=&T[3];
        if(T[4]!=-1) BPLUSC=&T[4];
      }

      if(T[6]!=-1) *C=T[6]-*A-*B;
      else if(APLUSC!=nullptr) *C=*APLUSC-*A;
      else *C=*BPLUSC-*B;
    }
  }

  if(T[3]==-1) T[3]=T[0]+T[1];
  if(T[4]==-1) T[4]=T[0]+T[2];
  if(T[5]==-1) T[5]=T[1]+T[2];
  if(T[6]==-1) T[6]=T[0]+T[1]+T[2];

  for(int i=0; i<7; i++) if(T[i]<1) return;
  
  if(T[3]!=T[0]+T[1] || T[4]!=T[0]+T[2] || T[5]!=T[1]+T[2] || T[6]!=T[0]+T[1]+T[2]) return;
  if(!(T[0]<=T[1] && T[0]<=T[2] && T[1]<=T[2])) return;
  s.insert(make_tuple(T[0],T[1],T[2]));
}

int main(){
  int TC;
  aux=scanf("%d",&TC);
  while(TC--){
    aux=scanf("%d",&n);
    for(int i=0; i<n; i++){
      aux=scanf("%d",x+i);
    }
    int p[]={1,2,3,4,5,6,7};
    do{
      for(int i=0; i<n; i++) v[i]=p[i]-1; 
      solve();
    }while(next_permutation(p,p+7));
    printf("%d\n",(int)s.size());
    //for (auto[a,b,c] : s) printf("%d %d %d\n", a, b, c); 
    s.clear();
  }
  return 0;
}

