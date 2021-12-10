#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll INF = 1e18;

int N, M;

ll solve(vvll& G) {
    ll dist[N+1][N+1][N+1], ret=0;

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            if(i == j) dist[i][j][0] = 0;
            else dist[i][j][0] = G[i][j];
        }

    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                dist[i][j][k] = min(dist[i][j][k-1], dist[i][k][k-1] + dist[k][j][k-1]);
            }
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            for(int k=1; k<=N; k++) {
                if(dist[i][j][k] == INF) continue;
                ret += dist[i][j][k];
            }
        }
    }

    return ret;
}

int main() {
    scanf("%d%d",&N, &M);

    vvll G(N+1, vll(N+1, INF));

    for(int i=0; i<M; i++) {
        int u, v, w; scanf("%d%d%d",&u,&v,&w);
        G[u][v] = w;
    }

    printf("%lld\n", solve(G));

    return 0;
}
