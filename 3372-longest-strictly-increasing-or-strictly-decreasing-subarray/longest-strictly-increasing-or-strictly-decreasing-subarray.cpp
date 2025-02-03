class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 0;
        int len = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                len++;
            }
            else{
                maxi = max(len,maxi);
                len = 1;
            }
        }
        maxi = max(maxi,len);
        len = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                len++;
            }
            else{
                maxi = max(len,maxi);
                len = 1;
            }
        }
        maxi = max(len,maxi);
        return maxi;
    }
};