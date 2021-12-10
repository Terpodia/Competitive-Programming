#include <cstdio>

const int MAXN = 2e3;

int a[MAXN], n;

void solve(){
    int xor_total = 0;
    for(int i=0; i<n; i++) xor_total ^= a[i];

    if(xor_total == 0) { puts("YES"); return; }
    
    int acc=0, cnt=0;

    for(int i=0; i<n; i++){
        acc ^= a[i];
        if(acc == xor_total){
            cnt++;
            acc = 0;
        }
    }

    (cnt <= 1)? puts("NO") : puts("YES");
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",a+i);

        solve();
    }

    return 0;
}
