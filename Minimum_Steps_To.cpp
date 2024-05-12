// Given an infinite number line. You start at 0 and can go either to the left or to the right. The condition is that in the ith move, you must take i steps. Given a destination d, find the minimum number of steps required to reach that destination.

// Example 1:

// Input: d = 2
// Output: 3
// Explaination: The steps takn are +1, -2 and +3.
// Example 2:

// Input: d = 10
// Output: 4
// Explaination: The steps are +1, +2, +3 and +4.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function minSteps() which takes the value d as input parameter and returns the minimum number of steps required to reach the destination d from 0.

// Expected Time Complexity: O(d)
// Expected Auxiliary Space: O(1) in cpp

#include <iostream>
#include <cmath> // for abs function

using namespace std;

int minSteps(int d) {
    int n = 0;
    int current_sum = 0;
    d = abs(d); 

    while (true) {
        n += 1;
        current_sum += n;
        if (current_sum == d) {
            return n;  
        }
        if (current_sum > d && (current_sum - d) % 2 == 0) {
            return n;  
        }
    }
}

int main() {
    int destination;
    cout << "Enter the destination on the number line: ";
    cin >> destination;  

    int steps = minSteps(destination);
    cout << "Minimum steps required to reach " << destination << ": " << steps << endl;

    return 0;
}
