#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

set<string> ans;
string s, a;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve(int msk){
    if(sz(a) == sz(s)){
        ans.insert(a);
        return;
    }

    for(int i=0; i<sz(s); i++){
        int aux = msk & (1<<i);
        if(aux == 0){
            int nmsk = msk | (1<<i);
            a += s[i];
            solve(nmsk);
            a.pop_back();
        }
    } 
}

int main(){
    fastIO();
    cin >> s; 
    
    solve(0);
    
    cout << sz(ans) << "\n";
    for(auto it=ans.begin(); it!=ans.end(); it++)
        cout << *it << "\n";

    return 0;
}
