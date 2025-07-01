# Number of Substrings Containing All Three Characters

## Intuition

The problem asks for the number of substrings that contain at least one 'a', one 'b', and one 'c'. A sliding window approach is a good fit for this type of problem. We can maintain a window and expand it to the right. Once the window contains all three characters, we know that any substring starting from the current `left` pointer and ending at or after the current `right` pointer will also contain all three characters.

## Pro-tip

The key insight is that once we have a valid window `s[left...right]`, every substring that starts at `left` and ends at `right` or later is also a valid substring. The number of such substrings is `s.length() - right`.

## Trick

Instead of a hash map, you can use an array of size 3 to store the counts of 'a', 'b', and 'c', which can be slightly more efficient.

## Main Concept

This problem is a classic example of the **Sliding Window** algorithm. This technique is useful for problems that involve finding a sub-array or substring that satisfies certain conditions.
