class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> arr(n+1,1);
        for(int i=0;i<banned.size();i++){
            if(banned[i] <= n)
                arr[banned[i]] = 0;
        } 
        int count = 0;
        int sum = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i] == 1){
                sum += i;
                count++;
            }

            if(sum > maxSum){
                sum -= i;
                count--;
                break;
            }
        }
        return count;
    }
};