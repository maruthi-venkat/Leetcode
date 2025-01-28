class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> visited(n,vector<bool> (m,0));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0 && visited[i][j] == 0){
                    q.push({grid[i][j],{i,j}});
                    visited[i][j] = 1;
                    int sum = 0;
                    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
                    while(!q.empty()){
                        auto [curr,cell] = q.front();
                        sum += curr;
                        int x = cell.first;
                        int y = cell.second;
                        q.pop();
                        for(auto d : dir){
                            int nx = d[0] + x;
                            int ny = d[1] + y;
                            if(nx >=0 && nx < n && ny>=0 && ny < m && grid[nx][ny] != 0 && visited[nx][ny] == 0){
                                visited[nx][ny] = 1;
                                q.push({grid[nx][ny],{nx,ny}});
                            }
                        }
                    }
                    maxi = max(maxi,sum);
                }
            }
        }

        return maxi;
    }
};