#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin>>tt;
  while(tt--){
    int n,W;
    cin>>n>>W;
    int w[n];
    for(int i=0; i<n; i++) cin>>w[i];

    multiset<int> m;
    for(int i=0; i<n; i++) m.insert(w[i]);

    int curr = W, ans = 1;

    while(!m.empty()){
      auto it = m.upper_bound(curr);
      if(it == m.begin()) ans++, curr = W - curr;
      else{
        it--;
        curr -= *it;
        m.erase(it);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}

