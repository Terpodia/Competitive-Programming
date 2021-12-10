#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long;

const int MAXN = 31;

int N; ll a[MAXN][MAXN];
unordered_map<int, ll> dp;

ll solve(int msk){
    if(msk == (1<<N)-1) return 0;

    if(dp.find(msk) != dp.end()) return dp[msk];

  	int i=0;
  	while(msk & (1<<i)) i++;

    int pmsk = msk;
  
    msk |= (1<<i);
    ll ret = 0;
    for(int j=i+1; j<N; j++){
        if((msk & (1<<j)) == 0){
            int nmsk = (msk | (1<<j));
            ret = max(ret, a[i][j] + solve(nmsk));
        }
    }

    return dp[pmsk] = ret;
}

int main(){
    scanf("%d",&N);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%lld",&a[i][j]);

    printf("%lld\n", solve(0));

    return 0;
}
