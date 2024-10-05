class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int r = cols - 1;
        int u = 0;
        int d = rows - 1;

        vector<int> res;
        while(l<=r && u<=d){
            for(int i = l;i<=r;i++){
                res.push_back(matrix[u][i]);
            }
            u++;
            if(u > d){
                break;
            }

            for(int i = u;i<=d;i++){
                res.push_back(matrix[i][r]);
            }
            r--;
            if(l > r){
                break;
            }

            for(int i=r;i>=l;i--){
                res.push_back(matrix[d][i]);
            }
            d--;
            if(u > d){
                break;
            }

            for(int i=d;i>=u;i--){
                res.push_back(matrix[i][l]);
            }
            l++;
            if(l > r){
                break;
            }
        }

        return res;
    }
};