# Find the Town Judge

## Intuition

The town judge is a person who trusts nobody and is trusted by everybody else (except for themselves). This translates to two conditions:
1. The judge's out-degree (the number of people they trust) is 0.
2. The judge's in-degree (the number of people who trust them) is `n-1`.

## Pro-tip

We can use two arrays to store the in-degree and out-degree of each person. A single array can also be used by incrementing the count for the person being trusted and decrementing for the person who trusts.

## Trick

A person `i` is the judge if and only if `trust_count[i] == 0` and `trusted_by[i] == n - 1`.

## Main Concept

This problem can be modeled as a graph problem. We are looking for a node with an in-degree of `n-1` and an out-degree of 0.
