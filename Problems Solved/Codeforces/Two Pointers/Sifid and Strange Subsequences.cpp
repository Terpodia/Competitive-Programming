#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
using ii = pair<int,int>;

const int MAXN = 1e5;
int n, a[MAXN];

int solve(){
    sort(a, a+n, greater<int>());
    ii d[MAXN];
    for(int i=0; i<n-1; i++){
        d[i].first = abs(a[i] - a[i+1]);
        d[i].second = i;
    }

    sort(d, d+(n-1));

    //for(int i=0; i<n-1; i++) printf("%d %d\n", d[i].first, d[i].second);

    int p = 0, cnt=0;

    for(int i=0; i<n-1; i++){
        while(p < n && d[p].second < i){
            p++;
        }

        if(d[p].first >= a[i]) break;
        else cnt++;
    }

    return n - cnt;
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",a+i); 
        printf("%d\n", solve());
    }

    return 0;
}
