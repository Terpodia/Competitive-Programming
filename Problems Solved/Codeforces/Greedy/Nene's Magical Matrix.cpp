#include <cstdio>
#include <vector>
using namespace std;

int main(){
  int tt;
  scanf("%d",&tt);
  while(tt--){
    int n;
    scanf("%d",&n);
    vector<int> op[2*n-1];
    op[0].push_back(1);
    op[0].push_back(1);
    for(int i=n; i>0; i--) op[0].push_back(i);
    int j=2;
    int cur=1;
    int acc=0;
    while(j <= n){
      if(cur == 0){
        op[j-1+acc].push_back(1);
        op[j-1+acc].push_back(j);
        for(int i=n; i>0; i--) op[j-1+acc].push_back(i);
        j++;
      }
      else {
        op[j-1+acc].push_back(2);
        op[j-1+acc].push_back(j);
        for(int i=n; i>0; i--) op[j-1+acc].push_back(i);
        acc++;
      }
      cur = 1 - cur;
    }
    int sum=0;
    for(int i=n; i>=1; i--){
      sum += (i * 2 - 1) * i;
    }
    printf("%d %d\n", sum, 2*n-1);
    for(int i=0; i<2*n-1; i++){
      for(int j=0; j<(int)op[i].size(); j++){
        printf("%d ", op[i][j]);
      }
      puts("");
    }
  }
  return 0;
}
