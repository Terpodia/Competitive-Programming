#include <iostream>
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
        bool f = false;
        int n; cin >> n;
        int a1, a2, a3;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(n - i*7 - j*5 < 0 || (n-i*7-j*5)%3 != 0)
                    continue;
                else{
                    f = true;
                    a1 = (n-i*7-j*5)/3; 
                    a2 = j;
                    a3 = i;
                }
                if(f) break;
            }
            if(f) break;
        }
        if(f){
            cout << a1 << " " << a2 << " " << a3 << "\n";
        }
        else cout << "-1\n";
    }

    return 0;
}
