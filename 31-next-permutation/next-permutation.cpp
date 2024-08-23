class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int point;
        int n = nums.size();
        int i;
        int maxi = INT_MIN;
        for(i=n-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                point = i;
                sort(nums.begin() + point,nums.end());
                for(int j=i;j<n;j++){
                    if(nums[j] > nums[i-1]){
                        swap(nums[j],nums[i-1]);
                        break;
                    }
                }
                break;
            }
        }

        if(i == 0){
            return sort(nums.begin(),nums.end());
        }
        
    }
};