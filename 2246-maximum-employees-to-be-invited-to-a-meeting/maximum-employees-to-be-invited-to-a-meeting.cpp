class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> inorders(n,0),chainlength(n,0),visited(n,0);
        for(int i=0;i<n;i++){
            inorders[favorite[i]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(inorders[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            chainlength[favorite[curr]] = chainlength[curr] + 1;
            inorders[favorite[curr]]--;
            if(inorders[favorite[curr]] == 0){
                q.push(favorite[curr]);
            }
        }

        int maxcycle = 0,totalchain=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int current = i,cyclelength=0;
                while(!visited[current]){
                    visited[current] = true;
                    cyclelength++;
                    current = favorite[current];
                }

                if(cyclelength == 2) totalchain += 2 + chainlength[i] + chainlength[favorite[i]];
                else maxcycle = max(maxcycle,cyclelength);
            }
        }

        return max(maxcycle,totalchain);
    }
};