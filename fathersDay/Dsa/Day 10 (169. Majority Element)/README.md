# Majority Element - LeetCode 169

## Main Concept: Boyer-Moore Voting Algorithm

The core idea behind the solution is the **Boyer-Moore Voting Algorithm**. This algorithm provides an elegant and highly efficient way to find the majority element in a sequence. The majority element is defined as the element that appears more than `n/2` times, where `n` is the size of the array.

The algorithm works by maintaining a `candidate` element and a `count`. It iterates through the array one element at a time.

1.  Initialize `candidate` to `null` and `count` to `0`.
2.  For each element in the array:
    *   If `count` is `0`, set the current element as the `candidate` and increment `count`.
    *   If the current element is the same as the `candidate`, increment `count`.
    *   If the current element is different from the `candidate`, decrement `count`.

At the end of the iteration, the `candidate` will be the majority element.

## Intuition

Think of it as a voting process. We are trying to find a candidate who has more than half the votes.

- We start with an arbitrary candidate from the array.
- As we iterate, we give a "vote" (`count++`) to our candidate if we see it again.
- If we see a different element, we take a vote away (`count--`). This is like pairing up one instance of our candidate with one instance of a different number and eliminating both.

Since the majority element appears more than `n/2` times, it outnumbers all other elements *combined*. Therefore, even after pairing it up with every other element, it will still have a positive vote count at the end. When the `count` drops to zero, it means the candidates up to that point have canceled each other out. We can then safely pick a new candidate from the current position and continue. The true majority element will always survive this process.

## Pro Tip & Trick

-   **Time and Space Efficiency:** The biggest advantage of this approach is its efficiency. It runs in **O(n) time complexity**, as it only requires a single pass through the array. It also uses **O(1) space complexity** because it only needs two variables (`candidate` and `count`), regardless of the input size.
-   **No Second Pass Needed (for this problem):** The LeetCode problem guarantees that a majority element always exists. Therefore, the candidate found by the algorithm is guaranteed to be the correct one. If this guarantee wasn't in place, a second pass would be required to count the occurrences of the final candidate to ensure it truly appears more than `n/2` times.
