class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int sum = 0;
        for(int i=0;i<n-1;i++){
            sum += nums[i];
            if(nums[i] >= nums[i+1]){
                maxi = max(sum,maxi);
                sum = 0;
            }
        }
        sum += nums[n-1];
        maxi = max(sum,maxi);

        return maxi;
    }
};