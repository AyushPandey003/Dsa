---

## 🔍 Anagram Validator — Python | Java | C++

### ✅ Problem Statement:

Determine whether two strings are **anagrams** of each other. An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all original letters exactly once.

---

### 💡 Core Logic (Used in all languages):

1. If the lengths of the two strings are not equal, they can't be anagrams.
2. Count the frequency of each character in the first string.
3. Decrease the count for each character found in the second string.
4. If any character count goes negative or doesn't exist, return `false`.
5. If all counts are 0, return `true`.

---

## 🐍 Python Solution

```python
def validAnagram(s1, s2):
    if len(s1) != len(s2):
        return False

    count = {}
    for char in s1:
        count[char] = count.get(char, 0) + 1

    for char in s2:
        if char not in count or count[char] == 0:
            return False
        count[char] -= 1

    return True

# Example
s1 = "anagram"
s2 = "nagaram"
print(validAnagram(s1, s2))  # Output: True
```

---

## ☕ Java Solution

```java
import java.util.HashMap;

public class AnagramCheck {
    public static boolean validAnagram(String s1, String s2) {
        if (s1.length() != s2.length()) return false;

        HashMap<Character, Integer> count = new HashMap<>();

        for (char c : s1.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        for (char c : s2.toCharArray()) {
            if (!count.containsKey(c) || count.get(c) == 0) {
                return false;
            }
            count.put(c, count.get(c) - 1);
        }

        return true;
    }

    public static void main(String[] args) {
        String s1 = "anagram", s2 = "nagaram";
        System.out.println(validAnagram(s1, s2));  // Output: true
    }
}
```

---

## 💻 C++ Solution

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

bool validAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> count;

    for (char c : s1) {
        count[c]++;
    }

    for (char c : s2) {
        if (count.find(c) == count.end() || count[c] == 0) {
            return false;
        }
        count[c]--;
    }

    return true;
}

int main() {
    string s1 = "anagram", s2 = "nagaram";
    cout << boolalpha << validAnagram(s1, s2) << endl;  // Output: true
    return 0;
}
```

---

## 📌 Time & Space Complexity

| Metric | Value                                                |
| ------ | ---------------------------------------------------- |
| Time   | `O(n)`                                               |
| Space  | `O(1)` (assuming limited charset like lowercase a-z) |

---

