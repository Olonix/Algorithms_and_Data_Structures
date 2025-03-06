def reverse_array(arr):
    i = 0
    j = len(arr) - 1
    while i < j:
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1
    return arr


import unittest

class TestReverseArray(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(reverse_array([1, 2, 3, 4, 5]), [5, 4, 3, 2, 1])
        self.assertEqual(reverse_array([10, 20, 30]), [30, 20, 10])
    
    def test_empty(self):
        self.assertEqual(reverse_array([]), [])
    
    def test_single_element(self):
        self.assertEqual(reverse_array([42]), [42])
    
    def test_palindrome(self):
        self.assertEqual(reverse_array([1, 2, 3, 2, 1]), [1, 2, 3, 2, 1])

if __name__ == "__main__":
    unittest.main()