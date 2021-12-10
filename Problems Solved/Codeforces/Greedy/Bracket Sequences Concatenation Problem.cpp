#include <iostream>
#include <cstring>
using namespace std;
 
typedef long long ll;
 
const int MAXN = 3e5, INF = 1e9;
 
int n; string s[MAXN];
 
ll isRegular(string& a, bool flag=false) {
  int cnt=0;
  for (char c : a) {
    (c == '(') ? cnt++ : cnt--;
    if (!flag && cnt < 0) return cnt;
  }
  return cnt;
}
 
bool valid(string& a) {
    int cnt=0;
    int lo=INF;
    for (char c : a) {
        (c == '(') ? cnt++ : cnt--;
        lo = min(lo, cnt);
    }
    if (lo >= 0) return true;

    return lo == isRegular(a, true);
}
 
ll checkPositive(string& a) {
  return (!valid(a)) ? -1 : isRegular(a);
}
 
ll checkNegative(string& a) {
  return (!valid(a) || isRegular(a,true) >= 0) ? -1 : -isRegular(a,true);
}
 
ll solve() {
  ll ret=0;
  ll cnt_regular=0;
 
  for (int i=0; i<n; i++) if (isRegular(s[i]) == 0)
    cnt_regular++;
 
  ret += cnt_regular * cnt_regular;
 
  ll t[MAXN+1][2]; memset(t, 0, sizeof(t));
 
  for (int i=0; i<n; i++) {
    ll res = checkPositive(s[i]);
    if (res != -1) t[res][0]++;
    res = checkNegative(s[i]);
    if (res != -1) t[res][1]++;
  }
 
  for (int i=0; i<=MAXN; i++) {
    ret += t[i][0] * t[i][1];
  }
 
  return ret;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i=0; i<n; i++)
    cin >> s[i];
 
  cout << solve() << "\n";
 
  return 0;
}
