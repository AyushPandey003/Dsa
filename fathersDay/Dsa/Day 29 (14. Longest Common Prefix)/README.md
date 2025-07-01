# Longest Common Prefix

## Intuition

The goal is to find the longest string that is a prefix of all strings in an array. A straightforward approach is to assume the first string is the longest common prefix and then iterate through the rest of the strings, comparing each with the current prefix. If a string doesn't start with the prefix, we shorten the prefix from the end by one character and check again. We continue this until we find a common prefix or the prefix becomes empty.

## Pro-tip

This method is often called **Horizontal Scanning**. Another effective approach is **Vertical Scanning**. In this method, you compare characters at the same index across all strings. You iterate from the first character (index 0) outwards. As soon as you find a character that doesn't match at the current index for any string, the common prefix is the substring up to the previous index.

## Trick

An elegant trick is to sort the array of strings first. The longest common prefix of all the strings must be a prefix of both the very first and the very last string in the sorted array. So, you only need to compare these two strings to find their common prefix, which will be the answer for the entire array.

## Main Concept

This is a classic **String Manipulation** problem. It involves careful character-by-character or prefix-by-prefix comparison to identify the shared starting sequence among a set of strings.
