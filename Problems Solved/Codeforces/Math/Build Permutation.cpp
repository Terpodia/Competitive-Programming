#include <cstdio>
#include <vector>
#include <set>
using namespace std;

#define sz(x) (int)x.size()

int n;
set<int> s;

vector<int> solve(int m){
  vector<int> ret;
  if(s.find(m-1) != s.end()){
    for(int i=m-1; i>=0; i--) ret.push_back(i); 
    return ret;
  }
  int sqr = *s.upper_bound(m-1), k=1;
  for(int i=1; i<m; i++){
    if(i+m-1 < sqr) k++;
  }
  ret = solve(k);
  for(int i=m-1; i>=k; i--)
    ret.push_back(i);

  return ret;
}

int main(){
  for(int i=0; i*i < (int)1e6; i++) s.insert(i*i);

  int tt;
  scanf("%d",&tt);
  while(tt--){
    scanf("%d",&n);
    vector<int> ans = solve(n);
    for(int i=0; i<sz(ans); i++)
      printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
  }
  return 0;
}
