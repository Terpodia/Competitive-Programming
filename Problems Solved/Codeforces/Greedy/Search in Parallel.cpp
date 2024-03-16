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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    pair<int,int> r[n];
    fore(i,0,n) cin>>r[i].fst;
    fore(i,0,n) r[i].snd=i;
    sort(r,r+n);
    int cnt1=s1, cnt2=s2;
    
    bool ans[n];
    fore(i,0,n) ans[i]=false;
    for(int i=n-1; i>=0; i--){
      if(cnt1 < cnt2) cnt1 += s1, ans[i]=true;
      else cnt2 += s2;
    }
    vector<int> a, b;
    fore(i,0,n) if(ans[i]) a.pb(r[i].snd+1);
    fore(i,0,n) if(!ans[i]) b.pb(r[i].snd+1);
    reverse(all(a)); reverse(all(b));
    cout << SZ(a) << " ";
    fore(i,0,SZ(a)) cout << a[i] << " ";
    cout << "\n";
    cout << SZ(b) << " ";
    fore(i,0,SZ(b)) cout << b[i] << " ";
    cout << "\n";
  }
  return 0;
}
