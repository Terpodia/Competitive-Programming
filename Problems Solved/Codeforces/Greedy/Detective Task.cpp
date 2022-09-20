#include <bits/stdc++.h>
using namespace std;

string s;

bool check(){
  bool first_zero=false;
  for(char c : s){
    if(c=='0') first_zero=true;
    if(c=='1' && first_zero) return true;
  }
  return false;
}

int solve(){
  if(check()) return 1;
  int n = (int)s.size();
  if(s[0]=='0' || s[n-1]=='1') return 1;
  /*
  bool ok=true;
  for(char c : s) ok &= c=='?';
  if(ok) return n;
  */

  int lsOne=0, fstZero=n-1;
  for(int i=0; i<n; i++){
    if(s[i]=='1') lsOne=i;
    else if(s[i]=='0'){fstZero=i;break;}
  }
  
  return fstZero - lsOne + 1;
}

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin>>tt;
  while(tt--){
    cin>>s;
    cout<<solve()<<"\n";
  }
  return 0;
}

