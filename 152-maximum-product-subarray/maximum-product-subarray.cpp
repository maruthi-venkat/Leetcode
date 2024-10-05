class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sufpro = 1;
        int prepro = 1;
        int res = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            if(sufpro == 0) sufpro = 1;
            if(prepro == 0) prepro = 1;

            prepro = prepro * nums[i];
            sufpro = sufpro * nums[nums.size()-1-i];

            res = max(prepro,res);
            res = max(res, sufpro);
        }

        return res;
    }
};