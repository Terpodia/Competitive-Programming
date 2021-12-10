#include <iostream>
#include <algorithm>
using namespace std;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

int main(){
    fastIO();
    int t; cin >> t;

    while(t--){
        int n; 
        cin >> n; int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        
        int ans = 0;

        for(int i=0; i<n; i++){
            int level = a[i];
            bool f = false;
            for(int j = 0; j < n; j++){
                if(a[j] < level){f = true; break;}
            }
            if(f) ans++;
        }
        cout << ans << "\n";
    }


    return 0;
}
