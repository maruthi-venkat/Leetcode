class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        vector<int> rows(n,0);
        vector<int> cols(m,0);
        for(int i=0;i<arr.size();i++){
            auto cell = mp[arr[i]];
            rows[cell.first]++;
            if(rows[cell.first] == m) return i;
            cols[cell.second]++;
            if(cols[cell.second] == n) return i;
        }

    
        return n*m;
    }
};