#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
using dd = pair<long double,long double>;

const int MAXN = 1e3;
int n; long double d;
dd a[MAXN];

int solve(){
    int ret=1, i=1;
    sort(a, a+n);
    dd current = a[0];
    
    while(i < n){
        while(i < n && a[i].first <= current.second){
            current.first = a[i].first;
            current.second = min(a[i].second, current.second);
            i++;
        }

        if(i < n) { ret++; current = a[i]; i++; }
    } 

    return ret;
}

int main(){
    int ca = 1;
    while(true){
        scanf("%d%Lf",&n,&d); 
        if(n==0) break;
        
        bool can = true;

        for(int i=0; i<n; i++){
            long double x,y; scanf("%Lf%Lf",&x,&y);
            if(d < y) { can = false; continue; }
            a[i].first = -sqrt(d*d - y*y) + x;
            a[i].second = sqrt(d*d - y*y) + x;
        }  
        
        printf("Case %d: %d\n", ca, (can)? solve() : -1);
        ca++;
    }

    return 0;
}
