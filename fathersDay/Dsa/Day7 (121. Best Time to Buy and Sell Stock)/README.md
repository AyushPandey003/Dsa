# Day 7: Best Time to Buy and Sell Stock (LeetCode 121)

## Main Concept

The problem asks us to find the maximum profit that can be achieved by buying and selling a stock. We are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. We are allowed to complete at most one transaction (i.e., buy one and sell one share of the stock).

The core idea is to iterate through the `prices` array, keeping track of the minimum price encountered so far. For each day's price, we calculate the potential profit if we were to sell on that day (current price - `min_price`). We then update the `max_profit` if the current potential profit is greater.

## Intuition

The intuition behind this approach is that to maximize profit, we want to buy at the lowest possible price and sell at the highest possible price *after* the buying day. As we traverse the array, `min_price` always stores the lowest price encountered up to the current day. When we look at the `current_price`, the best we could have done if we bought at `min_price` and sold at `current_price` is `current_price - min_price`. We continuously update `max_profit` with the largest such difference found.

This greedy approach works because we only care about the largest difference between a future selling price and a past buying price. By always tracking the minimum buying price seen so far, we ensure that any profit calculation is based on the best possible buying opportunity up to that point.

## Pro Tip and Trick

*   **Single Pass Optimization:** This problem can be solved efficiently in a single pass through the `prices` array. There's no need for nested loops or complex data structures.

*   **Tracking `min_price`:** The key is to maintain a variable (e.g., `min_price`) that stores the lowest stock price encountered *so far* as you iterate through the days. Initialize `min_price` to a very large number (or the first element of the array).

*   **Calculating `max_profit`:** For each `price` in the array:
    1.  **Update `min_price`:** If `price` is less than the current `min_price`, update `min_price` to `price`. This means we found a new, better buying opportunity.
    2.  **Calculate Potential Profit:** Otherwise (if `price` is not less than `min_price`), calculate the potential profit if we sell on the current day: `current_price - min_price`. This difference represents the profit if we bought at the lowest point seen so far and sold today.
    3.  **Update `max_profit`:** Compare this potential profit with the `max_profit` found so far and update `max_profit` if the potential profit is greater.

*   **Initialization:** Initialize `max_profit` to 0, as it's possible to make no profit (or even a loss, but the problem asks for maximum profit, so 0 is the minimum non-negative profit).

*   **Edge Case (Empty Array):** Handle the case where the `prices` array is empty or `None`. In such a scenario, no transaction can be made, so the profit is 0.