import re

def isPalindrome(s):
    s = s.lower()
    s = re.sub(r'[^a-z0-9]', '', s)
    left = 0
    right = len(s) - 1

    while left < right:
        if s[left] != s[right]:
            return False
        
        left += 1
        right -= 1
        
    return True


import unittest

class TestIsPalindrome(unittest.TestCase):

    def test_palindromes(self):
        self.assertTrue(isPalindrome("A man, a plan, a canal: Panama"))
        self.assertTrue(isPalindrome("racecar"))
        self.assertTrue(isPalindrome("No lemon, no melon"))
        self.assertTrue(isPalindrome(" "))
        self.assertTrue(isPalindrome("a"))
        self.assertTrue(isPalindrome("121"))

    def test_non_palindromes(self):
        self.assertFalse(isPalindrome("hello"))
        self.assertFalse(isPalindrome("race a car"))
        self.assertFalse(isPalindrome("123abc321"))
        self.assertFalse(isPalindrome("Python"))

if __name__ == "__main__":
    unittest.main()