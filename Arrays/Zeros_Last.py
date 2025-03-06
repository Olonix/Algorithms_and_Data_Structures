def zeros_last(arr):
    i = 0
    len_arr = len(arr)
    for j in range(len_arr):
        if arr[j] > 0:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    return arr


import unittest

class TestZerosLast(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(zeros_last([3, 1, 0, 4, 7, 0]), [3, 1, 4, 7, 0, 0])
        self.assertEqual(zeros_last([1, 0, 3, 0, 5, 0]), [1, 3, 5, 0, 0, 0])
        self.assertEqual(zeros_last([0, 3, 1, 0]), [3, 1, 0, 0])
    
    def test_empty(self):
        self.assertEqual(zeros_last([]), [])
    
    def test_single_element(self):
        self.assertEqual(zeros_last([2]), [2])
        self.assertEqual(zeros_last([0]), [0])
    
    def test_only_positive_or_zero(self):
        self.assertEqual(zeros_last([2, 4, 6]), [2, 4, 6])
        self.assertEqual(zeros_last([0, 0, 0]), [0, 0, 0])

if __name__ == "__main__":
    unittest.main()
