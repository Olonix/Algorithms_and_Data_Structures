def sort_binary_array(arr):
    i = 0
    j = len(arr) - 1
    while j > i:
        if arr[i] == 0:
            i += 1
        elif arr[j] == 1:
            j -= 1
        else:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    return arr


import unittest

class TestSortBinaryArray(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(sort_binary_array([1, 0, 1, 0, 1, 0]), [0, 0, 0, 1, 1, 1])
        self.assertEqual(sort_binary_array([1, 1, 0, 0, 1, 0]), [0, 0, 0, 1, 1, 1])
    
    def test_all_zeros(self):
        self.assertEqual(sort_binary_array([0, 0, 0, 0]), [0, 0, 0, 0])
    
    def test_all_ones(self):
        self.assertEqual(sort_binary_array([1, 1, 1, 1]), [1, 1, 1, 1])
    
    def test_empty(self):
        self.assertEqual(sort_binary_array([]), [])
    
    def test_single_element(self):
        self.assertEqual(sort_binary_array([0]), [0])
        self.assertEqual(sort_binary_array([1]), [1])

if __name__ == "__main__":
    unittest.main()