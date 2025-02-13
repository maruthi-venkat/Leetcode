class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int count = 0;
        while(pq.size() >= 2 && pq.top() < k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push((long long)(x * 2 + y));
            count++;
        }

        return count;
    }
};