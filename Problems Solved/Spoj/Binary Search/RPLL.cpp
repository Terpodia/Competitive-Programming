#include <algorithm>
#include <iostream>
using namespace std;
 
#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long int ll;
typedef pair<ll, ll> ii;
 
struct ship {
  string dir;
  ll x;
  ll y;
  ll v;
};
 
ship ships[3];
const ll MAXTIME = 1e9;
 
bool P(ll time, ll max_area) {
  ll area;
  ii positions[3];
  char d;
 
  forr(i, 0, 3) {
    d = ships[i].dir[0];
 
    switch (d) {
    case 'n':
      positions[i].first = ships[i].x;
      positions[i].second = (ships[i].y + (ships[i].v * time));
      break;
 
    case 's':
      positions[i].first = ships[i].x;
      positions[i].second = ships[i].y - (ships[i].v * time);
      break;
 
    case 'e':
      positions[i].first = ships[i].x + (ships[i].v * time);
      positions[i].second = ships[i].y;
      break;
 
    case 'w':
      positions[i].first = ships[i].x - (ships[i].v * time);
      positions[i].second = ships[i].y;
      break;
    }
  }
 
  area = (positions[0].first * (positions[1].second - positions[2].second) +
          positions[1].first * (positions[2].second - positions[0].second) +
          positions[2].first * (positions[0].second - positions[1].second)) /
         2;
 
  area = abs(area);
 
  return (area <= max_area);
}
 
ll bs(ll max_area) {
  ll lo = -1, hi = MAXTIME, mid, answer = 0;
 
  while (hi - lo > 1) {
    mid = (hi + lo) / 2;
 
    if (P(mid, max_area)) {
      answer = max(mid, answer);
      lo = mid;
    } else
      hi = mid;
  }
 
  return answer;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int T;
  ll max_area;
 
  cin >> T;
  forr(k, 1, T + 1) {
    cin >> max_area;
    forr(i, 0, 3) cin >> ships[i].x >> ships[i].y >> ships[i].dir >> ships[i].v;
 
    cout << "Scenario #" << k << ": " << bs(max_area) << "\n";
  }
 
  return 0;
} 

