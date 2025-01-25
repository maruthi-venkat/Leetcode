class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> temp;
        int n = nums.size();
        for(int i=0;i<n;i++) temp.push_back({nums[i],i});
        sort(temp.begin(),temp.end());
        
        vector<vector<pair<int,int>>> container;
        vector<pair<int,int>> row;
        container.push_back(row);
        container[container.size()-1].push_back(temp[0]);
        for(int i=1;i<n;i++){
            if(abs(temp[i].first - temp[i-1].first) <= limit){
                container[container.size()-1].push_back(temp[i]);
            }
            else{
                container.push_back(row);
                container[container.size()-1].push_back(temp[i]);
            }
        }
        vector<int> res(n,0);

        for(int i=0;i<container.size();i++){
            vector<int> arr;
            for(int j=0;j<container[i].size();j++){
                arr.push_back(container[i][j].second);
            }
            sort(arr.begin(),arr.end());
            for(int k=0;k<arr.size();k++){
                res[arr[k]] = container[i][k].first;
            }
        }

        return res;
    }
};