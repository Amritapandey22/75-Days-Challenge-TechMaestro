class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pbuy=INT_MAX,profit=0;
         if (prices.size()==0)
             return 0;
        for(int i=0;i<prices.size();i++)
        {
            pbuy=min(pbuy,prices[i]);
            profit=max(profit,prices[i]-pbuy);
        }
         return profit;
    }
};