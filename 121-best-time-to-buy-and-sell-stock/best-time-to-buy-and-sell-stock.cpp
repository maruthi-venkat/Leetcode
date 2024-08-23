class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minpro = prices[0];
        int maxi = INT_MIN;
        for(int i=0;i<prices.size();i++){
            minpro = min(minpro,prices[i]);
            maxi = max(maxi,prices[i]-minpro);
        }

        return maxi;
    }
};