# Reverse Words in a String

## Intuition

The task is to reverse the order of words in a given string. A word is defined as a sequence of non-space characters. The core idea is to first break the string down into its individual words, then reverse the sequence of these words, and finally, combine them back into a single string, separated by single spaces.

## Pro-tip

Most programming languages offer built-in utilities that make this task straightforward. For instance, you can use a `split` function to separate the string into a list of words and a `join` function to merge them back after reversing the list. This is often cleaner and less error-prone than manual parsing.

## Trick

Pay close attention to edge cases like leading or trailing spaces in the input string, as well as multiple spaces between words. A good approach is to `trim` the input string first and then use a split method that handles multiple spaces (e.g., splitting by the regular expression `\s+`).

## Main Concept

This is a fundamental **String Manipulation** problem. It tests your ability to parse a string, handle its components (words), and reconstruct a new string based on a specific ordering requirement.
