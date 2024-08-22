class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // creative solution of space = O(1)
        k = k%nums.size();
        int point = nums.size() - k - 1;
        reverse(nums.begin(),nums.begin()+point+1);
        reverse(nums.begin()+point+1,nums.end());
        reverse(nums.begin(),nums.end());
    }
};