#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
 
#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
#define forR(i, x, n) for (int i = (x); i > (int)(n); i--)
typedef long double ld;
 
const int MAXN = 50020;
int n;
ld cisterns[MAXN][4];
 
ld P(ld H, ld V) {
  ld vol, h, w, d, b;
 
  for (int i = 0; i < n; i++) {
    b = cisterns[i][0];
    h = cisterns[i][1];
    w = cisterns[i][2];
    d = cisterns[i][3];
 
    if (b <= H) {
      if (b + h <= H)
        V -= (h * w * d);
      else
        V -= (w * d * (H - b));
    }
  }
 
  return V;
}
 
ld bs(ld maximo, ld V) {
  ld lo = -1, answer = 0, mid, hi = maximo, volume;
  int counter = 81;
 
  while (counter > 0) {
    mid = (hi + lo) / 2;
    volume = P(mid, V);
 
    if (volume == 0) {
      answer = mid;
      hi = mid;
    }
 
    else if (volume < 0)
      hi = mid;
 
    else {
      answer = max(answer, mid);
      lo = mid;
    }
    counter--;
  }
  return answer;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int k;
  ld max_hi = 0, ans, V, sum;
  cin >> k;
 
  forr(d, 0, k) {
    cin >> n;
 
    forr(i, 0, n) {
      cin >> cisterns[i][0] >> cisterns[i][1] >> cisterns[i][2] >>
          cisterns[i][3];
 
      sum += (cisterns[i][1] * cisterns[i][2] * cisterns[i][3]);
      max_hi = max(max_hi, cisterns[i][0] + cisterns[i][1]);
    }
 
    cin >> V;
 
    if (sum < V)
      cout << "OVERFLOW\n";
 
    else {
      max_hi += 3;
      ans = bs(max_hi, V);
      cout << fixed;
      cout << setprecision(2);
      cout << ans << "\n";
    }
    max_hi = 0;
    sum = 0;
  }
 
  return 0;
} 

