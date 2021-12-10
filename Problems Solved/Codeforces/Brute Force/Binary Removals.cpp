#include <iostream>
using namespace std;

string s;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve(){
    for(int k=0; k <= (int)s.size(); k++){
        bool f1, f2; f1 = f2 = true;
        
        int cnt=0;

        for(int i=k-1; i>=0; i--){
            if(s[i] == '1'){
                if(cnt>=1){f1=false; break;}
                cnt++;
            } 
            else cnt=0;
        }
        
        cnt=0;

        for(int i=k; i < (int)s.size(); i++){
            if(s[i] == '0'){
                if(cnt>=1){f2=false; break;}
                else cnt++;
            }
            else cnt=0;
        }

        if(f1 && f2){
            printf("YES\n");
            return;
        }
    } 

    printf("NO\n");
}

int main(){
    int t; cin >> t;

    while(t--){
        cin >> s;
        solve();
    }

    return 0;
}
