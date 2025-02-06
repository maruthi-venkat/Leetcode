class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(nums[i] * nums[j]) != mp.end()){
                    mp[nums[i]*nums[j]]++;
                }
                else{
                    mp[nums[i]*nums[j]] = 1;
                }
            }
        }
        int res = 0;
        for(auto it : mp){
            int m = it.second;
            if(m > 1)
                res += (8*(m * (m-1))/2);
        }

        return res;
    }
};