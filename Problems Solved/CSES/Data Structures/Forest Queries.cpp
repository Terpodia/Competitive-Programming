#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

vvl psum2D(const vvl &a){
    int n = (int)a.size();
    vvl prefix2D(n+1, vl(n+1, 0));
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            prefix2D[i][j] = prefix2D[i-1][j] + prefix2D[i][j-1] -
                             prefix2D[i-1][j-1] + a[i-1][j-1];

        }
    }

    return prefix2D;
}

int main(){
    fastIO();
    int n, q; cin >> n >> q;
    vvl a(n, vl(n));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin >> c;
            if(c == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    vvl prefix2D = psum2D(a);
    while(q--){
        int y1, y2, x1, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        ll ans = prefix2D[y2][x2] - prefix2D[y1-1][x2] - prefix2D[y2][x1-1] + prefix2D[y1-1][x1-1];
        cout << ans << "\n";
    }

    return 0;
}
