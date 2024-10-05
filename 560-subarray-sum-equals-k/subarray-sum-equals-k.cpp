class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0] = 1;
        int res = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()){
                res += mp[sum - k];
            }

            if(mp.find(sum) != mp.end()){
                mp[sum]++;
            }
            else{
                mp[sum] = 1;
            }
        }

        return res;
    }
};