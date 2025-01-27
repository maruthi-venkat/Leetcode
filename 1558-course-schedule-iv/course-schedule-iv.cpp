class Solution {
public:
    bool helper(vector<vector<int>> &graph,int start,int end,vector<vector<int>> &dp){
        if(dp[start][end] != -1){
            if(dp[start][end] == 0) return false;
            else return true;
        }

        for(int i=0;i<graph[start].size();i++){
            if(graph[start][i] == end){
                dp[graph[start][i]][end] = 1;
                return true;
            }
            else{
                if(helper(graph,graph[start][i],end,dp)){
                    dp[graph[start][i]][end] = 1;
                    return true;
                }
            }
        }

        dp[start][end] = 0;
        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses,vector<int> (0,0));
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<vector<int>> dp(numCourses,vector<int> (numCourses,-1));
        vector<bool> res;
        for(int i=0;i<queries.size();i++){
            res.push_back(helper(graph,queries[i][0],queries[i][1],dp));
        }

        return res;
    }
};