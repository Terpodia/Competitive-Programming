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

const ll INF = 1e15;

ll x1, x2, y1, y2;
int n;
string s;

bool f(ll k){
  ll x3=x1, y3=y1;
  fore(i,0,n){
    if(s[i] == 'U'){
      y3 += k/n;  
      if(i < k%n) y3++;
    }
    if(s[i] == 'D'){
      y3 -= k/n;
      if(i < k%n) y3--;
    }
    if(s[i] == 'R'){
      x3 += k/n;
      if(i < k%n) x3++;
    }
    if(s[i] == 'L'){
      x3 -= k/n;
      if(i < k%n) x3--;
    }
  }
  ll d = abs(x3-x2) + abs(y3-y2);
  return d <= k;
}

void solve(){
  ll l = 0, r = INF;
  while(r>l){
    ll mid = l+(r-l)/2;
    if(f(mid)) r=mid;
    else l=mid+1;
  }
  if(r == INF) cout<<"-1\n";
  else cout<<r<<"\n";
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
  bool flag=true;
  fore(i,1,SZ(s)) flag &= s[i]==s[i-1];
  solve();
  return 0;
}

