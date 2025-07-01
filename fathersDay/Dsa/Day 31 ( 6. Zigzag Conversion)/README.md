# Zigzag Conversion

## Intuition

The problem asks us to convert a string into a zigzag pattern on a given number of rows. We can simulate the filling of this pattern by iterating through the string and appending each character to the appropriate row. We can keep track of the current row and the direction of movement (down or up).

## Pro-tip

Create an array of strings (or `StringBuilder`s in Java), where each string represents a row. Iterate through the input string, and for each character, append it to the string at the `current_row`. The `current_row` is updated based on the direction of movement.

## Trick

The direction of movement changes only when we are at the top row (row 0) or the bottom row (row `numRows - 1`). A boolean flag `going_down` can be used to keep track of the direction.

## Main Concept

This problem is about pattern simulation. The key is to find a systematic way to place the characters according to the zigzag pattern. Using an array of strings to represent the rows simplifies the logic.
