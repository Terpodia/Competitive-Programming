#include <bits/stdc++.h>
using namespace std;
 
#define forr(i, x, n) for(int i = (x); i < (int)(n); i++)
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<vector<ii>> vvii;
 
bool Dijkstra(vvi &G, vvii &W, ll init_time, ll S, ll E){
    priority_queue<ii> Q;
    vi dist(G.size(), 1e12);
    Q.push({-init_time, S});
    ii arc;
    ll p, v, u, w1, w2;
 
    while(!Q.empty()){
        arc = Q.top();
        Q.pop();
        p = arc.first;
        v = arc.second;
 
        forr(i, 0, G[v].size()){
            u = G[v][i];
            w1 = W[v][i].first;
            w2 = W[v][i].second + p;
            if(w2 > w1 && w1 - p < dist[u]){
                Q.push({p - w1, u});
                dist[u] = w1 - p;
            }
        }
    }
    if(dist[E] == 1e12) return false;
    return true;
}
 
void bs(vvi &G, vvii &W, ll S, ll E, ll M){
    ll lo = 0, hi = M+1, mid, answer = 0;
    while(hi - lo > 1){
        mid = (hi + lo)/2;
        if(Dijkstra(G, W, mid, S, E)){
            answer = max(answer, mid);
            lo = mid;
        }
        else hi = mid;
    }
 
    if(answer == 0) cout << "Primo can't escape\n";
    else cout << "Primo can escape in " << answer << " minute(s)\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll T, N, R, M, u, v, w, f, S, E;
    string fans_time;
    cin >> T;
 
    forr(i, 1, T+1){
        cin >> N >> R >> M;
        vvi G(N);
        vvii W(N);
        forr(j, 0, R){
            cin >> u >> v >> w >> fans_time;
            G[u].push_back(v);
            G[v].push_back(u);
            if(fans_time == "INF"){
                W[u].push_back({w, 1e15});
                W[v].push_back({w, 1e15});
            }
            else{
                W[u].push_back({w, stoi(fans_time)});
                W[v].push_back({w, stoi(fans_time)});
            } 
        }
        cin >> S >> E;
        cout << "Case #" << i << ": ";  
        bs(G, W, S, E, M);
    }
 
    return 0;
} 

