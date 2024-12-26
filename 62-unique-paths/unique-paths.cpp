class Solution {
public:
    // memoization
    // int solve(int row,int col,vector<vector<int>> &dp){
    //     if(row == 0 && col == 0){
    //         return 1;
    //     }

    //     if(dp[row][col] != -1) return dp[row][col];

    //     int left,top;

    //     if(col >= 1)
    //         left = solve(row,col-1,dp);
    //     else
    //         left = 0;

    //     if(row >= 1)
    //         top = solve(row-1,col,dp);
    //     else
    //         top = 0;

    //     return dp[row][col] = left + top;
    // }
    int uniquePaths(int m, int n) {
        if(n == 1 && m == 1) return 1;
        vector<vector<int>> dp(m, vector<int> (n,-1));
        // return solve(m-1,n-1,dp);

        // tabulation
        
        // dp[0][0] = 1;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i == 0 && j == 0) continue;
        //         int res = 0;
        //         if(i-1 >= 0){
        //             res += dp[i-1][j];
        //         }
        //         if(j-1 >= 0){
        //             res += dp[i][j-1];
        //         }
        //         dp[i][j] = res;
        //     }
        // }

        // return dp[m-1][n-1];

        // space optimized

        vector<int> up(n,0);
        vector<int> curr(n,-1);
        curr[0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                if(j==0) curr[j] = up[j];

                if(j > 0) curr[j] = up[j] + curr[j-1];
            }

            for(int k=0;k<n;k++){
                up[k] = curr[k];
            }
        }

        return up[n-1];
    }
};