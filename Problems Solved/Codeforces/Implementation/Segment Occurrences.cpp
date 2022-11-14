#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n,m,q;
  cin>>n>>m>>q;
  string s, t;
  cin>>s>>t;

  vector<int> pos;
  for(int i=0; i<n; i++){
    bool can=true;
    for(int j=0; j<m; j++){
      if(i+j >= n){can=false;break;}
      can &= s[i+j] == t[j];
    }
    if(can) pos.push_back(i);
  } 
  while(q--){
    int l,r;
    cin>>l>>r;
    l--, r--;
    int ans=0;
    for(int i : pos){
      if(i >= l && i + m - 1 <= r) ans++;
    }
    cout<<ans<<"\n";
  }
  return 0;
}

