class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0, minPrice = 100001;
        for(int price : prices){
            if(price < minPrice) minPrice = price;
            int profit = price - minPrice;
            if (profit > maximumProfit) maximumProfit = profit;
        }
        return maximumProfit;
    }
};
