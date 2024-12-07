class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r = *max_element(nums.begin(),nums.end());
        int l = 1;
        int res = r;
        while(l <= r){
            int penality = l + (r - l)/2;
            int ops = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]%penality == 0){
                    ops += (nums[i]/penality) - 1;
                }
                else{
                    ops += nums[i]/penality;
                }
            }

            if(ops <= maxOperations){
                res = penality;
                r = penality - 1;
            }
            else{
                l = penality + 1;
            }
        }

        return res;
    }
};