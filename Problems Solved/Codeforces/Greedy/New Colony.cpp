#include <cstdio>

const int MAXN = 102;
int n, k, h[MAXN];

void solve(){
    int pos = 0;
    int ans = 0;
    for(int i = 0; i < 100*100; i++){
        k--;
        if(k < 0){
            printf("%d\n",ans+1);
            return;
        }
        
        ans = pos;

        while(pos != n-1 && h[pos] >= h[pos+1]){
            pos++;
            ans++;
        }

        if(pos == n-1){
            printf("-1\n");
            return;
        }

        else{
            h[pos]++;
            if(pos != 0) pos--;
        }
    }
}

int main(){
    int t; scanf("%d",&t);

    while(t--){
        scanf("%d%d",&n,&k);
        for(int i = 0; i < n; i++)
            scanf("%d",h+i);

        solve();
    }

    return 0;
}
