#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int t; scanf("%d",&t);
    while(t--){
        int n, k; scanf("%d%d", &n, &k);

        if((n-1)/2 < k) puts("-1");
        else{
            vector<int> ans(n, -1);
            int cnt=0;
            for(int i=1; i<n-1; i+=2){
                if(cnt == k) break;
                ans[i] = n-cnt; cnt++; 
            }
            cnt = 1;
            for(int i=0; i<n; i++){
                if(ans[i] == -1) { ans[i] = cnt; cnt++; }
            }

            for(int i=0; i<n; i++) printf("%d ", ans[i]);
            puts("");
        }
    }

    return 0;
}
