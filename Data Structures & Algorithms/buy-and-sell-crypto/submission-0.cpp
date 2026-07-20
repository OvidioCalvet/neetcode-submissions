class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxProfit = 0;
        for(int& sell : prices) {
            maxProfit = max(maxProfit, sell - buy);
            buy = min(buy, sell);
        }
        return maxProfit;
    }
};
