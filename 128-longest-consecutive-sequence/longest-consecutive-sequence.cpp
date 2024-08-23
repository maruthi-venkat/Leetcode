class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = true;
        }

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i] - 1) != mp.end()){
                mp[nums[i] - 1] = false;
            }
        }
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                int count = 0;
                int x = nums[i];
                while(mp.find(x) != mp.end()){
                    count++;
                    x--;
                }
                maxi = max(maxi,count);
            }
        }

        return maxi;
    }
};