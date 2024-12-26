class Solution {
public:
    int solve(int row,int col,vector<vector<int>> &dp){
        if(row == 0 && col == 0){
            return 1;
        }


        if(dp[row][col] != -1) return dp[row][col];

        int left,top;

        if(col >= 1)
            left = solve(row,col-1,dp);
        else
            left = 0;

        if(row >= 1)
            top = solve(row-1,col,dp);
        else
            top = 0;

        return dp[row][col] = left + top;
    }
    int uniquePaths(int m, int n) {
        if(n == 1 && m == 1) return 1;
        vector<vector<int>> dp(m, vector<int> (n,-1));

        return solve(m-1,n-1,dp);
    }
};