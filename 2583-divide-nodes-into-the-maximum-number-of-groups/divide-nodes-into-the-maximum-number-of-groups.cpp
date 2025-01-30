class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> graph;
        for(auto &edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> component(n+1,-1);
        vector<vector<int>> components;

        for(int i=1;i<=n;i++){
            if(component[i] == -1){
                queue<int> q;
                q.push(i);
                component[i] = components.size();
                components.push_back({i});

                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int neighbor : graph[node]){
                        if(component[neighbor] == -1){
                            component[neighbor] = component[i];
                            components.back().push_back(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        int totalGroups = 0;
        for(auto &comp : components) {
            unordered_map<int,int> color;
            queue<int> q;

            bool bipartite = true;
            for(int node : comp) {
                if(color.find(node) == color.end()){
                    q.push(node);
                    color[node] = 0;
                    while(!q.empty()){
                        int cur = q.front();
                        q.pop();
                        for(int neighbor : graph[cur]){
                            if(color.find(neighbor) == color.end()){
                                color[neighbor] = 1 - color[cur];
                                q.push(neighbor);
                            }else if(color[neighbor] == color[cur]){
                                return -1;
                            }
                        }
                    }
                }
            }
            int maxDepth = 0;
            for(int node : comp){
                maxDepth = max(maxDepth, bfsDepth(graph,node,n));
            }
            totalGroups += maxDepth;
        }
        return totalGroups;
    }

    int bfsDepth(unordered_map<int,vector<int>> &graph,int root,int n){
        vector<int> visited(n+1,0);
        queue<int> q;
        q.push(root);
        visited[root] = 1;
        int depth = 0;

        while(!q.empty()){
            int size = q.size();
            depth++;
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();
                for(int neighbor : graph[node]){
                    if(!visited[neighbor]){
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
        return depth;
    }
};
