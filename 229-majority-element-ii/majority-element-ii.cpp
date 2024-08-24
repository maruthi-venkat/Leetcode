class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1=INT_MIN, candidate2=INT_MIN;
        int count1 = 0,count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(count1 == 0 && candidate2 != nums[i]){
                count1 = 1;
                candidate1 = nums[i];
            }
            else if(count2 == 0 && candidate1 != nums[i]){
                count2 = 1;
                candidate2 = nums[i];
            }
            else if(candidate1 == nums[i]){
                count1++;
            }
            else if(candidate2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == candidate1){
                count1++;
            }
            else if(nums[i] == candidate2){
                count2++;
            }
        }

        vector<int> res;
        if(count1 > nums.size()/3) res.push_back(candidate1);
        if(count2 > nums.size()/3) res.push_back(candidate2);

        return res;
    }
};