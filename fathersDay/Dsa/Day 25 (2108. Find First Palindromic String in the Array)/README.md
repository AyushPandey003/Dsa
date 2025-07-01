# Find First Palindromic String in the Array

## Intuition

The problem asks for the first string in a given array that is a palindrome. A palindrome is a word that reads the same forwards and backward. The most direct approach is to iterate through the array of strings from the beginning and, for each string, check if it is a palindrome. The very first one we find is our answer.

## Pro-tip

To check if a string is a palindrome, you can compare it with its reversed version. Most languages provide a simple way to reverse a string. For example, in Python, you can use slicing `word[::-1]`. This is often the most readable and concise way to perform the check.

## Trick

For a more manual check (which can be slightly more efficient as it avoids creating a new reversed string), you can use a **two-pointer** approach. Place one pointer at the beginning of the string and another at the end. Move the pointers towards each other, comparing the characters at each position. If you find a mismatch, it's not a palindrome. If the pointers meet or cross without any mismatches, the string is a palindrome.

## Main Concept

This is a straightforward **String Manipulation** and **Array Traversal** problem. It involves a simple linear scan of the input array and a standard palindrome-checking algorithm for each element.
