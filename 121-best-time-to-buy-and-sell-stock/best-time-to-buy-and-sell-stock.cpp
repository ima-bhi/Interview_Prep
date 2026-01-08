class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minm=prices[0],maxProfit=0;
        for(int i=1;i<n;i++){
            //step 1: find min
            minm=min(prices[i],minm);
            int profit= prices[i]-minm;
            maxProfit=max(profit,maxProfit);
        }
        return maxProfit;
    }
};