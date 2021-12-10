#include<bits/stdc++.h>
using namespace std;
 
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef unordered_map<string, int> umap;
 
int Dijsktra(vvi &G, vvi &W, int begin, int end){
    priority_queue<ii> Q;
    Q.push({-0, begin});
    vector<bool> visited(G.size(), false);
    int u, v, w, k;
    ii p;
 
    while(!Q.empty()){
        p = Q.top();
        Q.pop();
        k = p.first;
        v = p.second;
 
        if(v == end) return -k;
 
        if(!visited[v]){
            visited[v] = true;
            forr(i, 0, G[v].size()){
                u = G[v][i];
                w = W[v][i];
                Q.push({k-w, u});
            }
        }
    }
 
    return -1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s, n, p, u, w, r, begin, end;
    string city, source, destination;
    umap names;
    cin >> s;
 
    forr(i, 0, s){
        cin >> n;
        vvi G(n), W(n);
 
        forr(j, 0, n){
            cin >> city;
            names[city] = j;
            cin >> p;
 
            forr(k, 0, p){
                cin >> u >> w;
                G[j].push_back(u-1);
                W[j].push_back(w);
            }
        }
        cin >> r;
 
        forr(j, 0, r){
            cin >> source >> destination;
            begin = names[source];
            end = names[destination];
 
            cout << Dijsktra(G, W, begin, end) << "\n";
        }
    }
 
    return 0;
} 

