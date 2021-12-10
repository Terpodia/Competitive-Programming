#include <bits/stdc++.h>
using namespace std;
 
#define forr(i, x, n) for(int i = (x); i < (int)(n); i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
 
bool comp(ii a, ii b){
    if(a.first != b.first) return (a.first < b.first);
    return (a.second < b.second);
}
 
void topoSort(vvi &G){
    vi degrees(G.size(), 0);
    vector<ii> answer;
    queue<ii> Q;
    ii p;
 
    forr(i, 0, G.size())
        forr(j, 0, G[i].size())
            degrees[G[i][j]]++;
 
    forr(i, 0, degrees.size()) if(degrees[i] == 0) Q.push({1, i});
 
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        answer.push_back(p);
 
        forr(i, 0, G[p.second].size()) if(--degrees[G[p.second][i]] == 0) Q.push({p.first+1, G[p.second][i]});
    }
 
    sort(answer.begin(), answer.end(), comp);
    forr(i, 0, answer.size()) cout << answer[i].first << " " << answer[i].second << "\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, n, r, v, u;
    cin >> T;
 
    forr(k, 1, T+1){
        cin >> n >> r;
        vvi G(n);
 
        forr(i, 0, r){
            cin >> v >> u;
            G[u].push_back(v);
        }
        cout << "Scenario #" << k << ":\n";
        topoSort(G);
    }
    
    return 0;
} 

