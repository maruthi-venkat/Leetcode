class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k] < 0){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k] == 0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else{
                    k--;
                }
            }
        }

        vector<vector<int>> res;
        for(auto it : s){
            res.push_back(it);
        }

        return res;
    }
};