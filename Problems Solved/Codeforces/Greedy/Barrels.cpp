#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main(){
    fastIO();
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;
        ll a[n]; for(int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n, greater<ll>());
        
        ll lo = a[n-1], hi = a[0];

        for(int i=1; i<n; i++){
            if(k == 0) break;
            if(a[i] == 0) break;
            else{
                hi += a[i];
                lo = 0;
                k--;
            }
        }
        cout << hi-lo << "\n"; 
    }

    return 0;
}
