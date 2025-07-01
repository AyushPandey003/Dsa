# Remove All Adjacent Duplicates In String

## Intuition

The problem requires us to repeatedly remove adjacent identical characters until no such pairs exist. This process is reminiscent of a Last-In, First-Out (LIFO) behavior, which strongly suggests using a stack. As we iterate through the string, we can use a stack to keep track of the characters for our result string.

## Pro-tip

Iterate through the input string one character at a time. For each character, look at the top of the stack.
- If the stack is not empty and its top character is the same as the current character, it means we've found an adjacent duplicate pair. So, we pop the stack.
- Otherwise, we push the current character onto the stack.

## Trick

After iterating through the entire string, the characters remaining in the stack, when read from bottom to top, form the final result string. In C++, a `std::string` can be used as a stack with `push_back` and `pop_back` for this problem, which simplifies building the final string.

## Main Concept

This is a classic application of the **Stack** data structure. It's used to process sequences and handle problems where the most recently added item is the first one to be considered for an operation.
