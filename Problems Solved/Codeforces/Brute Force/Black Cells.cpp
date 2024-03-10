#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i,x,n) for(auto i=(x); i<(n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " " 
#define raya cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tt;
  cin>>tt;
  while(tt--){
    int n, k;
    cin>>n>>k;
    int l[n], r[n], res=0, ans=0;
    fore(i,0,n) cin>>l[i];
    fore(i,0,n) cin>>r[i];

    int cur=0,j=0,pos=0,cnt=0;
    fore(i,0,n){
      j=i; 
      res += l[i]-pos + min(r[i]-l[i], k-cur-1) + 2, pos = min(r[i], l[i]+k-cur-1);
      cur += min(k-cur, r[i]-l[i]+1);
      if(cur==k) break;
    }
    if(cur < k){ cout<<"-1\n"; continue; }
    ans = res;
    fore(i,0,j+1){
      if(r[i]-l[i]==0) cnt++;
    }
    while(j<n && cnt>0){
      if(pos+1 <= r[j]) pos++, cnt--, res--; 
      else {
        j++;
        if(j==n) break;
        cnt--;
        if(r[j]-l[j] == 0) cnt++;
        res+=l[j]-pos, pos=l[j];
      }
      ans = min(ans, res);
    }
    cout << ans << "\n";
  }
  return 0;
}
