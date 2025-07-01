# Reverse Vowels of a String

## Intuition

The problem asks us to reverse only the vowels within a string, while keeping the consonants in their original positions. This suggests a "two-pointer" approach. We can have one pointer starting from the beginning of the string and another from the end, moving towards each other.

## Pro-tip

1.  Initialize a `left` pointer to the start of the string and a `right` pointer to the end.
2.  Move the `left` pointer forward until it points to a vowel.
3.  Move the `right` pointer backward until it points to a vowel.
4.  Once both pointers are on vowels, swap the characters.
5.  Continue this process until the `left` and `right` pointers cross each other.

## Trick

To efficiently check if a character is a vowel, you can pre-populate a `Set` (or `HashSet` in Java, `unordered_set` in C++) with all vowel characters (both lowercase and uppercase). This provides a constant-time O(1) lookup, which is much faster than repeatedly checking against each vowel character individually.

## Main Concept

This problem is a great example of the **Two-Pointer** algorithm, a common technique for problems involving arrays or strings where you need to find pairs of elements or process the sequence from both ends simultaneously.
