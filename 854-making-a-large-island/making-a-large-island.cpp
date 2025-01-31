class Solution {
public:
    int findlarge(vector<vector<int>> &grid,int n,vector<vector<int>> &dp,vector<int> &counts,int &k,vector<vector<int>> &dir){
        vector<vector<bool>>visited(n,vector<bool> (n,0));
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    dp[i][j] = k;
                    int count = 0;
                    while(!q.empty()){
                        auto cell = q.front();
                        int x = cell.first;
                        int y = cell.second;
                        count++;
                        q.pop();
                        for(auto d : dir){
                            int nx = x + d[0];
                            int ny = y + d[1];
                            if(nx >= 0 && nx < n && ny >=0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]){
                                visited[nx][ny] = 1;
                                dp[nx][ny] = k;
                                q.push({nx,ny});
                            }
                        }
                    }
                    counts.push_back(count);
                    k++;
                    res = max(count, res);
                }
            }
        }

        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxi = 0;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        vector<int> counts;
        int k=0;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        maxi = max(maxi,findlarge(grid,n,dp,counts,k,dir));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    int sum = 1;
                    set<int> s;
                    for(auto d : dir){
                        int nx = i + d[0];
                        int ny = j + d[1];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n && dp[nx][ny] != -1){
                            s.insert(dp[nx][ny]);
                        }
                    }
                    for(auto p : s){
                        sum += counts[p];
                    }
                    maxi = max(maxi,sum);
                }
            }
        }

        return maxi;
    }
};