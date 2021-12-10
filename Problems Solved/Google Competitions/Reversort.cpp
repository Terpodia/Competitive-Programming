#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 100;
int N, l[MAXN];

int solve(){
    int ret=0;
    
    for(int i=0; i<N-1; i++){
        pair<int,int> p = {1e9, -1};

        for(int j=i; j < N; j++){
            if(l[j] < p.first) { p = {l[j], j}; } 
        } 
        
        ret += p.second - i + 1;
        
        int j = i, z = p.second;
        while(j < z){ swap(l[j], l[z]); j++; z--; } 
    }

    return ret;
}

int main(){
    int t, x=1; scanf("%d",&t);
    
    while(t--){
        scanf("%d",&N);
        for(int i=0; i<N; i++) scanf("%d",l+i);
        printf("Case #%d: %d\n", x, solve());
        x++;
    }

    return 0;
}
