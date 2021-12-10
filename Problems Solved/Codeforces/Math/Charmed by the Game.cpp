#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

#define sz(x) (int)x.size()

int a, b;

void solve() {
    vector<int> ans;
    int x, y;

    x = (a+b+1)/2, y = (a+b)/2;
    for(int i=0; i<=x; i++) {
        if(b < i) continue;
        if(y < b-i) continue;
        ans.push_back(i + y - (b-i)); 
    }
    
    x = (a+b)/2, y = (a+b+1)/2;
    for(int i=0; i<=x; i++) {
        if(b < i) continue;
        if(y < b-i) continue;
        ans.push_back(i + y - (b-i)); 
    }

    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));

    printf("%d\n", sz(ans));
    for(int i=0; i<sz(ans); i++)
        printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&a,&b); 
        solve();
    } 

    return 0;
}

