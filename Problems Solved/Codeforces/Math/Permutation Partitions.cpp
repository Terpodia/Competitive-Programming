#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

typedef long long ll;

const ll MOD = 998244353;

int main(){
  int n, k; 
  scanf("%d%d",&n,&k);
  pair<int,int> p[n];
  for(int i=0; i<n; i++){ 
    scanf("%d",&p[i].fst);
    p[i].snd = i;
  }

  sort(p,p+n);

  ll s=0, cnt=1;
  set<int> ss;

  for(int i=n-1; i>=n-k; i--){
    s += p[i].fst;
    ss.insert(p[i].snd);
  }
  for(int i=n-1; i>=n-k; i--){
    ll a=1, b=1;

    auto it1 = ss.lower_bound(p[i].snd);
    if(it1 != ss.begin()){
      it1--;
      a = (ll)(p[i].snd - *it1);
      ss.insert(*it1+1);
    }
    auto it2 = ss.upper_bound(p[i].snd);
    if(it2 != ss.end()){
      b = (ll)(*it2 - p[i].snd);
      ss.insert(*it2-1);
    }
    cnt *= (a * b) % MOD;
    cnt %= MOD;
  }
  printf("%lld %lld\n", s, cnt);
  return 0;
}
