#include <vector>
#include <algorithm> // For std::min and std::max

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int min_price = prices[0]; // Initialize with the first price
        int max_profit = 0;
        
        // Iterate from the second element
        for (int i = 1; i < prices.size(); ++i) {
            // Update min_price if a lower price is found
            min_price = std::min(min_price, prices[i]);
            
            // Calculate current profit and update max_profit if it's higher
            max_profit = std::max(max_profit, prices[i] - min_price);
        }
        
        return max_profit;
    }
};