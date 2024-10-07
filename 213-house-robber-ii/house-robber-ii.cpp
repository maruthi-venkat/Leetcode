class Solution {
public:
    int solve(vector<int>& nums,int index,int limit,vector<int>& dp){
        if(index < limit) return 0;
        if(dp[index] != -1) return dp[index];

        int with = solve(nums,index-2,limit,dp) + nums[index];
        int without = solve(nums,index-1,limit,dp);

        return dp[index] = max(with,without);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n,-1);
        int withlast = solve(nums,n-1,1,dp);
        vector<int> dp1(n,-1);
        int withfirst = solve(nums,n-2,0,dp1);

        return max(withlast,withfirst);
    }
};