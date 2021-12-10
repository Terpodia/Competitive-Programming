#include <iostream>
using namespace std;

int px, py;
string s;

void solve(){
    int x = 0, y = 0;
    int cnt[4]; for(int i = 0; i < 4; i++) cnt[i] = 0;

    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == 'U'){
            cnt[0]++;
            y++;
        }
        else if(s[i] == 'D'){
            cnt[1]++;
            y--;
        }
        else if(s[i] == 'R'){
            cnt[2]++;
            x++;
        }
        else{
            cnt[3]++;
            x--;
        }
    }
    if(x != px){
        if(x > px){
            if(x - cnt[2] > px){
                cout << "NO\n";
                return;
            }
        }
        else if(x < px){
            if(x + cnt[3] < px){
                cout << "NO\n";
                return;
            }
        }
    }
    if(y != py){
        if(y > py){
            if(y - cnt[0] > py){
                cout << "NO\n";
                return;
            }
        }
        else if(y < py){
            if(y + cnt[1] < py){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        cin >> px >> py;
        cin >> s;
        solve();
    }


    return 0;
}
