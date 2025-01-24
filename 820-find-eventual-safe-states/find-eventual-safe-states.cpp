class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverse_graph(n);
        for(int i=0;i<n;i++){
            vector<int> temp;
            reverse_graph.push_back(temp);
            for(int j=0;j<graph[i].size();j++){
                reverse_graph[graph[i][j]].push_back(i);
            }
        }

        vector<int> inorders(n,0);
        queue<int> q;
        vector<int> res;

        for(int i=0;i<n;i++){
            for(int j=0;j<reverse_graph[i].size();j++){
                inorders[reverse_graph[i][j]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(inorders[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i=0;i<reverse_graph[curr].size();i++){
                inorders[reverse_graph[curr][i]]--;
                if(inorders[reverse_graph[curr][i]] == 0){
                    q.push(reverse_graph[curr][i]);
                    res.push_back(reverse_graph[curr][i]);
                }
            }
        }
        sort(res.begin(),res.end());

        return res;
    }
};