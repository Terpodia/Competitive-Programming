#include <iostream>
#include <algorithm>
using namespace std;

class Solution 
{
    public:
        int longestCommonSubsequence(string text1, string text2) 
        {
            int n = (int)text1.size(), m = (int)text2.size();
            int dp[n+1][m+1];
            for(int i=0; i<=n; i++) for(int j=0; j<=m; j++) dp[i][j] = -1e9;
            for(int i=0; i<=m; i++) dp[0][i] = 0;
            for(int i=0; i<=n; i++) dp[i][0] = 0;

            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                    dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
                }
            }

            return dp[n][m];
        }
};

int main(void)
{
    string text1, text2;
    cin >> text1 >> text2;
    Solution sol;

    cout << sol.longestCommonSubsequence(text1, text2) << "\n";
    
    return 0;
}
