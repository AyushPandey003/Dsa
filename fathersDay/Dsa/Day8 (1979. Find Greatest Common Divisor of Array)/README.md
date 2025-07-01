# Day 8: Find Greatest Common Divisor of Array (LeetCode 1979)

## Main Concept

The problem asks us to find the greatest common divisor (GCD) of the smallest number and the largest number present in a given array of integers. The GCD of two integers is the largest positive integer that divides both numbers without leaving a remainder.

The solution involves three main steps:
1.  **Find the minimum element** in the input array.
2.  **Find the maximum element** in the input array.
3.  **Calculate the GCD** of these two found elements (minimum and maximum).

## Intuition

The problem simplifies the task of finding a GCD for an array by specifying that we only need to consider the two extreme values: the smallest and the largest. This means we don't need to calculate GCDs for all pairs or a sequence of numbers. Once these two values are identified, the problem reduces to a standard GCD calculation between two numbers.

The most common and efficient algorithm for finding the GCD of two numbers is the **Euclidean Algorithm**. Its intuition is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number. This process is repeated until one of the numbers becomes zero, and the other number is then the GCD.

## Pro Tip and Trick

*   **Efficient Min/Max Finding:** You can find both the minimum and maximum elements in the array in a single pass. Initialize `min_val` with a very large number and `max_val` with a very small number (or simply with the first element of the array), then iterate through the array, updating `min_val` and `max_val` as needed.

*   **Euclidean Algorithm Implementation:** The Euclidean algorithm is fundamental for GCD. Here's a common iterative implementation:
    ```python
    def gcd(a, b):
        while b:
            a, b = b, a % b
        return a
    ```
    ```cpp
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ```
    ```java
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ```

*   **Standard Library Functions:** Many programming languages provide built-in functions for GCD calculation, which are often optimized for performance:
    *   **Python:** `math.gcd(a, b)`
    *   **C++:** `std::gcd(a, b)` (available since C++17, requires `<numeric>` header)
    *   **Java:** For `int` types, you typically implement the Euclidean algorithm yourself or use a utility class. For `BigInteger`, there's a `BigInteger.gcd()` method.

    Using these built-in functions is generally preferred for conciseness and reliability unless the problem specifically requires implementing the algorithm from scratch.

*   **Edge Cases:** Consider edge cases like an array with only one element (min and max are the same, GCD is that element) or an array with negative numbers (though this problem usually deals with positive integers).