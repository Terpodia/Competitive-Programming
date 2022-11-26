#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

unsigned long long combinationSum4(vector<int>& nums, int target) {
  unsigned long long dp[target + 1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;

  for (int i = 1; i <= target; i++) {
    for (int j = 0; j < (int)nums.size(); j++) {
      int x = i - nums[j];
      if (x < 0) continue;
      dp[i] += dp[x];
    }
  }
  return dp[target];
}

int main(void) {
  int n, target;
  scanf("%d%d", &n, &target);
  vector<int> nums(n);
  for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

  printf("%lld\n", combinationSum4(nums, target));

  return 0;
}
