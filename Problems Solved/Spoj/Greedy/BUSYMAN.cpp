#include <stdio.h>
#include <algorithm>
using namespace std;

struct activity{
    int begin;
    int end;
};

const int MAXN = 1e5 + 7;
int N;
activity a[MAXN];

bool c(activity a1, activity a2){
    if(a1.end != a2.end) return a1.end < a2.end;
    return a1.begin < a2.begin;
}

void solve(){
    sort(a, a+N, c);
    int ans = 1;
    int j = 0;
    for(int i = 1; i < N; i++){
        if(a[i].begin >= a[j].end){
            j = i;
            ans++;
        }
    }

    printf("%d\n",ans);
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d",&N);
        for(int i = 0; i < N; i++)
            scanf("%d%d",&a[i].begin,&a[i].end);
         
        solve();
    }

    return 0;
}
