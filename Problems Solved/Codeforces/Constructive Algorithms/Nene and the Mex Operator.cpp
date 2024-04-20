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

vector<pair<int,int>> op;
int dp[20], n, a[20];

void construct(int k, int l){
  if(k == 1){
    op.pb({l, l});
    return;
  }
  construct(k-1, l);
  for(int i=k-2; i>0; i--){
    op.pb({l, l+i-1});
    construct(i, l);
  }
  op.pb({l, l+k-1});
  return;
}

int solve(int i){
  if(i == n) return dp[n] = 0;
  int& ret = dp[i];
  if(ret != -1) return ret;
  ret = solve(i+1) + a[i];
  for(int j=i; j<n; j++){
    ret = max(ret, solve(j+1) + (j-i+1) * (j-i+1));
  }
  return ret;
}

void reconstruct(int i){
  if(i == n) return;
  int k=i, cur=a[i]+dp[i+1]; 
  bool flag=true;
  for(int j=i; j<n; j++){
    if(cur < dp[j+1] + (j-i+1) * (j-i+1)){
      flag=false;
      cur = dp[j+1] + (j-i+1) * (j-i+1);
      k = j;
    }
  }
  if(!flag){ 
    op.pb({i+1,k+1});
    for(int j=i; j<=k; j++){
      if(a[j] == 0){
        op.pb({i+1,k+1});
        break;
      }
    }
    construct(k-i+1, i+1);
  }
  reconstruct(k+1);
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i];

  memset(dp, -1, sizeof(dp));

  int s = solve(0);
  reconstruct(0);
  cout << s << " ";
  cout << SZ(op) << "\n";
  for(auto & [l,r] : op) cout << l << " " << r << "\n";
  return 0;
}
