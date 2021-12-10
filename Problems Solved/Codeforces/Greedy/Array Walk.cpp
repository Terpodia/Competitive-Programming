#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;

int n, k, z, a[MAXN], pref[MAXN+1];

int solve(int i) {
    int mvs = i, back_mvs = 0, ret=pref[i+1];
    bool turn = false;

    while(mvs < k && back_mvs < z) {
        if(!turn) {
            ret += a[i+1]; mvs++; 
        }     
        else {
            ret += a[i]; mvs++; back_mvs++;
        }
        turn = !turn;
    }

    int curr = (!turn)? i : i+1;

    ret += pref[curr+(k-mvs)+1] - pref[curr+1];

    return ret;
}

int main() {
    int t; scanf("%d",&t);

    while(t--) {
        scanf("%d%d%d",&n,&k,&z);
        for(int i=0; i<n; i++) scanf("%d",a+i);

        pref[0] = 0;
        for(int i=1; i<=n; i++) 
            pref[i] = pref[i-1] + a[i-1];

        int ans = pref[k+1];

        for(int i=0; i<n-1; i++) {
            if(i > k) break;
            ans = max(ans, solve(i));        
        }

        printf("%d\n", ans);
    }

    return 0;
}

