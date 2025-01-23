class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>> &dp,int n){
        if(i >= n) return 0;
        if(j < 0) return 10000;
        if(j > i) return 10000;

        if(dp[i][j] != -1) return dp[i][j];

        int left = INT_MAX,right = INT_MAX;
        left = triangle[i][j] + solve(i+1,j,triangle,dp,n);
        right = triangle[i][j] + solve(i+1,j+1,triangle,dp,n);

        return dp[i][j] = min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(0,0,triangle,dp,n);
    }
};