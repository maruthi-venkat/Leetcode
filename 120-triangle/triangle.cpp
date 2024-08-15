class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i >= triangle.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(i+1,j,triangle,dp);
        int dnext = triangle[i][j] + solve(i+1,j+1,triangle,dp);
        
        int res = min(down,dnext);

        return dp[i][j] = res;
    }
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
        
        return solve(0,0,triangle,dp);
    }
};