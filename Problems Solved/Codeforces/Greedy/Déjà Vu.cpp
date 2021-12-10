#include <iostream>
using namespace std;

void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

bool isPalindrome(string s){
    int a=0, b=s.size()-1;

    while(a < b){
        if(s[a] != s[b]) return false;
        a++; b--;
    }
    return true;
}

int main(){
    fastIO();
    int t; cin >> t;

    while(t--){
        string s; cin >> s;
        bool can = false;

        for(char c : s) if(c != 'a') can = true;
        
        if(!can) cout << "NO\n";
        else{
            cout << "YES\n";
            if(!isPalindrome("a" + s))
                cout << "a" + s << "\n";
            else
                cout << s + "a" << "\n";
        }
    }

    return 0;
}
