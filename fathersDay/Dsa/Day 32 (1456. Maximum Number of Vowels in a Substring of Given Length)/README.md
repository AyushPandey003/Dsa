# Maximum Number of Vowels in a Substring of Given Length

## Intuition

We need to find the maximum number of vowels in any substring of length `k`. A sliding window of size `k` is the perfect approach for this. We can maintain a count of vowels within the current window. As we slide the window one position to the right, we check the new character entering the window and the character leaving the window to update the vowel count efficiently.

## Pro-tip

Initialize the vowel count for the first window of size `k`. Then, iterate from `k` to the end of the string. In each step, update the count based on the new character and the character that's sliding out of the window. This avoids recounting vowels for the entire window every time.

## Trick

Use a `Set` or a boolean array for vowels to get O(1) lookup time when checking if a character is a vowel.

## Main Concept

This problem is a classic application of the **Sliding Window** algorithm. It's about maintaining a window of a fixed size and updating calculations efficiently as the window moves through the data.
