#include <iostream>
using namespace std;
 
const int INF = 1e9;
 
int n;
string a, b;
 
void fastIO() { cin.tie(0)->sync_with_stdio(0); }
 
int calc(string s) {
  int cnt=0, num1=0, num2=0;
 
  for (int i=0; i<n; i++) {
    if (s[i] == '1' && b[i] == '0') cnt++;
    if (s[i] == '1') num1++;
    if (b[i] == '1') num2++;
  }
 
  if (num1 != num2) return INF;
 
  return cnt * 2;
}
 
int f(char x) {
  string s = a;
  if (x == 'x') 
    return calc(s);
 
  int j=-1; 
 
  for (int i=0; i<n; i++)
    if (a[i] == '1' && b[i] == x) j = i;
 
  if (j == -1) return INF;
 
  for (int i=0; i<n; i++) if (i != j)
    s[i] = (s[i] == '1') ? '0' : '1'; 
 
  return calc(s);
}
 
void solve() {
  int ans = min(f('x'), min(f('0')+1, f('1')+1)); 
  if (ans == INF) cout << "-1\n";
  else cout << ans << "\n";
}
 
int main() {
  fastIO();
  int t; cin >> t;
 
  while (t--) {
    cin >> n >> a >> b;
    solve();
  }
 
 
  return 0;
}

