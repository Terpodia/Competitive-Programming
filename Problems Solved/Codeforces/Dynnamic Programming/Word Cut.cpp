#include <iostream>
#include <cstring>
using namespace std;
 
typedef long long ll;
 
const int MAXN = 1000;
const ll MOD = 1e9+7;
 
void fastIO() { cin.tie(0)->sync_with_stdio(0); }
 
int main() {
    fastIO();
    string a,b; cin>>a>>b;
    int n=(int)a.size(),k; cin>>k;
    a += a;
 
    ll dp[MAXN];
    memset(dp,0,sizeof(dp));
 
    for(int i=0; i<n; i++) {
        string c="";
        for(int j=0; j<n; j++) c.push_back(a[i+j]);
        dp[i] = (c==b); 
    }
 
    ll s=0;
    for(int j=0; j<n; j++) s+=dp[j];
 
    for(int i=1; i<=k; i++) {
        for(int j=0; j<n; j++) dp[j] = (s-dp[j]+MOD)%MOD; 
        s=0; for(int j=0; j<n; j++) s+=dp[j];
    }
 
    cout << dp[0] << "\n";
 
    return 0;
}

