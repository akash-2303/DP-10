// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
// Did the code run on Leetcode: Yes

// Approach:
// 1. We can use dynamic programming to solve this problem
// 2. We can create a dp array where dp[i][j] represents the maximum coins we can get by bursting all the balloons between index i and j
// 3. We can iterate through all the possible lengths of the subarray and for each length, we can iterate through all the possible starting indices
// 4. For each starting index, we can iterate through all the possible ending indices and for each ending index, we can iterate through all the possible last balloons to burst
// 5. We can calculate the maximum coins we can get by bursting the last balloon and adding the coins we can get from the left and right subarrays
// 6. We can return the maximum coins we can get by bursting all the balloons between index 0 and n - 1
// 7. NOTE: if we have 4, 2, 3, 7 and we burst 2, we can get 4 * 2 * 3 + 4 * 3 + 2 * 3 + 2 * 7 + 3 * 7 = 4 * 2 * 3 + dp[0][1] + dp[2][3] = dp[0][3]
// 8. We cannot get 4,3 as a result because we have already burst 2 and we cannot get 2,3 as a result because we have already burst 4

class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>>dp(n, vector<int>(n));
            for(int len = 1; len <= n; len++){
                for(int i = 0; i <= n - len; i++){
                    int j = i + len - 1;
                    for(int k = i; k <= j; k++){
                        int leftValue = 1; 
                        int rightValue = 1;
                        if(i != 0){
                            leftValue = nums[i - 1];
                        }
                        if(j != n - 1){
                            rightValue = nums[j + 1];
                        }
                        int before = 0; 
                        int after = 0;
                        if(i != k){
                            before = dp[i][k - 1];
                        }
                        if(j != k){
                            after = dp[k + 1][j];
                        }
                        dp[i][j] = max(leftValue * nums[k] * rightValue + before + after, dp[i][j]);
                    }
                }
            }
            return dp[0][n - 1];
        }
    };