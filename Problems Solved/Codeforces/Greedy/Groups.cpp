#include <cstdio>
#include <vector>
using namespace std;

#define FOR(i,x,n) for(int i=(x); i<(int)(n); i++)

int aux;

int main() {
    int t; aux=scanf("%d",&t); 
    while(t--) {
        int n; aux=scanf("%d",&n);
        int a[n][5];
        FOR(i,0,n) FOR(j,0,5) aux=scanf("%d",&a[i][j]); 

        bool can=false;

        FOR(d1,0,5) FOR(d2,0,5) if(d1 != d2) {
            int cnt1=0, cnt2=0; 
            vector<bool> sel(n, false); 

            FOR(i,0,n) 
                if(a[i][d1] == 1 && a[i][d2] == 0) cnt1++, sel[i] = true;

            FOR(i,0,n) if(cnt1 < n/2) {
                if(a[i][d1] == 1 && !sel[i]) cnt1++, sel[i] = true;
            }

            FOR(i,0,n) if(cnt2 < n/2) {
                if(a[i][d2] == 1 && !sel[i]) cnt2++, sel[i] = true;
            }

            if(cnt1 == n/2 && cnt2 == n/2) can = true;
        }

        (!can)? puts("NO") : puts("YES");
    }

    return 0;
}

