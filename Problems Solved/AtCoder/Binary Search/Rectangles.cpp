#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define ALL(x) x.begin(), x.end()

int N;
vector<ii> pt;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int main() {
  fastIO();

  cin >> N;
  pt = vector<ii>(N);
  FOR(i, 0, N) cin >> pt[i].first >> pt[i].second;

  map<int, vector<int>> mp;
  FOR(i, 0, N) mp[pt[i].second].push_back(pt[i].first);

  for (auto it = mp.begin(); it != mp.end(); it++)
    sort(it->second.begin(), it->second.end());

  int ans = 0;

  FOR(i, 0, N) FOR(j, 0, N) {
    if (i == j) continue;

    if (pt[i].first < pt[j].first && pt[i].second > pt[j].second) {
      if (!binary_search(ALL(mp[pt[i].second]), pt[j].first)) continue;
      if (!binary_search(ALL(mp[pt[j].second]), pt[i].first)) continue;
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}
