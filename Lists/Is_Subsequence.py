def isSubsequence(s, t):
    i = j = 0
    len_s = len(s)
    len_t = len(t)

    while j < len_t and i < len_s:
        if t[j] == s[i]:
            i += 1
        j += 1

    return i == len_s


import unittest

class TestIsSubsequence(unittest.TestCase):

    def test_subsequence(self):
        self.assertTrue(isSubsequence("abc", "ahbgdc"))
        self.assertTrue(isSubsequence("ace", "abcde"))
        self.assertTrue(isSubsequence("", "abc"))
        self.assertTrue(isSubsequence("", ""))
        self.assertTrue(isSubsequence("a", "a"))
        self.assertTrue(isSubsequence("b", "abc"))

    def test_not_subsequence(self):
        self.assertFalse(isSubsequence("axc", "ahbgdc"))
        self.assertFalse(isSubsequence("abc", "acb"))
        self.assertFalse(isSubsequence("abc", ""))
        self.assertFalse(isSubsequence("z", "abc"))

if __name__ == "__main__":
    unittest.main()