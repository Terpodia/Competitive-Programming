#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        int n; scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",a+i);

        if(a[0]==1) {
            printf("%d ", n+1);
            for(int i=1; i<=n; i++) printf("%d%c",i," \n"[i==n]);
        }
        
        else {
            bool can=false;
            vector<int> ans;
            for(int i=0; i<n; i++) {
                if(can) { ans.push_back(i+1); continue; }

                if(i == n-1) {
                    if(a[i]==0) { 
                        ans.push_back(i+1); 
                        ans.push_back(n+1); 
                        can=true; 
                    }
                }
                
                else {
                    if(a[i] == 0 && a[i+1] == 1) {
                        ans.push_back(i+1);
                        ans.push_back(n+1);
                        can = true;
                    }

                    else ans.push_back(i+1);
                }
            }

            if(!can) puts("-1");
            else 
                for(int i=0; i<n+1; i++)
                   printf("%d%c",ans[i]," \n"[i==n]); 
        }
    }


    return 0;
}

