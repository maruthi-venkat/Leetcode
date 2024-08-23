class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presum;
        presum[0] = 1;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(presum.find(sum - k) != presum.end()){
                count = count + presum[sum - k];
            }

            if(presum.find(sum) != presum.end()){
                presum[sum]++;
            }
            else{
                presum[sum] = 1;
            }
        }

        return count;
    }
};