class Solution {
public:
    int sumofdigits(int n){
        int sum = 0;
        while(n != 0){
            sum += (n%10);
            n=n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            int sum = sumofdigits(nums[i]);
            mp[sum].push_back(nums[i]);
        }
        int res = -1;
        for(auto it : mp){
            auto arr = it.second;
            if(arr.size() < 2){
                continue;
            }
            else{
                int first_maxi = -1;
                int second_maxi = -1;
                int idx1 = -1;
                int idx2 = -1;
                for(int i=0;i<arr.size();i++){
                    if(arr[i]>first_maxi){
                        first_maxi = arr[i];
                        idx1 = i;
                    }
                }
                for(int i=0;i<arr.size();i++){
                    if(arr[i]>second_maxi && i != idx1){
                        second_maxi = arr[i];
                    }
                }
                res = max(res,first_maxi + second_maxi);
            }
        }

        return res;
    }
};