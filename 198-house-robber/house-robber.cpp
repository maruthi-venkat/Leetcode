class Solution {
public:
//memoization
    // int solve(int n,vector<int> nums,vector<int> &dp){
    //     if(n < 0) return 0;
    //     if(dp[n] != -1) return dp[n];

    //     int pick = nums[n] + solve(n-2,nums,dp);
    //     int nonpick = solve(n-1,nums,dp);

    //     return dp[n] = max(pick,nonpick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        // return solve(n-1,nums,dp);
        // tabulation
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int pick = INT_MIN;
        //     if(i > 1)
        //         pick = nums[i] + dp[i-2];
        //     else
        //         pick = nums[i];

        //     int nonpick = dp[i-1];

        //     dp[i] = max(pick,nonpick);
        // }

        // return dp[n-1];

        int prev1=nums[0];
        int prev2=INT_MIN;
        int curr = nums[0];
        for(int i=1;i<n;i++){
            int pick = INT_MIN;
            if(i > 1)
                pick = nums[i] + prev2;
            else
                pick = nums[i];

            int nonpick = prev1;

            curr = max(pick,nonpick);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};