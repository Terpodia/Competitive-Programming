#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin>>n;
  ll a[n];
  for(int i=0; i<n; i++) cin>>a[i];

  ll ans = (ll)1e18;

  for(int i=0; i<n; i++){
    ll cnt=0, prev=0;
    for(int j=i-1; j>=0; j--){
      ll k = (prev / a[j]) + 1;
      cnt += k;
      prev = k * a[j];
    }
    prev=0;
    for(int j=i+1; j<n; j++){
      ll k = (prev / a[j]) + 1;
      cnt += k;
      prev = k * a[j];
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<"\n";
  return 0;
}

