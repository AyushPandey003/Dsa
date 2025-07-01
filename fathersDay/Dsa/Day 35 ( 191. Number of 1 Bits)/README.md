# Number of 1 Bits

## Intuition

The core idea is to check each bit of the number. We can do this by repeatedly checking the last bit and then right-shifting the number to process the next bit.

## Pro-tip

The `n & 1` operation is a fast way to check if the last bit is 1.

## Trick

The `n >>= 1` operation is an efficient way to right-shift the bits of a number, effectively dividing it by 2.

## Main Concept

This problem is about bit manipulation. Understanding bitwise operators like AND (`&`) and right shift (`>>`) is crucial.
