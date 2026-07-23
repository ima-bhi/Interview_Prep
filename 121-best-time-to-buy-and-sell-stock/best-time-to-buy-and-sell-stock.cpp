class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minm = prices[0], maxProfit = 0;
        for(int i=1;i<n;i++){
            //step 1: find minm,then maxProfit 
            minm=min(prices[i],minm);
            // step 2: find maxProfit
            maxProfit=max(prices[i]-minm,maxProfit);
        }
        return maxProfit;
    }
};