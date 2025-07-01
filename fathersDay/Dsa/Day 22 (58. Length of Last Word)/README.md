# Length of Last Word

## Intuition

The problem asks us to find the length of the last word in a given string. A word is defined as a maximal substring consisting of non-space characters. The most straightforward approach is to first handle any trailing spaces, then find the last word, and finally calculate its length.

## Pro-tip

Many languages have built-in string manipulation functions that can simplify this. For example, you can `trim` the string to remove leading/trailing spaces, then `split` the string by spaces, and finally take the length of the last element in the resulting array.

## Trick

An efficient way to solve this without splitting the string is to iterate from the end of the string. First, skip any trailing spaces. Then, count the characters until you encounter a space or reach the beginning of the string. This count will be the length of the last word.

## Main Concept

This is a basic **String Manipulation** problem. It tests your ability to parse strings, handle whitespace, and extract specific substrings based on defined criteria.
