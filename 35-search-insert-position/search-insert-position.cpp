class Solution {
public:
    int res = -1;
    void binarysearch(int low, int high,vector<int>& nums,int target){
        if(low > high){
            return;
        }
        int mid = low + (high - low)/2;
        if(nums[mid] < target){
            res = max(res,mid);
            binarysearch(mid+1,high,nums,target);
        }
        else{
            binarysearch(low,mid-1,nums,target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        binarysearch(0,nums.size()-1,nums,target);
        return res+1;
    }
};