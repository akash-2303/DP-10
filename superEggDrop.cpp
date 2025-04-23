// Time Complexity: O(k * n)
// Space Complexity: O(k * n)
// Did the code run on Leetcode: Yes

//Approach: 
// 1. Instead of putting the table between eggs and floors, we should make it between attempts and eggs where you have maximum attempts as floors
// 2. Keep the rows as attempts and columns as eggs
// 3. dp[i][j] = 1 + BREAK(dp[i - 1][j - 1]) + NOT_BREAK(dp[i - 1][j]) and we stop once dp[i][j] reaches n or greater, in which case i is the answer
// 4. If that does not happen, we return n as the answer

class Solution {
    public:
        int superEggDrop(int k, int n) {
            vector<vector<int>>dp(n + 1, vector<int>(k + 1 , 0));
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= k; j++){
                    dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i - 1][j];
                    if(dp[i][j] >= n){
                        return i;
                    }
                }
            }
            return n;
        }
    };