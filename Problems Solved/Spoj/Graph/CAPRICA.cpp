#include <bits/stdc++.h>
using namespace std;
 
#define forr(i, x, n) for(int i = (x); i < (int)(n); i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
 
int Dijkstra(vvi &G, vvi &W, int start, vi &Y){
    priority_queue<ii> Q;
    vi dist(G.size(), 1e9);
    dist[start] = 0;
    Q.push({-0, start});
    int v, u, w, p, answer = 1e9;
    ii arc;
 
    while(!Q.empty()){
        arc = Q.top();
        Q.pop();
        p = arc.first;
        v = arc.second;
 
        if(dist[v] != -p) continue;
        forr(i, 0, G[v].size()){
            u = G[v][i];
            w = W[v][i];
            if(w - p < dist[u]){
                dist[u] = w - p;
                Q.push({p - w, u});
            }
        }
    }
    forr(i, 0, Y.size()) answer = min(answer, dist[Y[i]]);
    return answer;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, M, A, B, u, v, w;
 
    do{
        int answer = 1e9;
        cin >> N >> M >> A >> B;
        if(N == 0 && M == 0 && A == 0 && B == 0) break;
 
        vi X(A), Y(B);
        forr(i, 0, A) cin >> X[i];
        forr(i, 0, B) cin >> Y[i];
 
        vvi G(N), W(N);
        forr(i, 0, M){
            cin >> u >> v >> w;
            G[u].push_back(v);
            G[v].push_back(u);
            W[u].push_back(w);
            W[v].push_back(w);
        }
 
        forr(i, 0, A){
            answer = min(answer, Dijkstra(G, W, X[i], Y));
        }
 
        cout << answer << "\n";
        
    } while (N != 0 || M != 0 || A != 0 || B != 0);
    
 
    return 0;
}

