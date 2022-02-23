#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define sz(x) (int)x.size()

string n;
int dp[1<<13][15];

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int solve(int msk, int i) {
    if(i == sz(n)) {
        for(int j=sz(n); j<=15; j++)
            if(msk & (1<<j)) return 0;

        return 1;
    }

    int& ret = dp[msk][i];

    if(ret != -1) return ret;

    ret=0;

    for(int j=0; j<10; j++) {
        for(int z=0; z<10; z++) {
            int y = (msk & (1<<i))? j+1 : j;
            int nmsk = (y + z >= 10)? (msk | (1<<(i+2))) : msk;
            
            if((y+z)%10 == n[i]-'0') ret += solve(nmsk, i+1); 
        } 
    }

    return ret;
}

int main() {
    fastIO();

    int t;
    cin >> t;

    while(t--) {
        cin >> n; 
        reverse(n.begin(), n.end());
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) - 2 << "\n";
    }

    return 0;
}

