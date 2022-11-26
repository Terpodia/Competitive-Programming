#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

int main(){
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin>>s;

  vector<int> w, o;
  for(int i=0; i<sz(s); i++){
    if(s[i] == 'v' && i < (int)s.size()-1 && s[i+1] == 'v')
      w.push_back(i);
    else if(s[i] == 'o')
      o.push_back(i);
  }

  ll ans=0;
  for(int i=0; i<sz(o); i++){
    auto it1 = lower_bound(all(w), o[i]);
    if(it1 == w.begin()) continue;
    it1--;

    auto it2 = upper_bound(all(w), o[i]);
    if(it2 == w.end()) break;

    ans += (ll)(distance(w.begin(), it1) + 1) * 
           (ll)(distance(it2, w.end()));
  }
  cout<<ans<<"\n";
  return 0;
}

