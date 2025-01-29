class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size()+1);
        for(int i=1;i<edges.size()+1;i++){
            parent[i] = i;
        }
        for(int i=0;i<edges.size();i++){
            int r1 = find(edges[i][0]);
            int r2 = find(edges[i][1]);
            if(r1 != r2){
                parent[r2] = r1;
            }
            else{
                return edges[i];
            }
        }

        return {};
    }
    int find(int x){
        return parent[x] == x ? x : find(parent[x]);
    }
};