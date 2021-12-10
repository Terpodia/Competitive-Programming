#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
int n, m, a[MAXN], cnt[MAXN];

void solve(){
    int ans = 0;
    memset(cnt, 0, sizeof(cnt)); 
    for(int i=0; i<n; i++) cnt[a[i]%m]++;

    for(int i=m-1; i>=0; i--){
        if(cnt[i]<=0) continue;
        
        int p = (m - i)%m;
        int r = min(cnt[i], cnt[p]);
        if(r>0){
            ans++;
            if(r!=cnt[i]) cnt[i] -= r+1;
            else cnt[i] -= r;

            if(i != p){
                if(r != cnt[p]) cnt[p] -= r+1;
                else cnt[p] -= r;
            }
        }

        ans += cnt[i];
        cnt[i]=0;
    }
    printf("%d\n",ans);
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) scanf("%d",a+i); 
        solve();
    }

    return 0;
}
