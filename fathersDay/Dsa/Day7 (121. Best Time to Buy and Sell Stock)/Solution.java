class Solution {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length == 0) {
            return 0;
        }
        
        int minPrice = prices[0]; // Initialize with the first price
        int maxProfit = 0;
        
        // Iterate from the second element
        for (int i = 1; i < prices.length; i++) {
            // Update minPrice if a lower price is found
            minPrice = Math.min(minPrice, prices[i]);
            
            // Calculate current profit and update maxProfit if it's higher
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
}