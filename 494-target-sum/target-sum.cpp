class Solution {
public:
    int count = 0;
    void solve(int index,char sign,int sum,vector<int> &nums,int target){
        if(index >= nums.size()){
            return;
        }

        if(sign == '+'){
            sum += nums[index];
        }
        if(sign == '-'){
            sum -= nums[index];
        }
        if(index == nums.size()-1 && sum == target){
            count++;
        }

        solve(index+1,'+',sum,nums,target);
        solve(index+1,'-',sum,nums,target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0,'+',0,nums,target);
        solve(0,'-',0,nums,target);

        return count;
    }
};