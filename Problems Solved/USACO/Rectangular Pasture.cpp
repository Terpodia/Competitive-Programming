#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

struct cow{
    int x;
    int y;
};

const int MAXN = 2500;
cow c[MAXN];
ll prefix[MAXN+2][MAXN+2];

int N;

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

bool cmp1(cow a, cow b){
    return a.x < b.x;
}

bool cmp2(cow a, cow b){
    return a.y < b.y;
}

ll rSum(int a, int b, int A, int B){
    return prefix[A][B] - prefix[a-1][B] - prefix[A][b-1] + prefix[a-1][b-1];
}

int main(){
    fastIO();

    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> c[i].x >> c[i].y;
    
    sort(c, c+N, cmp1);
    for(int i = 0; i < N; i++) c[i].x = i+1;
    sort(c, c+N, cmp2);
    for(int i = 0; i < N; i++) c[i].y = i+1;

    for(int i = 0; i <= MAXN; i++) prefix[0][i] = 0;
    for(int i = 0; i <= MAXN; i++) prefix[i][0] = 0;
    
    for(int i = 0; i < N; i++) prefix[c[i].x][c[i].y] = 1;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
    
    ll ans = 1;

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            ll min_x = min(c[i].x, c[j].x);
            ll max_x = max(c[i].x, c[j].x);
            ll min_y = min(c[i].y, c[j].y);
            ll max_y = max(c[i].y, c[j].y);
            ans += rSum(1, min_y, min_x, max_y) * rSum(max_x, min_y, N, max_y);
        }
    }

    cout << ans << "\n";

    return 0;
}
