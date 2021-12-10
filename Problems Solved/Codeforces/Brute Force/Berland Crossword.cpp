/* 
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <iostream>
#include <vector>
using namespace std;

int n; vector<int> m(4);
bool can = false;

void solve(int i, vector<int> p, vector<bool> v = vector<bool>(4,false)) {
    if(i == 4) { 
        for(int j=0; j<4; j++) if(p[j] < 0) return;
        can = true;
        return;
    }

    if(p[i] < 0) return;
    if(p[i] <= n-2) { solve(i+1, p, v); return; }

    if(p[i] == n) {
        p[(i+1)%4]--; p[(i-1+4)%4]--; p[i]-=2;
        v[(i+1)%4] = v[i] = true;
        solve(i+1, p, v);
        return;
    }
    
    p[i]--;
    if(!v[(i+1)%4]) { v[(i+1)%4] = true; p[(i+1)%4]--; solve(i+1, p, v); v[(i+1)%4] = false; p[(i+1)%4]++; }
    if(!v[i]) { v[i] = true; p[(i-1+4)%4]--; solve(i+1, p, v); p[(i-1+4)%4]++; v[i] = false; }
}

int main() {
    int t; scanf("%d",&t);

    while(t--) {
        scanf("%d %d %d %d %d", &n, &m[0], &m[1], &m[2], &m[3]); 

        solve(0, m);
        
        if(!can) puts("NO");
        else puts("YES");

        can = false;
    }

    return 0;
}

