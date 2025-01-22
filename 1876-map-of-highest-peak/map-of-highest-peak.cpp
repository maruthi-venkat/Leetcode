class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> mat(n,vector<int> (m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        vector<vector<bool>> visited(n,vector<bool> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 0) mat[i][j] = -1;
                else{
                    mat[i][j] = 0;
                    pq.push({0,{i,j}});
                    visited[i][j] = 1;
                } 
            }
        }
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto [h,cell] = pq.top();
            pq.pop();
            for(auto d : dir){
                int nx = cell.first + d[0];
                int ny = cell.second + d[1];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    mat[nx][ny] = h + 1;
                    pq.push({mat[nx][ny],{nx,ny}});
                }
            }
        }

        return mat;

    }
};