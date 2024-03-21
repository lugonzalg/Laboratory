class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy_price = 2147483647;
        int sell_price = 0;
        int res = 0;
        
        for (size_t i = 0; i < prices.size(); i++) {
            
            if (prices[i] < buy_price) {
                buy_price = prices[i];
                sell_price = prices[i];
            }
            else if (prices[i] > sell_price) {
                if ((prices[i] - buy_price) > res)
                    res = prices[i] - buy_price;        
                sell_price = prices[i];
            }
        }
        return res;
    }
};
