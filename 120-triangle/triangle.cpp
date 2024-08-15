class Solution {
public:
    // Bottom Up approach

    // int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    //     if(i >= triangle.size()) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int down = triangle[i][j] + solve(i+1,j,triangle,dp);
    //     int dnext = triangle[i][j] + solve(i+1,j+1,triangle,dp);
        
    //     int res = min(down,dnext);

    //     return dp[i][j] = res;
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        int j=1;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int k=0;k<j;k++){
                temp.push_back(-1);
            }
            dp.push_back(temp);
            j++;
        }

        // return solve(0,0,triangle,dp);

        // space optimization
        dp[0][0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else if(j!=i){
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<dp[n-1].size();i++){
            mini = min(mini,dp[n-1][i]);
        }

        return mini;
    }
};