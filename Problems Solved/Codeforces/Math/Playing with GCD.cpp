#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int b[n+1];
    for(int i=0; i<=n; i++) b[i]=1;

    for(int i=0; i<n; i++){
      b[i] *= a[i] / __gcd(a[i], b[i]);
      b[i+1] *= a[i] / __gcd(a[i], b[i+1]);
    }

    bool can=true;
    for(int i=0; i<n; i++) can &= (a[i] == __gcd(b[i], b[i+1]));
    (can) ? cout<<"YES\n" : cout<<"NO\n";
  }
  return 0;
}

