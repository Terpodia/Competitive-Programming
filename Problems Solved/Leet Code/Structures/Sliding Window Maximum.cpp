#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    multiset<int> w;

    for (int i = 0; i < k; i++) w.insert(nums[i]);

    int j = 0;

    auto itr = w.end();
    itr--;
    ans.push_back(*itr);

    for (int i = k; i < (int)nums.size(); i++) {
      w.erase(w.find(nums[j]));
      w.insert(nums[i]);
      itr = w.end();
      itr--;
      ans.push_back(*itr);

      j++;
    }

    return ans;
  }
};

int main() {
  Solution solve;

  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];

  vector<int> ans = solve.maxSlidingWindow(nums, k);
  for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
  cout << "\n";

  return 0;
}
