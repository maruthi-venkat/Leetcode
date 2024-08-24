class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k = j+1;
                int l = n-1;
                while(k<l){
                    if((long long) nums[i]+nums[j]+nums[k]+nums[l] == target){
                        s.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if((long long) nums[i]+nums[j]+nums[k]+nums[l] < target){
                        k++;
                    }
                    else{
                        l--;
                    }
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