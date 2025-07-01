# Lexicographically Smallest Palindrome

## Intuition

To make a string a palindrome, we need to ensure that characters at symmetric positions (i.e., `s[i]` and `s[len - 1 - i]`) are the same. To achieve the lexicographically smallest palindrome, when `s[i]` and `s[len - 1 - i]` are different, we should change both to the smaller of the two characters. This ensures that we make the minimal changes necessary while prioritizing smaller characters, which leads to a lexicographically smaller result.

## Pro-tip

Use a two-pointer approach: one pointer (`left`) starting from the beginning and another (`right`) starting from the end. Move them towards the center. At each step, compare `s[left]` and `s[right]`. If they are different, replace both with the character that has a smaller ASCII value. If they are the same, do nothing.

## Trick

Converting the string to a mutable character array (or list of characters in Python) makes in-place modifications easier. After the loop, convert it back to a string.

## Main Concept

This problem combines **String Manipulation** with the **Two-Pointer** technique and the concept of **Lexicographical Order**. The key is to understand that to achieve the lexicographically smallest result, you should always favor smaller characters when making changes.
