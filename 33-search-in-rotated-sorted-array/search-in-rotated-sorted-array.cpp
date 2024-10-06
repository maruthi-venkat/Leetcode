class Solution {
public:
    int res = -1;
    void binarysearch(int low,int high,vector<int>& nums,int target){
        if(low > high) return;

        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            res = mid;
            return;
        }

        if(nums[low] <= nums[mid]){
            if(target >= nums[low] && target <= nums[mid]){
                binarysearch(low,mid-1,nums,target);
            }
            else{
                binarysearch(mid+1,high,nums,target);
            }
        }
        else{
            if(target >= nums[mid] && target <= nums[high]){
                binarysearch(mid+1,high,nums,target);
            }
            else{
                binarysearch(low,mid-1,nums,target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) return nums[0] == target ? 0 : -1;
        binarysearch(0,nums.size()-1,nums,target);

        return res;
    }
};