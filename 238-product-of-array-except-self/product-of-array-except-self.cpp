class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixproduct(n);
        vector<int> suffixproduct(n);
        int prod = 1;
        for(int i=0;i<n;i++){
            prefixproduct[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for(int i=n-1;i>=0;i--){
            suffixproduct[i] = prod;
            prod *= nums[i];
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(prefixproduct[i]*suffixproduct[i]);
        }

        return res;
    }
};