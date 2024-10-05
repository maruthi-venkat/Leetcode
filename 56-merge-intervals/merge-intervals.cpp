class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            vector<int> temp(2);
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
            int j = i+1;
            while(j<n){
                if(intervals[j][0] <= temp[1]){
                    temp[1] = max(temp[1],intervals[j][1]);
                }
                else if(intervals[j][0] > temp[1] || j == n){
                    temp[1] = max(temp[1],intervals[j-1][1]);
                    break;
                }
                j++;
            }
            i = j - 1;
            res.push_back(temp);
        }

        return res;
    }
};