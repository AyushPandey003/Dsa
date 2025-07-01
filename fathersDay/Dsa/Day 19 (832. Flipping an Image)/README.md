# Flipping an Image

## Intuition

The problem asks us to perform two operations on a binary matrix (image): first, flip each row horizontally, and then invert the image (change 0s to 1s and 1s to 0s). These operations can be combined for efficiency.

## Pro-tip

For each row, you can use a two-pointer approach to flip it horizontally. While doing so, you can also invert the values. When `left` and `right` pointers are on different elements, swap them and invert both. If `left` and `right` point to the same element (for odd-length rows), just invert that single element.

## Trick

The inversion `0 -> 1` and `1 -> 0` can be achieved simply by `1 - pixel_value`.

## Main Concept

This problem is a straightforward **Matrix Manipulation** task. It involves iterating through a 2D array and applying transformations to its elements. The two-pointer technique is useful for in-place reversal and modification.
