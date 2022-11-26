#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<int, int>, int> passwords;
map<pair<int, int>, int>::iterator itr;

int maximum(int x, int y, int z = 0) {
  int max = x;

  if (y > max) max = y;
  if (z > max) max = z;

  return max;
}

int max_number_of_stones(vector<vector<int> > &floor, int posh, int posw,
                         int &h, int &w) {
  if (posw == -1)
    return 0;

  else if (posw == w)
    return 0;

  else if (posh == 0)
    return floor[posh][posw];

  itr = passwords.find(pair<int, int>(posh, posw));

  if (itr != passwords.end()) {
    return itr->second;
  }

  passwords.insert(make_pair(
      make_pair(posh, posw),
      maximum(
          floor[posh][posw] +
              max_number_of_stones(floor, posh - 1, posw - 1, h, w),
          floor[posh][posw] + max_number_of_stones(floor, posh - 1, posw, h, w),
          floor[posh][posw] +
              max_number_of_stones(floor, posh - 1, posw + 1, h, w))));

  itr = passwords.find(pair<int, int>(posh, posw));
  return itr->second;
}

int main() {
  int T, h, w;

  cin >> T;

  for (int i = 0; i < T; i++) {
    int ans = 0;

    cin >> h >> w;
    vector<vector<int> > floor(h, vector<int>(w));
    for (int j = 0; j < h; j++) {
      for (int z = 0; z < w; z++) {
        cin >> floor[j][z];
      }
    }

    for (int z = 0; z < w; z++)
      ans = maximum(ans, max_number_of_stones(floor, h - 1, z, h, w));

    cout << ans << endl;
    passwords.clear();
  }
}
