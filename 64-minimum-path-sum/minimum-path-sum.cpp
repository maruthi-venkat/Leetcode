class Solution {
public:
    // Top down approach

    // long solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    //     if(i<0 || j<0) return INT_MAX;

    //     if(i==0 && j==0) return grid[0][0];
        
    //     if(dp[i][j] != -1) return dp[i][j];
    //     long top = grid[i][j] + solve(i-1,j,grid,dp);
    //     long left = grid[i][j] + solve(i,j-1,grid,dp);

    //     long res = min(top,left);

    //     return dp[i][j] = res;
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> dp(n,vector<int> (m,-1));

        // return (int)solve(n-1,m-1,grid,dp);

        // Bottom Up approach

        // dp[0][0] = grid[0][0];

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(i == 0 && j == 0) continue;

        //         if(i>0 && j>0){
        //             dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
        //         }
        //         else{
        //             if(j > 0){
        //                 dp[i][j] = grid[i][j] + dp[i][j-1];
        //             }
        //             else if(i > 0){
        //                 dp[i][j] = grid[i][j] + dp[i-1][j];
        //             }
        //             else{
        //                 dp[i][j] = grid[i][j];
        //             }
        //         }
        //     }
        // }


        // return dp[n-1][m-1];

        vector<int> prev(m,-1);
        vector<int> curr(m,-1);

        curr[0] = grid[0][0];
        for(int row=0;row<n;row++){
            for(int i=0;i<m;i++){
                if(i == 0){
                    if(prev[i] == -1){
                        curr[i] = grid[row][i];
                    }
                    else{
                        curr[i] = grid[row][i] + prev[i];
                    }
                }
                else{
                    if(prev[i] == -1){
                        curr[i] = grid[row][i] + curr[i-1];
                    }
                    else{
                        curr[i] = grid[row][i] + min(curr[i-1],prev[i]);
                    }
                }
            }

            for(int i=0;i<m;i++){
                prev[i] = curr[i];
            }
        }
        
        return curr[m-1];
    }
};