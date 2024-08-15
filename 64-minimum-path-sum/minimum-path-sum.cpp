class Solution {
public:
    long solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i<0 || j<0) return INT_MAX;

        if(i==0 && j==0) return grid[0][0];
        
        if(dp[i][j] != -1) return dp[i][j];
        long top = grid[i][j] + solve(i-1,j,grid,dp);
        long left = grid[i][j] + solve(i,j-1,grid,dp);

        long res = min(top,left);

        return dp[i][j] = res;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));

        return (int)solve(n-1,m-1,grid,dp);
    }
};