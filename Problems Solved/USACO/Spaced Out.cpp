#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 1004;
int N, a[MAXN][MAXN];

int maxS1(){
    vector<int> s1(N, 0), s2(N, 0);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j+=2)
           s1[i] += a[i][j]; 
        
    
    for(int i = 0; i < N; i++)
        for(int j = 1; j < N; j+=2)
            s2[i] += a[i][j];
        
    int ret = 0;

    for(int i = 0; i < N; i++)
        ret += max(s1[i], s2[i]);
    
    return ret;
}

int maxS2(){
    vector<vector<int>> w(2, vector<int>(N, 0));
    
    for(int i = 0; i < N; i+=2)
        for(int j = 0; j < N; j++)
            w[0][j] += a[i][j];
        
    for(int i = 1; i < N; i+=2)
        for(int j = 0; j < N; j++)
            w[1][j] += a[i][j];
    
    int ret = 0;
    
    for(int i = 0; i < N; i++)
        ret += max(w[0][i], w[1][i]);
    

    return ret;
}

void solve(){
    printf("%d\n",max(maxS1(), maxS2()));
}

int main(){
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d",&a[i][j]);

    solve();

    return 0;
}
