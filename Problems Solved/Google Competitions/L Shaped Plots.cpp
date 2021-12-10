#include <iostream>
#include <vector>
using namespace std;

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MAXN = 1e3;
int R, C, a[MAXN][MAXN];

int f(pair<int,int> p, int dir1, int dir2){
    int cnt1=1, cnt2=1, ret=0;

    if(a[p.first][p.second] == 0) return 0;
    
    for(int i=p.first+dir2; i < R && i >= 0; i += dir2){ 
        if(a[i][p.second] == 0) break;
        cnt1++; cnt2=1;

        for(int j=p.second+dir1; j<C && j>=0; j+=dir1){
            if(a[i][j] == 0) break;
            cnt2++;     
        }
        if(cnt2 >= cnt1*2) ret++;
    }
    
    cnt1 = cnt2 = 1;

    for(int j=p.second+dir1; j < C && j >= 0; j += dir1){ 
        if(a[p.first][j] == 0) break;
        cnt1++; cnt2=1;

        for(int i=p.first+dir2; i<R && i>=0; i+=dir2){
            if(a[i][j] == 0) break;
            cnt2++;     
        }
        if(cnt2 >= cnt1*2) ret++;
    }

    return ret;
}

int solve(){
    int ans=0;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            ans += f({i, j}, 1, 1);
            ans += f({i, j}, 1, -1);
            ans += f({i, j}, -1, 1);
            ans += f({i, j}, -1, -1);
        }
    }

    return ans;
}

int main(){
    int t, x=1;
    cin >> t;

    while(t--){
        cin >> R >> C;        
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                cin >> a[i][j];

        int y = solve();
        cout << "Case #" << x << ": " << y << "\n"; 
        x++;
    }

    return 0;
}
