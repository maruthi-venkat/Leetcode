class Solution {
public:
    int findlowerbound(int low,int high,vector<int> &nums,int target){
        int lbound = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                lbound = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }

        return lbound;
    }
    int findupperbound(int low, int high,vector<int> &nums,int target){
        int ubound = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ubound = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ubound;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lbound = findlowerbound(0,nums.size()-1,nums,target);
        if(lbound == -1) return {-1,-1};
        int ubound = findupperbound(0,nums.size()-1,nums,target);

        return {lbound,ubound};
    }
};