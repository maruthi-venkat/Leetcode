class Solution {
public:

    // long solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    //     if(i >= matrix.size()){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     long dleft = INT_MAX;
    //     long down = INT_MAX;
    //     long dright = INT_MAX;

    //     if(j==0){
    //         down = matrix[i][j] + solve(i+1,j,matrix,dp);
    //         dright = matrix[i][j] + solve(i+1,j+1,matrix,dp);
    //     }
    //     else if(j == matrix.size()-1){
    //         down = matrix[i][j] + solve(i+1,j,matrix,dp);
    //         dleft = matrix[i][j] + solve(i+1,j-1,matrix,dp);
    //     }
    //     else{
    //         down = matrix[i][j] + solve(i+1,j,matrix,dp);
    //         dleft = matrix[i][j] + solve(i+1,j-1,matrix,dp);
    //         dright = matrix[i][j] + solve(i+1,j+1,matrix,dp);
    //     }

    //     return dp[i][j] = min({down,dleft,dright});
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));

        // long mini = INT_MAX;
        // for(int j=0;j<matrix[0].size();j++){
        //    mini = min(mini,solve(0,j,matrix,dp));
        // }

        // return (int)mini;

        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j == n-1){
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j],dp[i-1][j-1]});
                }
                else{
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
                }
            }
        }

        int res = INT_MAX;
        for(int i=0;i<n;i++){
            res = min(res,dp[n-1][i]);
        }

        return res;
    }
};