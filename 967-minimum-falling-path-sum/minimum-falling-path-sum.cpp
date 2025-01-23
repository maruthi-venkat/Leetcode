class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp,int n){
        if(i >= n) return 0;
        if(j < 0) return 10000;
        if(j >= n) return 10000;

        if(dp[i][j] != -1) return dp[i][j];

        int left = INT_MAX,right = INT_MAX,center = INT_MAX;
        left = matrix[i][j] + solve(i+1,j-1,matrix,dp,n);
        center = matrix[i][j] + solve(i+1,j,matrix,dp,n);
        right = matrix[i][j] + solve(i+1,j+1,matrix,dp,n);

        return dp[i][j] = min({left,center,right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));

        // int res = INT_MAX;
        // for(int i=0;i<n;i++){
        //     res = min(res,solve(0,i,matrix,dp,n));
        // }
        // return res;

        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == 0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==n-1){
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j-1],dp[i-1][j]});
                }
                else{
                    dp[i][j] = matrix[i][j] + min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
                }
            }
        }
        int res = INT_MAX;
        for(int j=0;j<n;j++){
            res = min(res,dp[n-1][j]);
        }

        return res;
    }
};
