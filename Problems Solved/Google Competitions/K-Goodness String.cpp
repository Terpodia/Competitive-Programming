#include <iostream>
using namespace std;

int N, K;
string s;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int solve(){
    int i=0, j=N-1, ans=0, sum=0; 
    
    while(i < j){
        if(s[i] != s[j]) sum++;
        i++; j--;
    }

    i=0; j=N-1;
    while(i < j){
        if(sum == K) break;
        else if(sum < K && s[i] == s[j]){ans++; sum++;}
        else if(sum > K && s[i] != s[j]){sum--; ans++;}

        i++; j--;
    }

    return ans; 
}

int main(){
    fastIO();
    int t, x=1; cin >> t;

    while(t--){
        cin >> N >> K;
        cin >> s;
        cout << "Case #" << x << ": " << solve() << "\n";    
        x++;
    }

    return 0;
}
