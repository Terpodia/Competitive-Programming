#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;
int N, M;

char grid[MAXN][MAXM];
vector<vector<bool>> vis(MAXN, vector<bool>(MAXM, false));

int xd[4] = {1, -1, 0, 0}, yd[4] = {0, 0, 1, -1};

void fastIO(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void floodFill(int i, int j){
    if(i < 0 || j < 0 || i >= N || j >= M || grid[i][j] == '#' || vis[i][j])
        return;

    vis[i][j] = true;
    for(int c=0; c<4; c++) floodFill(i+yd[c], j+xd[c]);
}

int main(){
    fastIO();
    cin >> N >> M; 

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> grid[i][j];
    
    int ans = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!vis[i][j] && grid[i][j] != '#'){
                floodFill(i, j);
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
