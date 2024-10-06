class Solution {
public:
    int res = -1;
    void binarysearch(int low,int high,vector<int>& nums,int target){
        if(low > high){
            return;
        }

        int mid = low + (high - low)/2;
        // cout<<mid<<endl;
        if(target == nums[mid]){
            res = mid;
            return;
        }
        else if(target > nums[mid]){
            binarysearch(mid + 1,high,nums,target);
        }
        else{
            binarysearch(low,mid-1,nums,target);
        }
    }
    int search(vector<int>& nums, int target) {
        binarysearch(0,nums.size()-1,nums,target);
        return res;
    }
};