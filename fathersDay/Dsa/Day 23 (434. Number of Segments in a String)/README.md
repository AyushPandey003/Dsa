# Number of Segments in a String

## Intuition

A "segment" is defined as a contiguous sequence of non-space characters. The problem is to count how many such segments exist in a string. The most intuitive way to think about this is to split the string by spaces and then count the number of non-empty parts.

## Pro-tip

Many programming languages provide a built-in `split` function that can automatically handle breaking a string by whitespace. Using this function is typically the simplest and most readable way to solve the problem. Just be mindful of how the function handles multiple spaces between words or leading/trailing spaces.

## Trick

An alternative to splitting is to iterate through the string and count the segments manually. A segment starts when you encounter a non-space character that is either at the beginning of the string or is preceded by a space. You can maintain a simple state or check `s[i] != ' ' && (i == 0 || s[i-1] == ' ')`.

## Main Concept

This is a basic **String Parsing** problem. It requires careful definition of what constitutes a word or segment and handling edge cases related to whitespace.
