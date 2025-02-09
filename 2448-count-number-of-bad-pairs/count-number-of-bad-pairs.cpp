class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0;
        long long n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i] - i) != mp.end()){
                res += mp[nums[i] - i];
                mp[nums[i] - i]++;
            }
            else{
                mp[nums[i] - i] = 1;
            }
        }
        return (long long) (((n*(n-1))/2) - res);
    }
};