class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        if(n <= 2 || m <= 2) return 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        vector<vector<bool>> visited(n,vector<bool> (m,false));

        for(int i=0;i<n;i++){
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][m-1],{i,m-1}});
            visited[i][0] = true;
            visited[i][m-1] = true;
        }

        for(int j=1;j<m-1;j++){
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[n-1][j],{n-1,j}});
            visited[0][j] = true;
            visited[n-1][j] = true;
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int water = 0;
        while(!pq.empty()){
            auto [h,cell] = pq.top();
            int x = cell.first,y = cell.second;
            pq.pop();
            for(auto d : dir){
                int nx = x + d.first, ny = y + d.second;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    water += max(0,h - heightMap[nx][ny]);
                    pq.push({max(h,heightMap[nx][ny]),{nx,ny}});
                }
            }

        }

        return water;

        
    }
};