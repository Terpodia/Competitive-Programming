#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int a,b,c,m;
vector<ll> v1, v2;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr); 
    cin.tie(nullptr);
}

void solve(){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int i=0, j=0;
    
    int cnt=0; ll value=0;

    for(i=0; i < (int)v1.size(); i++){
        if(a==0) break;
        value += v1[i]; cnt++;
        a--;
    }

    for(j=0; j < (int)v2.size(); j++){
        if(b==0) break;
        value += v2[j]; cnt++;
        b--;
    }

    while((i < (int) v1.size() || j < (int) v2.size()) && c > 0){
        cnt++;
        if(i>=(int)v1.size()){
            value += v2[j]; j++; c--;
        }
        else if(j>=(int)v2.size()){
            value += v1[i]; i++; c--;
        }
        else{
            value += min(v1[i], v2[j]); c--;
            (min(v1[i], v2[j]) == v1[i])? i++ : j++;
        }
    }

    cout << cnt << " " << value << "\n";
}

int main(){
    fastIO();

    cin >> a >> b >> c;
    cin >> m;
    for(int i=0; i<m; i++){
        ll value; string type;
        cin >> value >> type;
        (type == "USB")? v1.push_back(value) : v2.push_back(value);
    }

    solve();

    return 0;
}
