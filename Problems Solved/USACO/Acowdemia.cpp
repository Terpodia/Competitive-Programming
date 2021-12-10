#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using vi = vector<int>;

#define sz(x) (int)x.size()

const int MAXN = 1e5, INF = 1e9;

int N, K, L, c[MAXN];

bool f(int h){
    int cnt = 0;
    vi a(L+1, 0); a[L] = K;
    bool flag = false;
    int pos = L;

    for(int i=0; i<N; i++){
        if(c[i] >= h) cnt++;
        else if(pos > 0 && !flag){
            int r = h - c[i]; 
            int s=0, init = pos;
            
            while(r > 0 && pos > 0){
                int aux = min(r, a[pos] - s);
                a[pos] -= aux; r -= aux;
                a[pos-1] += aux;
                
                if(a[pos] == 0) init--;
                if(a[pos] - s == 0){ pos--; s = aux; }
            }

            if(r == 0) cnt++;
            else flag = true;
            pos = init;
        }
    }

    return cnt >= h;
}

int bs(){
    int ans=0, l=0, r=1e9, mid;

    while(l <= r){
        mid = l + (r-l)/2;
        if(f(mid)){
            ans = mid; l = mid+1;
        } 
        else r = mid-1;
    }

    return ans;
}

int main(){
    scanf("%d%d%d",&N, &K, &L);
    for(int i=0; i<N; i++) scanf("%d", c+i);

    sort(c, c+N, greater<int>());

    printf("%d\n",bs());    

    return 0;
}
