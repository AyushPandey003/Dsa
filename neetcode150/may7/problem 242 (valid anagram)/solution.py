def validAnagram(s1,s2):
    if len(s1) != len(s2):
        return False
    count = {}
    for char in s1:
        count[char] = count.get(char, 0) + 1
        print(count)
    print("count after s1:", count)
    for char in s2:
        if char not in count or count[char] == 0:
            return False
        count[char] -= 1
        print(count)
    print("count after s2:", count)
    return True
s1 = "anagram"
s2 = "nagaram"
print(validAnagram(s1, s2))