#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin>>tt;
  while(tt--){
    ll h, p;
    cin>>h>>p;

    ll ans=0, cnt=0;

    for(ll i=0; i<h; i++){
      ll curr = (1LL << i) - cnt;
      if(curr < p) ans++, cnt=0;
      else{
        ans += curr / p;
        ans += (curr % p != 0) ? 1 : 0;
        cnt = (curr % p == 0) ? 0 : p - (curr % p);
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}

